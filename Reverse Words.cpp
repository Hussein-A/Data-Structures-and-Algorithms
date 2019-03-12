#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>

void reverse_string(std::string& s) {
	std::string reversed;
	std::string temp;
	std::istringstream ss{ s };
	while (!ss.eof()) {
		ss >> temp;
		reversed = temp + " " +  reversed;
		std::cout << reversed << "\n";
	}
	s = reversed;

}

int main() {
	std::string reversed = "hello darkness my old friend!";
	reverse_string(reversed);
	std::cout << reversed << "\n";
}