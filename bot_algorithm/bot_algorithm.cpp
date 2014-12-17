
// inspiré de http://www.policyalmanac.org/games/aStarTutorial.htm
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include "node_bot.hpp"

using namespace std;



const int n=60; // Taille horizontale de la carte 
const int m=60; // Taille verticale de la carte
static int map[n][m];

static int open_Nodes_map[n][m]; // Carte représentant les noeuds que l'on n'a pas encore testé
static int closed_Nodes_map[n][m]; // Carte représentant les noeuds que l'on a déjà testé
static int dir_map[n][m]; // Carte des directions
const int dir=8; // Nombre de directions possibles à partir d'une case
static int dx[dir]={1, 1, 0, -1, -1, -1, 0, 1};
static int dy[dir]={0, 1, 1, 1, 0, -1, -1, -1};
/*
5|6|7
-+-+-
4|X|0
-+-+-
3|2|1
*/

// Determine priority (in the priority queue)
bool operator<(const Node & a, const Node & b)
{
  return a.getPriority() > b.getPriority();
}

// Le plus court trajet est renvoyé sous la forme d'une chaîne de caractères
string pathFind( const int & xStart, const int & yStart, 
                 const int & xFinish, const int & yFinish )
{
    static priority_queue<Node> pq[2]; // liste des noeuds non testés
    static int pq_index; // index de la liste précédente
    static Node* n0;
    static Node* m0;
    static int i, j, x, y, xdx, ydy;
    static char c;
    
    pq_index=0;

    // réinitialise les cartes de noeuds
    for(y=0;y<m;y++)
    {
        for(x=0;x<n;x++)
        {
            closed_Nodes_map[x][y]=0;
            open_Nodes_map[x][y]=0;
        }
    }
    // On cree le noeud de départ, et on le pousse dans la liste des noeuds testés.
    n0 = new Node(xStart, yStart, 0, 0);
    n0->updatePriority(xFinish, yFinish);
    pq[pq_index].push(*n0);
    open_Nodes_map[xStart][yStart]=n0->getPriority(); // on le marque dans la liste des noeuds testés.

    // Recherche d'après l'algorithme A* 
    delete n0;
    while(!pq[pq_index].empty()) // Si cette liste est vide, cela veut dire que l'on n'a pas pu trouver de chemin. On renverra alors une chaîne vide.
    {
        // obtenir le noeud dont la priorité est la plus haute dans la liste des noeuds non testés
        n0=new Node( pq[pq_index].top().getxPos(), pq[pq_index].top().getyPos(), 
                     pq[pq_index].top().getLevel(), pq[pq_index].top().getPriority());

        x=n0->getxPos(); y=n0->getyPos();

        pq[pq_index].pop(); // On supprime le noeud de la liste open
        open_Nodes_map[x][y]=0;
        // On l'ajoute à la liste des noeuds testés.
        closed_Nodes_map[x][y]=1;

        // On arrête de chercher lorsque nous sommes arrivé à la case d'arrivée.
        //c-a-d quand if((*n0).estimate(xFinish, yFinish) == 0)
        if(x==xFinish && y==yFinish) 
        {
            // On génère alors la chaîne de caractères correspondant au chemin en suivant les directions.
            string path="";
            while(!(x==xStart && y==yStart))
            {
                j = dir_map[x][y];
                c = '0'+(j+dir/2)%dir;
                path = c+path;
                x += dx[j];
                y += dy[j];
            }


            delete n0;
            // On  supprime les noeuds restants
            while(!pq[pq_index].empty()) pq[pq_index].pop();           
            return path;
        }

        // On génère des noeuds dans toutes les directions différentes
        for(i=0;i<dir;i++)
        {
            xdx=x+dx[i]; ydy=y+dy[i];
            // Cas sortie de map ou déjà dans la carte des noeuds déjà explorés, ou on  ne peut pas marcher dessus
            if(!(xdx<0 || xdx>n-1 || ydy<0 || ydy>m-1 || map[xdx][ydy]==1 
                || closed_Nodes_map[xdx][ydy]==1))
            {
                // on  crèe un noeud fils
                m0=new Node( xdx, ydy, n0->getLevel(), 
                             n0->getPriority());
                m0->nextLevel(i);
                m0->updatePriority(xFinish, yFinish);

                // S'il n'est pas dans la liste open, l'y ajouter
                if(open_Nodes_map[xdx][ydy]==0)
                {
                    open_Nodes_map[xdx][ydy]=m0->getPriority();
                    pq[pq_index].push(*m0);
                    delete m0;
                    // marquer la direction de son père
                    dir_map[xdx][ydy]=(i+dir/2)%dir;
                }
                else if(open_Nodes_map[xdx][ydy]>m0->getPriority())
                {
                    // acualiser les informations sur la priorité
                    open_Nodes_map[xdx][ydy]=m0->getPriority();
                    // actualiser la direction de son père
                    dir_map[xdx][ydy]=(i+dir/2)%dir;

                    // remplacer le noeud en vidant un pq dans l'autre, sauf le noeud à remplacer qui sera ignoré et remplacé par le nouveau noeud
  
                    while(!(pq[pq_index].top().getxPos()==xdx && 
                           pq[pq_index].top().getyPos()==ydy))
                    {                
                        pq[1-pq_index].push(pq[pq_index].top());
                        pq[pq_index].pop();       
                    }
                    pq[pq_index].pop(); // on supprime le noeud en question
                    
                    // On vide le plus gros pq dans le plus petit
                    if(pq[pq_index].size()>pq[1-pq_index].size()) pq_index=1-pq_index;
                    while(!pq[pq_index].empty())
                    {                
                        pq[1-pq_index].push(pq[pq_index].top());
                        pq[pq_index].pop();       
                    }
                    pq_index=1-pq_index;
                    pq[pq_index].push(*m0); // on ajoute le noeud voulu
                    delete m0;
                }
                else delete m0; 
            }
        }
        delete n0; 
    }
    return ""; // pas de route trouvée
}

