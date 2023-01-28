#include<iostream>
#include<algorithm>
#include<string>

int main() {
	std::string s = "a_b_c";
	std::string::difference_type n = std::count(s.begin(), s.end(), '_');

	std::cout << "Number of " 
			  << '_'
			  << " is "
			  << n
			  << std::endl;

	return 0;
}