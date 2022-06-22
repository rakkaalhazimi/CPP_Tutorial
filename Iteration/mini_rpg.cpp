#include<iostream>
#include<algorithm>
#include<ctime>


// rand() will generate random number between 0 - RAND_MAX
// srand() establishes the first value in the sequence of pseudorandom integer values
// time(0) returns the number of seconds from January 1970 until now


int attack()
{
    // attack returns random number
    return (rand() % 3) + 1;
}



int main(int argc, char const *argv[])
{   
    // Seed random seed value
    unsigned seed = static_cast<unsigned>(std::time(0));
    srand(seed);

    // Players health
    int myHealth, enemyHealth;
    myHealth = enemyHealth = 100;

    while (myHealth > 0 && enemyHealth > 0) {

        // Players attack
        int myAttack = attack();
        int enemyAttack = attack();

        // Players got damage
        myHealth = std::max(myHealth - enemyAttack, 0);
        enemyHealth = std::max(enemyHealth - myAttack, 0);

        // Show battle status
        std::cout << "I got " << enemyAttack << " damage. "
                  << "My HP is " << myHealth << std::endl;

        std::cout << "Enemy got " << myAttack << " damage. "
                  << "Enemy's HP is " << enemyHealth << std::endl;

        std::cout << std::endl;

    }

    // Show battle result
    if (myHealth > enemyHealth)
    {
        std::cout << "I win with " << myHealth << " HP left.";
    }
    else
    {
        std::cout << "Enemy win with " << enemyHealth << " HP left.";
    }


    return 0;
}
