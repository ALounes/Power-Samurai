#include "main.hpp"

int main(int argc, char *argv[])
{
  Game * jeu = new Game;
 
  jeu->Map_Load();
  jeu->Start();
  
  delete jeu;
  
  return 0;
}
