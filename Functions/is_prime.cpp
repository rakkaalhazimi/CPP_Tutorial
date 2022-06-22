#include<iostream>
#include<cmath>


bool is_prime(int value) {
    double root_value = std::sqrt(value);
    int trial_factor = 2, max_factor = static_cast<int>(root_value);

    for (int i = trial_factor; i <= max_factor; i++) {
        if (value % i == 0) {
            return false;
        }
    }

    return true;
}


int main(int argc, char const *argv[])
{
    int value;
    std::cout << "Enter number: ";
    std::cin >> value;

    bool result = is_prime(value);

    if (result) {
        std::cout << "The number " << value 
                  << " is a prime number" << std::endl;

    } else {
        std::cout << "The number " << value 
                  << " is 'not' a prime number" << std::endl;
    }

    return 0;
}
