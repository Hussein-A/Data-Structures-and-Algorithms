/*
Program to implement Radix Sort
*/
#include<vector>
#include<iostream>
#include<math.h>
#include<random>
using namespace std;

#define DIGIT_SIZE 10

void printVector(const vector<int>& v) {
	for (int x : v)
		cout << x << " ";
	cout << "\n\n";
}

void random_vector(vector<int>& v) {
	random_device r;
	mt19937 rng(r());
	uniform_int_distribution<int> dist(-1000, 1000);

	for (int& x : v)
		x = dist(rng);
}

void countSort(vector<int>& v, int place) {
	vector<int> temp(DIGIT_SIZE);

	int digit;
	for (int num : v) {
		num /= pow(10, place - 1);
		digit = num % 10;
		++temp[digit];
	}


	for (int i = 1; i < temp.size(); ++i) {
		temp[i] += temp[i - 1];
	}

	for (int i = temp.size() - 1; i > 0; --i) {
		temp[i] = temp[i - 1];
	}
	temp[0] = 0;

	vector<int> newV(v.size());
	for (int i = 0; i < v.size(); ++i) {
		int val = v[i];
		digit = (val / (int)pow(10, place-1)) % 10;
		newV[temp[digit]++] = val;
	}

	v = newV;
}

void radixSort(vector<int>& v) {
	//get max
	int max = v[0];
	for (int i = 0; i < v.size(); ++i) {
		if (max < v[i]) max = v[i];
	}

	int digit = 1;
	while (max != 0) {
		countSort(v, digit);
		max /= 10;
		++digit;
		printVector(v);
	}


}

int main() {
	vector<int> temp{ 122,0,3,133,3,144,4,23,1,5,76,3,1,3,4,5,6,1 };
	radixSort(temp);
	printVector(temp);
}