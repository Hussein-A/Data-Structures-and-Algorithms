/*
Problem 1.2 in CTCI. Given two strings check if one is a permutation of the other.

Solution: hash each character keeping track of the count. For the first string +1 and during the second -1. 
At the end the count of each letter must be 0 count else they are not a permutation.
*/

#include<string>
#include<unordered_map>

bool is_perm(std::string& s, const std::string& t) {
	std::unordered_map<char, int> char_count;

	for (char ch : s)
		++char_count[ch];

	for (char ch : t)
		--char_count[ch];

	for (auto it = char_count.begin(); it != char_count.end(); ++it)
		if (it->second != 0) return false;

	return true;
}

int main() {
	std::string s = "HELLO WORLD!";
	std::string t = "DLROW OLLEH!";

	return is_perm(s, t);
}