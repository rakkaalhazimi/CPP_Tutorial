#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>


bool compare(int left, int right)
{
    return left < right;
}

int main(int argc, char const *argv[])
{
    
    std::vector<int> unsorted = {10, 7, 8, 1};
    
    std::sort(unsorted.begin(), unsorted.end(), compare);
    
    for (int i = 0; i < unsorted.size(); i++)
    {
        std::cout << unsorted[i] << std::endl;
    }
    
    
    
    return 0;
}
