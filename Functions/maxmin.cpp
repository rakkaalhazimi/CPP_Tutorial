#include<iostream>
#include<algorithm>

int main(int argc, char const *argv[])
{
    int score1 = 2;
    int score2 = 3;
    int max_ = std::max(score1, score2);

    std::cout << "The maximum between " << score1
              << " and " << score2
              << " is " << max_;

    return 0;
}
