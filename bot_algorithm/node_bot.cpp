#include "node_bot.hpp"


Node::Node(int xp, int yp, int d, int p) {
  xPos=xp; 
  yPos=yp; 
  level=d; 
  priority=p;
}

int Node::getxPos() const {
  return xPos;
}

int Node::getyPos() const {
  return yPos;
}

int Node::getLevel() const {
  return level;
}

int Node::getPriority() const {
  return priority;
}

void Node::updatePriority(const int & xDest, const int & yDest)
{
     priority = level + estimate(xDest, yDest)*10; // Principe de l'algo A* (un déplacement = 10)
}

// On précise que nous préférons aller en ligne droite plutôt qu'en diagonale.
void Node::nextLevel(const int & i) // i: direction (impair = diagonale)
{
     level+= (i%2==0?10:14);
}

// Calcul de la distance restante estimée
const int & Node::estimate(const int & xDest, const int & yDest) const
{
    static int xd, yd, d;
    xd=xDest-xPos;
    yd=yDest-yPos;         

    // Definition de la distance. Dans notre cas, on considère qu'avancer en diagonale a le même coût qu'en ligne droite.
    d = static_cast<int>(!(xd<yd)?xd:yd);


    return d;
}

