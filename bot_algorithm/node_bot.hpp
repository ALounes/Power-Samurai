#ifndef NODE_BOT_HPP
#define NODE_BOT_HPP

#include "stdafx.hpp"

using namespace std;

class Node
{
    // position courante
    int xPos;
    int yPos;
    
    int level;      // distance totale parcourue pour arriver au noeud
                    // priority = level+ distance restante estimée
    int priority;   // plus la valeur est petite, plus la priorité est grande

    public:
        Node(int xp, int yp, int d, int p) ;
    
        int getxPos() const ;
        int getyPos() const ;
        int getLevel() const ;
        int getPriority() const ;

        void updatePriority(const int & xDest, const int & yDest);


        void nextLevel(const int & i) ; 
        

        const int & estimate(const int & xDest, const int & yDest) const;
};

#endif
