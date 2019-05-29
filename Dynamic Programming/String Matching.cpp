/*
Program to check the cost of converting one string into another, where the cost is identified as 1 for any 
substition, insertion or deletion of a letter. Based strongly upon the implementation as found in Skiena's Algorithm Design
Manual, 2ed. pg. 283. This was made strictly with the purpose of education.
*/

#include<string>
#include<vector>
#include<iostream>
#include<istream>

enum choice {
	match, ins, del
};

struct cell {
	int cost;
	choice parent;
};

inline int match_char(char s, char t) {
	if (s == t) return 0;
	else return 1;
}

int string_match(std::string s, std::string t) {
	//to hold cost of choosing one of the options
	std::vector<int> opt(3);

	//(0, 0 is reserved as empty space for both)
	s.std::string::insert(s.begin(), ' ');
	t.std::string::insert(t.begin(), ' ');

	//n+1 x m+1 matrix 
	const int row = s.size();
	const int clmn = t.size();
	
	std::vector<std::vector<cell>> matrix(row, std::vector<cell>(clmn));

	//init matrix
	for (int i = 0; i < clmn; ++i) matrix[0][i] = cell{i, choice::match};
	for (int j = 0; j < row; ++j) matrix[j][0] = cell{j, choice::match};

	for (int i = 1; i < row; ++i) {
		for (int j = 1; j < clmn; ++j) {
			opt[choice::match] = matrix[i - 1][j - 1].cost + match_char(s[i], t[j]);
			opt[choice::ins] = matrix[i][j - 1].cost + 1;
			opt[choice::del] = matrix[i - 1][j].cost + 1;

			matrix[i][j].cost = opt[choice::match];
			matrix[i][j].parent = choice::match;
			for (int k = choice::ins; k <= choice::del; ++k) {
				if (opt[k] < matrix[i][j].cost) {
					matrix[i][j].cost = opt[k];
					matrix[i][j].parent = (choice)k;
				}
			}
		}
	}
	return matrix[row - 1][clmn - 1].cost;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	while (true) {
		std::cout << "please enter two strings to find cost to match.\n";
		std::string s; std::getline(std::cin, s);
		std::string t; std::getline(std::cin, t);
		std::cout << string_match(s, t) << "\n";
	}
}