int main()
{
    // On initialise la map
    for(int y=0;y<m;y++)
    {
        for(int x=0;x<n;x++) map[x][y]=0;
    }

    // remplissage des obstacles
    for(int x=n/8;x<n*7/8;x++)
    {
        map[x][m/2]=1;
    }
    for(int y=m/8;y<m*7/8;y++)
    {
        map[n/2][y]=1;
    }
    map[20][20]=1;
    map[20][21]=1;
    map[20][22]=1;
    map[20][23]=1;
    map[20][24]=1;
    map[20][25]=1;
    
    map[41][31]=1;
    map[41][32]=1;
    map[41][33]=1;
    map[41][34]=1;
    map[41][35]=1;
    map[41][36]=1;
    map[41][37]=1;
    map[41][38]=1;
    
    
    int xA, yA, xB, yB;
    
    xA = 19;
    yA = 22;
    xB = 40;
    yB = 35;

    cout<<"Map Size (X,Y): "<<n<<","<<m<<endl;
    cout<<"Start: "<<xA<<","<<yA<<endl;
    cout<<"Finish: "<<xB<<","<<yB<<endl;
    // On calcule la route
    clock_t start = clock();
    string route=pathFind(xA, yA, xB, yB);
    if(route=="") cout<<"An empty route generated!"<<endl;
    clock_t end = clock();
    double time_elapsed = double(end - start);
    cout<<"Time to calculate the route (ms): "<<time_elapsed<<endl;
    cout<<"Route:"<<endl;
    cout<<route<<endl<<endl;

    // On suit la route 
    if(route.length()>0)
    {
        int j; char c;
        int x=xA;
        int y=yA;
        map[x][y]=2;
        for(int i=0;i< (int)route.length();i++)
        {
            c = route.at(i);
            j = atoi(&c); 
            x = x+dx[j];
            y = y+dy[j];
            map[x][y] = 3;
        }
        map[x][y] = 4;
    
        // afficher la carte
        for(int y=0;y<m;y++)
        {
            for(int x=0;x<n;x++)
                if(map[x][y]==0)
                    cout<<".";
                else if(map[x][y]==1)
                    cout<<"O"; //obstacle
                else if(map[x][y]==2)
                    cout<<"D"; //Début
                else if(map[x][y]==3)
                    cout<<"+"; //Chemin
                else if(map[x][y]==4)
                    cout<<"A"; //Arrivée
            cout<<endl;
        }
    }
      
    return(0);
}

