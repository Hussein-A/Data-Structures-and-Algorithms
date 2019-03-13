#include<iostream>
#include<cmath> //for verification

int BS_sqrt(int n) {
	int low = 1, high = n / 2;
	int mid;
	while (low < high) {
		mid = low + (high - low) / 2;
		if (mid == n) return mid;
		else if (mid < n/mid){low = mid + 1;}
		else { high = mid - 1; }
	}
	if (low*low > n) {
		return low - 1;
	}
	else if ((low + 1)*(low + 1) <= n) {
		return low + 1;
	}
	else return low;
}

int main() {
	while (true) {
		std::cout << "please enter a positive integer value. \n";
		int n; std::cin >> n;
		std::cout << "Your sqrt is: " << BS_sqrt(n) << "\n";
		std::cout << "Actual integral, sqrt is: " << (int)sqrt(n) << "\n";
	}
}


