#include "Creature.h"
#include <iostream>
#include <string>

int main()
{
  std::cout << "Enter your name: ";
  std::string player_name;
  getline(std::cin, player_name);
  
  Player p{player_name};
  std::cout << "Welcome, " << p.get_name() << "." << std::endl;
  std::cout << p;
  
  return 0;
}