#include "bot_algorithm.hpp"


// Surcharge, permet d'obtenir le noeud de priorité la plus grande
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
            closed_Nodes_Map[x][y]=0;
            open_Nodes_Map[x][y]=0;
        }
    }
    // On cree le noeud de départ, et on le pousse dans la liste des noeuds testés.
    n0 = new Node(xStart, yStart, 0, 0);
    n0->updatePriority(xFinish, yFinish);
    pq[pq_index].push(*n0);
    open_Nodes_Map[xStart][yStart]=n0->getPriority(); // on le marque dans la liste des noeuds testés.

    // Recherche d'après l'algorithme A* 
    delete n0;
    
    while(!pq[pq_index].empty()) // Si cette liste est vide, cela veut dire que l'on n'a pas pu trouver de chemin. On renverra alors une chaîne vide.
    {
        // obtenir le noeud dont la priorité est la plus haute dans la liste des noeuds non testés
        n0=new Node( pq[pq_index].top().getxPos(), pq[pq_index].top().getyPos(), 
                     pq[pq_index].top().getLevel(), pq[pq_index].top().getPriority());

        x=n0->getxPos(); y=n0->getyPos();

        pq[pq_index].pop(); // On supprime le noeud de la liste open
        open_Nodes_Map[x][y]=0;
        // On l'ajoute à la liste des noeuds testés.
        closed_Nodes_Map[x][y]=1;

        // On arrête de chercher lorsque nous sommes arrivé à la case d'arrivée.
        //c-a-d quand if((*n0).estimate(xFinish, yFinish) == 0)
        if(x==xFinish && y==yFinish) 
        {
            // On génère alors la chaîne de caractères correspondant au chemin en suivant les directions.
            string path="";
            while(!(x==xStart && y==yStart))
            {
                j = dir_Map[x][y];
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
            // Cas sortie de Map ou déjà dans la carte des noeuds déjà explorés, ou on ne peut pas marcher dessus
            if(!(xdx<0 || xdx>n-1 || ydy<0 || ydy>m-1 || Map[xdx][ydy]== 0 
                || closed_Nodes_Map[xdx][ydy]==1))
            {
                // on  crèe un noeud fils
                m0=new Node( xdx, ydy, n0->getLevel(), 
                             n0->getPriority());
                m0->nextLevel(i);
                m0->updatePriority(xFinish, yFinish);

                // S'il n'est pas dans la liste open, l'y ajouter
                if(open_Nodes_Map[xdx][ydy]==0)
                {
                    open_Nodes_Map[xdx][ydy]=m0->getPriority();
                    pq[pq_index].push(*m0);
                    delete m0;
                    // marquer la direction de son père
                    dir_Map[xdx][ydy]=(i+dir/2)%dir;
                }
                else if(open_Nodes_Map[xdx][ydy]>m0->getPriority())
                {
                    // acualiser les informations sur la priorité
                    open_Nodes_Map[xdx][ydy]=m0->getPriority();
                    // actualiser la direction de son père
                    dir_Map[xdx][ydy]=(i+dir/2)%dir;

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

  Image * image_linus = new Image();
  Sprite sprite_perso;
  RenderWindow * mainWindow_ = new RenderWindow(VideoMode(700, 700), "Bot manager");
  image_linus->LoadFromFile("fleche.png");
  sprite_perso.SetImage(*image_linus);
  Clock clock;
  
    // On initialise la Map
    for(int y=0;y<m;y++)
    {
        for(int x=0;x<n;x++) Map[x][y]=1;
    }

    // remplissage des obstacles
    for(int x=n/8;x<n*7/8;x++)
    {
        Map[x][m/2]=0;
    }
    for(int y=m/8;y<m*7/8;y++)
    {
        Map[n/2][y]=0;
    }
    Map[20][20]=0;
    Map[20][21]=0;
    Map[20][22]=0;
    Map[20][23]=0;
    Map[20][24]=0;
    Map[20][25]=0;
    
    Map[41][31]=0;
    Map[41][32]=0;
    Map[41][33]=0;
    Map[41][34]=0;
    Map[41][35]=0;
    Map[41][36]=0;
    Map[41][37]=0;
    Map[41][38]=0;
    
    
    int xA, yA, xB, yB;
    
    xA = 19;
    yA = 22;
    xB = 40;
    yB = 35;

    cout<<"Map Size (X,Y): "<<n<<","<<m<<endl;
    cout<<"Start: "<<xA<<","<<yA<<endl;
    cout<<"Finish: "<<xB<<","<<yB<<endl;
    // On calcule la route
    //clock_t start = clock();
    string route=pathFind(xA, yA, xB, yB);
    if(route=="") cout<<"An empty route generated!"<<endl;
    //clock_t end = clock();
    //double time_elapsed = double(end - start);
    //cout<<"Time to calculate the route (ms): "<<time_elapsed<<endl;
    cout<<"Route:"<<endl;
    cout<<route<<endl<<endl;

    // On suit la route 
    if(route.length()>0)
    {
        int j; char c;
        int x=xA;
        int y=yA;
        Map[x][y]=2;
        
        for(int i=0;i < (int)route.length();i++)
        {
        while (clock.GetElapsedTime() < 0.1)
        {
          
        }
        clock.Reset();
            c = route.at(i);
            j = atoi(&c); 
            cout << "c " << c << endl;
            cout << "j " << j << endl;
            cout << "dy[j] " << dy[j] << endl;
            cout << "dx[j] " << dx[j] << endl;
            x = x+dx[j];
            y = y+dy[j];
            cout<< "x : " << x << "y : " << y << endl;
            Map[x][y] = 3;
            sprite_perso.SetPosition(x*10,y*10);
            mainWindow_->Clear(Color::White);
            mainWindow_->Draw(sprite_perso);
            mainWindow_->Display();
        }
        Map[x][y] = 4;
    
        // afficher la carte
        for(int y=0;y<m;y++)
        {
            for(int x=0;x<n;x++)
                if(Map[x][y]==1)
                    cout<<".";
                else if(Map[x][y]==0)
                    cout<<"O"; //obstacle
                else if(Map[x][y]==2)
                    cout<<"D"; //Début
                else if(Map[x][y]==3)
                    cout<<"+"; //Chemin
                else if(Map[x][y]==4)
                    cout<<"A"; //Arrivée
            cout<<endl;
        }
    }
      
    return(0);
}

