#include<cmath>
#include<iostream>
#include<vector>

int main(int argc, char const *argv[])
{
    
    std::vector<int> array = {-1, 2, 3, -4, -5, 4};
    
    int sum = 0, best = 0;
    
    for (int k = 0; k < array.size(); k++)
    {
        sum = std::max(array[k], sum + array[k]);
        best = std::max(sum, best);
    }
    
    std::cout << "Maximum sum of subarray: " << best;
    
    /* code */
    return 0;
}
