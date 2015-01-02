#include "bot.hpp"
#include "bot_algorithm.hpp"


//Image effect_1;

/*!
*\file bot.hpp
*\brief Monstre (Bots)
*/


/*!
*\brief Surcharge de l'opérateur de comparaison afin de pouvoir comparer deux noeuds suivant la priorité
*/
bool operator<(const Node & a, const Node & b)
{
  return a.getPriority() > b.getPriority();
}

/*!
*\brief Constructeur
*
*Constructeur de la classe Bot
*
*\param win : fenêtre où sera affichée les Bots
*\param image : Référence de l'image du Bot.
*\param nbrOfAnim : Vecteur définissant le nombre d'animations en Hauteur et Largeur dans l'image. 
*\param name : Nom du Bot
*\param life : Vie du Bot
*\param mana : Mana du Bot
*\param myMap : Map de référence pour (entre autres) le calcul du plus court chemin
*\param att_dmg : Dégats du Monstre
*\param att_delay : Vitesse d'attaque
*\param bot_speed : Vitesse de déplacement
*\param ident : Numéro d'identification 
*\param rangebot : Rayon de détection du Bot
*\param xp : Xp donnée à la mort du Bot
*\param image1 : Image du premier sort
*\param image2 : Image du second sort
*\param image3 : Image du troisième sort
*/
Bot::Bot(RenderWindow *win, Image& image, const Vector2i nbrOfAnim, String name,
			int life, int mana, enum power power, Map *myMap, float att_dmg, float att_delay, float bot_speed, int ident, int rangebot, int xp, Image* image1, Image* image2, Image* image3)
:LivingEntity(win,image,nbrOfAnim,myMap)
,range_(rangebot)
,attack_delay(att_delay)
,xp_(xp)
{

   setName(name);
   setLife(life);
   setLifeMax(life);
   setMana(mana);
   setManaMax(mana);
   setAttackDamage(att_dmg);
   setSpeed(bot_speed);
   setId(ident);
   play();
   Timer_Refresh_ = new Clock();
}

Bot::~Bot()
{
   delete Timer_Refresh_;
}

void
Bot::move()
{

}

void
Bot::SetRange(int range)
{
	range_ = range;
}

int Bot::GetRange() const
{
   return range_;
}

void Bot::SetSpeed(int speed) 
{
   speed_ = speed;
}

int Bot::GetSpeed() const
{
   return speed_;
}

void Bot::SetPlayer(Player * player)
{
   player_ = player;
}

Player * Bot::GetPlayer() const
{
   return player_;
}


//Algorithme inspiré de A Star
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

void Bot::update_path(Map * map, Player * player) 
{
   path = pathFind(getCenter().x / 
			 			 getAnimationWidth(),
						 getCenter().y /
						 getAnimationWidth(),
						 player->getCenter().x /
						 getAnimationWidth(),
						 player->getCenter().y /
						 getAnimationWidth(),
						 map);
}

string Bot::GetPath() const 
{
   return path;
}

void Bot::follow_path(Map * map, Player * player) {
   int j;
   char c;
	      
	//Les monstres ont trois sorts. Chacun a un timer, un délai (le cooldown), une range, une quantité de dégats. Si le sort n'est plus en cooldown, et que le joueur est bien dans la range du sort, il se caste. On initialise et lance alors l'effet, que l'on place dans la liste des sorts, puis on met le sort en cooldown. 
   if ( getTimer(1)->GetElapsedTime() > getSpellDelay(1) && (int)path.size() <= getSRange(1) ) {
         player->lifePenalty(getDmg(1));
         player->setIsDamaged(true);
		      
		   FolowingAnimation *effect1 = new FolowingAnimation(win_, *getImgSpell(1), getVSpell(1), player);
		   
		   
		   effect1->setSoundB("Musique/Bite.ogg");
         effect1->getSound()->SetLoop(false);
	      effect1->getSound()->Play();
         effect1->play();
         spells.push_front(effect1);
         getTimer(1)->Reset();
   }
   if ( getTimer(2)->GetElapsedTime() > getSpellDelay(2) && (int) path.size() <= getSRange(2) ) {
         player->lifePenalty(getDmg(2));
         player->setIsDamaged(true);
		      
		   FolowingAnimation *effect2 = new FolowingAnimation(win_, *getImgSpell(2), getVSpell(2), player);
		   effect2->setSoundB("Musique/Ice10.ogg");
         effect2->getSound()->SetLoop(false);
	      effect2->getSound()->Play();
		   
         effect2->play();
         spells.push_front(effect2);
         getTimer(2)->Reset();
   }
   
   if ( getTimer(3)->GetElapsedTime() >  getSpellDelay(3) && ( (int) path.size() <= getSRange(3)) ) {
         player->lifePenalty(getDmg(3));
         player->setIsDamaged(true);
          
		      
		   FolowingAnimation *effect3 = new FolowingAnimation(win_, *getImgSpell(3), getVSpell(3), player);
		   effect3->setSoundB("Musique/Fire9.ogg");
         effect3->getSound()->SetLoop(false);
	      effect3->getSound()->Play();
         effect3->play();
         spells.push_front(effect3);
         getTimer(3)->Reset();
   }
	      
	//Puis, on suit le chemin donné par l'algorithme A*. L'ayant sous la forme d'une chaîne de caractères, on lit celle la, et on déplace le bot suivant le résultat.      
	      
   if (path == "")
   {
   
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

void Bot::setRange(int x)
{
   range_ = x;
}

int Bot::getRange() 
{
   return range_;
}


void Bot::setDistance(int x)
{
   distance = x;
}

int Bot::getDistance() 
{
   return distance;
}

void Bot::setAttackDelay(float ad) 
{
   attack_delay = ad;
}

float Bot::getAttackDelay() 
{
   return attack_delay;
}

void Bot::setXp(int xp) 
{
   xp_ = xp;
}

int Bot::getXp() const 
{
   return xp_;
}

void Bot::inPursuit() 
{
   in_pursuit = true;
}

bool Bot::getPursuit() 
{
   return in_pursuit;
}

void Bot::drawRect() {
   if (getLife() == getLifeMax())
   {
      // Dans un soucis d'esthétique, quand le monstre a toute sa vie, on n'affiche pas sa barre de vie.
   }
   else {
      //Sinon, on affiche la barre de vie.
      Rect =  Shape::Rectangle(0, 0, 30 *((float) getLife() /(float) getLifeMax()), 3, Color::Red);
      Rect.SetPosition(getCenter().x - 15, getCenter().y - 22);
      win_->Draw(Rect);
   }
}

Clock* Bot::getRefresh() const {
   return Timer_Refresh_;
}
