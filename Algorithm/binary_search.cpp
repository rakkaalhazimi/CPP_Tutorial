#include<iostream>
#include<vector>

int main(int argc, char const *argv[])
{
    
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7};
    
    
    int k = 0;
    int x = 7;
    
    for (int b = array.size() / 2; b >= 1; b /= 2) 
    {
        std::cout << "Jump speed: " << b << std::endl;
        while (k + b < array.size() && array[k + b] <= x) 
        {
            k += b;
            std::cout << "Index: " << k << std::endl;
            
        }
    }
    if (array[k] == x) {
        std::cout << "Found: " << x << std::endl;
    }

    return 0;
}
