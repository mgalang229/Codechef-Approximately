#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 2;

vector<int> decimal_digits(N);

void Precompute() {
	long long denominator = 33102;
	// get the first remainder by dividing 103993 with 33102 (quotient = 4687)
	long long remainder = 4687;
	// calculate the next digits one by one up to 1e6-th position
	for (int i = 1; i <= 1e6; i++) {
		// like the elementary division, multiply the remainder by 10
		remainder *= 10;
		// get the needed digit by dividing the new remainder by the denominator
		decimal_digits[i] = remainder / denominator;
		// apply the changes by dividing the new remainder by the denominator and 
		// getting another remainder
		remainder %= denominator;
	}
}

int main() {
	ios::sync_with_stdio(false);
	// precompute the values after the decimal point
	Precompute();
	int tt;
	cin >> tt;
	while (tt--) {
		int k;
		cin >> k;
		if (k == 0) {
			cout << "3\n";
			continue;
		}
		cout << "3.";
		// print the digits up to the 'k'-th position
		for (int i = 1; i <= k; i++) {
			cout << decimal_digits[i];
		}
		cout << '\n';
	}
	return 0;
}
