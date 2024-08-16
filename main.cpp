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

  for (int i{}; i < 10; ++i) {
    Monster m{Monster::get_random_monster()};
    std::cout << m;
  }
  
  return 0;
}