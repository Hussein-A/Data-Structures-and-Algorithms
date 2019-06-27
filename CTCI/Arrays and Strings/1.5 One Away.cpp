/*
CTCI 1.5 Problem to solve: One Away: There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. 
Given two strings, write a function to check if they are one edit (or zero edits) away.

We consider the case of size difference of two strings at most 1 and we deal with difference 0 and 1 seperately.
*/
#include<string>
#include<iostream>


bool is_one_away(std::string& s, std::string& t) {
	const int ssize = s.size();
	const int tsize = t.size();
	if (ssize - tsize > 1 || ssize - tsize < -1) return false;

	if (ssize == tsize) {
		//case: only replacements
		bool replaced = false;
		for (int i = 0; i < ssize; ++i) {
			if (s[i] != t[i]) {
				if (replaced) //have we used our only replacement already?
					return false;
				else 
					replaced = true;
			}
		}
	}
	else {//s and t differ in size by 1
		std::string&min = ssize < tsize ? s : t;
		std::string& max = ssize > tsize ? s : t;

		bool deleted = false;
		int j = 0;
		for (int i = 0; i < min.size(); ++i) {
			if (min[i] != max[j]) {
				if (deleted) return false;
				else {
					deleted = true;
					++j;
				}
			}
			++j;
		}

	}
	return true;
}

int main() {
	std::string s = "HELLO";
	std::string t = "HEEELLO";

	if (is_one_away(s, t)) std::cout << "TRUE\n";
	else std::cout << "FALSE\n";
}