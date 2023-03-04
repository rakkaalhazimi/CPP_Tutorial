#include<iostream>
#include<queue>


int main(int argc, char const *argv[]) {
    
    std::queue<int> numQueue;

    numQueue.push(0);
    std::cout << "First element:" << std::endl;
    std::cout << numQueue.front() << std::endl;

    numQueue.push(1);
    std::cout << "Second element:" << std::endl;
    std::cout << numQueue.back() << std::endl;

    numQueue.pop();
    std::cout << "First element after pop:" << std::endl;
    std::cout << numQueue.front() << std::endl;


    return 0;
}
