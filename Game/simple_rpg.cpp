#include<algorithm>
#include<ctime>
#include<iostream>
#include<iomanip>
#include<random>
#include<string>

// RnG
std::default_random_engine generator(std::time(0));
std::uniform_real_distribution<double> distribution(0.0,1.0);

// Constant
float minDamage = 0.5;


class Player {
    public: 
        std::string name;
        int damage, defense;
        float hp, critChance, critDamage;

        Player(
            std::string name, 
            float hp, 
            int damage, 
            int defense, 
            float critChance, 
            float critDamage
        ) {
            this -> name = name;
            this -> hp = hp;
            this -> damage = damage;
            this -> defense = defense;
            this -> critChance = critChance;
            this -> critDamage = critDamage;
        }

        float getCriticalDamage(int damage) {
            double num = distribution(generator);
            if (Player::critChance <= num) {
                return damage * Player::critDamage;
            }
            return damage;
        }
    
        float attack(Player& opponent) {
            int damage = std::rand() % Player::damage + 1;                          // damage ranges from (1, player_damage)
            float critDamage = getCriticalDamage(damage);                           // calculate crit damage
            float totalDamage = std::max(minDamage, critDamage - opponent.defense); // deal minimal damage if defense exceed damage
            opponent.hp -= totalDamage;
            return totalDamage;
        }
};

void attackAction(Player& subject, Player& target) {
    float damage = subject.attack(target);
    std::cout << subject.name << " hit " << target.name << " with " << damage << " damage." << std::endl;
}


int main() {
    
    std::srand(time(0));

    Player player1(
        "main player",      // name
        100.,               // hp
        5,                  // damage
        2,                  // defense
        0.1,                // crit chance
        1.5                 // crit damage
    );

    Player player2(
        "opponent player",  // name
        100.,               // hp
        5,                  // damage
        2,                  // defense
        0.1,                // crit chance
        1.5                 // crit damage
    );

    std::cout << "Welcome to simple RPG in C++, made by: Rakka." << std::endl
              << "It is a turn based game where every player has a chance to take an action" << std::endl;

    char action;
    float damage;

    while (player1.hp > 0 && player2.hp > 0) {
         // HP status
        std::cout << player1.name << " hp: " << player1.hp << std::endl
                  << player2.name << " hp: " << player2.hp << std::endl;

        std::cout << "Select your action [a=attack, q=quit]: ";
        std::cin >> action;

        switch (action) {
            case 'a':
                // Declaring var inside switch will cause error
                attackAction(player1, player2);
                break;
            case 'q':
                std::exit(3);
                break;
            default:
                continue;
        }

        // Player2 attack
        attackAction(player2, player1);
        std::cout << std::endl;
    }
}
