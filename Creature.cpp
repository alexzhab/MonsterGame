#include "Creature.h"

#include <iostream>
#include <string>
#include <map>

Creature::Creature(const std::string & name, char sym, int health, int damage, int gold) 
      : m_name{name}
      , m_sym{sym}
      , m_health{health}
      , m_damage{damage}
      , m_gold{gold} {
}

const std::string & Creature::get_name() const {
  return m_name;
}

char Creature::get_sym() const {
  return m_sym;
}

int Creature::get_health() const {
  return m_health;
}

int Creature::get_damage() const {
  return m_damage;
}

int Creature::get_gold() const {
  return m_gold;
}

void Creature::reduce_health(int amount) {
  m_health -= amount;
}

bool Creature::is_dead() const {
  return m_health <= 0;
}

void Creature::add_gold(int amount) {
  m_gold += amount;
}

std::ostream & Creature::print(std::ostream & os) const {
  os << "You have " << this->get_health() << " health and are carrying " << this->get_gold() << " gold." << std::endl;
  return os;
}

// ----------------------------------------------

Player::Player(const std::string & name) 
      : Creature{name, '@', 10, 1, 0} {
}

int Player::get_level() const {
  return m_level;
}

void Player::level_up() {
  ++m_level;
  ++m_damage;
}

bool Player::has_won() const {
  return m_level == 20;
}

// ----------------------------------------------

Monster::Monster(const MonsterType & mt) 
      : Creature{monsterData.at(mt)} {
}

std::ostream & Monster::print(std::ostream & os) const {
  os << "You have encountered a " << this->get_name() << "!" << std::endl;
  return os;
}