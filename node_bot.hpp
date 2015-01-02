/*******************************************************************/
/*=================================================================*/
/************ -- PROJET : POWER SAMURAI 2D RPG -- ******************/
/*=================================================================*/
/*        [EI-SE4] Polytech Paris UPMC (2014-2015) (C++)           */
/*=================================================================*/
/*                       # Devloppeur #                            */
/*                       ==============                            */
/*                - lounes.achab@etu.upmc.fr                       */
/*               - maxime.martelli@etu.upmc.fr                     */
/*             - clement.maciejewski@etu.upmc.fr                   */
/*=================================================================*/
/*******************************************************************/

#ifndef NODE_BOT_HPP
#define NODE_BOT_HPP

#include "stdafx.hpp"

using namespace std;

class Node
{
    //Chaque noeud a des coordonnées (ce sont les cases du tableau), une distance pour arriver au noeud, et une priorité, correspondant à la somme de la distance déjà parcourue pour arriver au noeud, et à la distance restante estimée. Plus la valeur est petite, plus la priorité est grande (plus court chemin)

    public:
        Node(int xp, int yp, int d, int p) ;
    
        int getxPos() const ;
        int getyPos() const ;
        int getLevel() const ;
        int getPriority() const ;

        void updatePriority(const int & xDest, const int & yDest);
        
       

        void nextLevel(const int & i) ; 
        

        const int & estimate(const int & xDest, const int & yDest) const;
        
    private:
        // position courante
        int xPos;
        int yPos;
        int level;      // distance totale parcourue pour arriver au noeud
                       
        int priority;   //  priority = level + distance restante estimée. Plus la valeur est petite, plus la priorité est grande 
        
};

#endif
