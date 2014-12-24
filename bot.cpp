#include "bot.hpp"
#include "bot_algorithm.hpp"

bool operator<(const Node & a, const Node & b)
{
  return a.getPriority() > b.getPriority();
}

Bot::Bot(RenderWindow *win, Image& image, const Vector2i nbrOfAnim, String name,
			int life, int mana, enum power power, Map *myMap, float att_dmg, float att_delay, float bot_speed, int ident, int rangebot, int xp)
:Entity(win,image,nbrOfAnim,myMap)
,range_(rangebot)
,name_(name)
,life_(life)
,mana_(mana)
,power_(power)
,attack_damage_(att_dmg)
,attack_delay(att_delay)
,xp_(xp)
{
   setSpeed(bot_speed);
   setId(ident);
   play();
   timer = new Clock();
}

Bot::~Bot()
{
   delete timer;
}

void
Bot::move()
{
	/*if (player_->getPosition())*/
	
}

void
Bot::SetRange(int range)
{
	range_ = range;
}

int Bot::GetRange() const{
   return range_;
}
void Bot::SetSpeed(int speed) {
   speed_ = speed;
}

int Bot::GetSpeed()  const{
   return speed_;
}

void Bot::SetPlayer(Player * player){
   player_ = player;
}

Player * Bot::GetPlayer()  const{
   return player_;
}

string Bot::pathFind( const int & xStart, const int & yStart, 
                 const int & xFinish, const int & yFinish, Map * map_)
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
            if(!(xdx<0 || xdx>n-1 || ydy<0 || ydy>m-1 || map_->getVector()[ydy][xdx] != 1 || closed_Nodes_Map[xdx][ydy]==1))
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
                    open_Nodes_Map[xdx][ydy]= m0->getPriority();
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

void Bot::update_path(Map * map, Player * player) {
   //path = pathFind(soclePosition()[1], soclePosition()[3], player->soclePosition()[1], player->soclePosition()[3], map);
   path = pathFind(getCenter().x / getAnimationWidth(), getCenter().y / getAnimationWidth(), player->getCenter().x / getAnimationWidth(), player->getCenter().y / getAnimationWidth(), map);
   //cout << "position pour le bot du perso : (x,y) = " << player->soclePosition()[0]<<", " << player->soclePosition()[2] << endl;
}

string Bot::GetPath() const {
   return path;
}

void Bot::follow_path(Map * map, Player * player) {
   int j;
   char c;
   bool refresh = false;
   //attack_delay = 0.5;
   
   if (timer->GetElapsedTime() > getAttackDelay()) {
		refresh = true;
	}	
   	
   
   if (path == "")
   {
   // Attaque du personnage
      if (refresh)
      {
          player->lifePenalty(getAttackDamage());
          timer->Reset();
      }
     
   }
   else {
      c = path.at(0);
      //cout << "Direction bot : " << c << endl;
      j = atoi(&c);

      switch(j) 
      {
         //cout << "Premiere case du chemin : " << path.at(0);
         case 0 : {
         runMove();
            moveRight();
            break;
         }
         case 1 : {
            runMove();
            moveDownRight();
            break;
         }
         case 2 : {
            runMove();
            moveDown();
            break;
         }
         case 3 : {
            runMove();
            moveDownLeft();
            break;
         }
         case 4 : {
            runMove();
            moveLeft();
            break;
         }
         case 5 : {
            runMove();
            moveUpLeft();
            break;
         }
         case 6 : {
            runMove();
            moveUp();
            break;
         }
         case 7 : {
            runMove();
            moveUpRight();
            break;
         }
         default :
            break;
      }
   }
   //cout << "position du perso : (x,y) = " << player->soclePosition()[1]<<", " << player->soclePosition()[3] << endl;
   //cout << "Centre perso : (x,y) = " << player->getCenter()
   //cout << "position du bot: (x,y) = " << soclePosition()[1]<<", " << soclePosition()[3] << endl;
}


void 
Bot::update()
{
	if (isMoving())
	{
		updateSprite();
		animationRight();
		stopMove();
	}
}

void Bot::setRange(int x){
   range_ = x;
}
int Bot::getRange() {
   return range_;
}


void Bot::setDistance(int x){
   distance = x;
}
int Bot::getDistance() {
   return distance;
}

String 
Bot::getName() const
{
	return name_;
}

void 
Bot::setName(String name)
{
	name_ = name;
}

int 
Bot::getLife() const
{
	return life_;
}

int 
Bot::getMana() const
{
	return mana_;
}

void 
Bot::setLife(int life)
{
	life_ = life;
}

void 
Bot::setMana(int mana)
{
	mana_ = mana;
}

void 
Bot::lifePenalty(int penalty)
{
	life_ -= penalty;

	if(life_ < ZERO)
	{
		life_ = ZERO;
	}
}

void 
Bot::lifeGain(int gain)
{
 	life_ += gain;

	if(life_ > lifeMax_)
	{
		life_ = lifeMax_;
	}
}

void 
Bot::manaPenalty(int penalty)
{
	mana_ -= penalty;

	if(mana_ < ZERO)
	{
		mana_ = ZERO;
	}
}

void 
Bot::manaGain(int gain)
{
 	mana_ += gain;

	if(mana_ > manaMax_)
	{
		mana_ = manaMax_;
	}
}

bool 
Bot::isAlive() const
{
	return (life_ > ZERO);
}

bool 
Bot::haveMana() const
{
	return (mana_ > ZERO);
}


int  
Bot::getLifeMax() const
{
	return lifeMax_;
}

int  
Bot::getManaMax() const
{
	return manaMax_;
}

void  
Bot::setLifeMax(int life)
{
	lifeMax_ = life;
}

void  
Bot::setManaMax(int mana)
{
	manaMax_ = mana;
}


void 
Bot::bonusLifeMax(int life)
{
	lifeMax_ += life;
}

void 
Bot::bonusManaMax(int mana)
{
	manaMax_ += mana;
}

void Bot::setAttackDelay(float ad) {
   attack_delay = ad;
}

float Bot::getAttackDelay() {
   return attack_delay;
}

void Bot::setAttackDamage(float ad) {
   attack_damage_ = ad;
}

float Bot::getAttackDamage() {
   return attack_damage_;
}

void Bot::setXp(int xp) {
   xp_ = xp;
}
int Bot::getXp() const {
   return xp_;
}
