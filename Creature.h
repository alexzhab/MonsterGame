#ifndef CREATURE_H
#define CREATURE_H

#include "Random.h"
#include <iostream>
#include <string>
#include <map>

class Creature {
protected:
  std::string m_name;
  char m_sym{};
  int m_health{};
  int m_damage{};
  int m_gold{};

public:
  Creature() = default;
  Creature(const std::string & name, char sym, int health, int damage, int gold);

  const std::string & get_name() const;
  char get_sym() const;
  int get_health() const;
  int get_damage() const;
  int get_gold() const;
  void reduce_health(int amount);
  bool is_dead() const;
  void add_gold(int amount);
  friend std::ostream & operator<<(std::ostream & os, const Creature & c) {
    return c.print(os);;
  }
  virtual std::ostream & print(std::ostream & os) const;
};

class Player : public Creature {
private:
  int m_level{1};

public:
  Player(const std::string & name);
  
  int get_level() const;
  void level_up();
  bool has_won() const;
};

class Monster : public Creature {
public:
  enum class MonsterType{
    Dragon,
    Orc,
    Slime
  };

private:
  static inline std::map<MonsterType, Creature> monsterData = {
      {MonsterType::Dragon, Creature {"dragon", 'd', 20, 4, 100}},
      {MonsterType::Orc, Creature {"orc", 'o', 4, 2, 25}},
      {MonsterType::Slime, Creature {"slime", 's', 1, 1, 10}}
    };

public:
  Monster(const MonsterType & mt);

  std::ostream & print(std::ostream & os) const override;

  static Monster get_random_monster() {
    return Monster(static_cast<MonsterType>(Random::get(0, monsterData.size() - 1)));
  }
};

#endif // CREATURE_H