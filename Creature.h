#ifndef CREATURE_H
#define CREATURE_H

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
  Creature(const std::string & name, char sym, int health, int damage, int gold) 
        : m_name{name}
        , m_sym({sym}
        , m_health{health}
        , m_damage{damage}
        , m_gold{gold} {
  }

  const std::string & get_name() const {
    return m_name;
  }

  char get_char() const {
    return m_sym;
  }

  int get_health() const {
    return m_health;
  }

  int get_damage() const {
    return m_damage;
  }

  int get_gold() const {
    return m_gold;
  }

  void reduce_health(int amount) {
    m_health -= amount;
  }

  bool is_dead() const {
    return m_health <= 0;
  }

  void add_gold(int amount) {
    m_gold += amount;
  }

  friend std::ostream & operator<<(std::ostream & os, const Creature & c) {
    os << "You have " << c.get_health() << " health and are carrying " << c.get_gold() << " gold." << std::endl;
    return os;
  }
};

class Player : public Creature {
private:
  int m_level{1};

public:
  Player(const std::string & name) 
        : Creature{name, '@', 10, 1, 0} {
  }

  int get_level() const {
    return m_level;
  }

  void level_up() {
    ++m_level;
    ++m_damage;
  }

  bool has_won() const {
    return m_level == 20;
  }
};

class Monster : public Creature {
public:
  enum class MonsterType{
    Dragon,
    Orc,
    Slime,
    MaxTypes
  };

private:
    inline static std::map<MonsterType, Creature> monsterData[] {
      Creature {"dragon", 'D', 20, 4, 100},
      Creature {"orc", 'o', 4, 2, 25},
      Creature {"slime", 's', 1, 1, 10}
    };

    static_assert(std::size(monsterData) == max_types);

public:
    Monster(const MonsterType & mt) : Creature{monsterData[mt]} {
    }
};

#endif // CREATURE_H