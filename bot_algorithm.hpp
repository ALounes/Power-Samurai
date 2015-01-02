#ifndef BOT_ALGORITHM_HPP
#define BOT_ALGORITHM_HPP


// inspiré de http://www.policyalmanac.org/games/aStarTutorial.htm
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include "node_bot.hpp"



const int n = 55; // Taille horizontale de la carte 
const int m = 55; // Taille verticale de la carte


static int open_Nodes_Map[n][m]; // Carte représentant les noeuds que l'on n'a pas encore testé mais scanné
static int closed_Nodes_Map[n][m]; // Carte représentant les noeuds que l'on a déjà testé
static int dir_Map[n][m]; // Carte des directions
const int dir=8; // Nombre de directions possibles à partir d'une case
static int dx[dir]={1, 1, 0, -1, -1, -1, 0, 1}; // Caractérisation du déplacement
static int dy[dir]={0, 1, 1, 1, 0, -1, -1, -1};
// On commence le déplacement à zéro, correspondant à "Droite", puis on tourne dans le sens des aiguilles d'une montre

#endif
