#include "powersamurai.hpp"

int main(int argc, char *argv[])
{
  PowerSamurai *game = new PowerSamurai;

  game->run();

  delete game;
  
  return 0;
}
