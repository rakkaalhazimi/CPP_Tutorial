#include<iostream>
#include<iomanip>
#include<string>


class Player {
    public: 
        std::string name;
        float hp, damage, defense, critChance, critDamage;

        Player(std::string name, int hp, int damage, int defense, float critChance, float critDamage) {
            this -> name = name;
            this -> hp = hp;
            this -> damage = damage;
            this -> defense = defense;
            this -> critChance = critChance;
            this -> critDamage = critDamage;
        }
    
        float attack(Player player) {
            float totalDamage = damage - player.defense;
            player.hp -= totalDamage;
            return totalDamage;
        }
};



int main() {
    Player player1("main player", 100., 5., 2., 10., 1.5);
    Player player2("opponent player", 100., 5., 2., 10., 1.5);

    std::cout << "Welcome to simple RPG in C++, made by: Rakka." << std::endl
              << "It is a turn based game where every player has a chance to take an action" << std::endl;

    char action;
    float damage;

    while (player1.hp > 0 && player2.hp > 0) {
        std::cout << "Select your action [a=attack, q=quit]: ";
        std::cin >> action;

        switch (action) {
            case 'a':
                // Declaring var inside switch will cause error
                damage = player1.attack(player2);
                std::cout << player1.name << " hit " << player2.name << " with " << damage << " damage." << std::endl;
                break;
            case 'q':
                std::exit(3);
                break;
            default:
                continue;
        }

        // Player2 attack
        damage = player2.attack(player1);
        std::cout << player1.name << " hit " << player2.name << " with " << damage << " damage." << std::endl;

        // HP status
        std::cout << player1.name << " hp: " << player1.hp << std::endl
                  << player2.name << " hp: " << player2.hp << std::endl;
    }
}
