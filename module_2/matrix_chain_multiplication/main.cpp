#include <iostream>
using namespace std;

int n;
int *matrix;
int **dp;

void get_input() {
	cin >> n;
	matrix = new int[n];
	
	for (int i = 0; i <= n; i++) {
		cin >> matrix[i];
	}

	dp = new int*[n];
	for (int i = 0; i < n; i++) {
		dp[i] = new int[n];
	}
}

int minimum(int a, int b) {
	return a>b?b:a;
}

void mcm() {
	for (int gap = 0; gap < n; gap++ ) {
			for (int i = 0, j = gap; j < n; j++, i++) {
				cerr << "Gap: " << gap <<" i: " << i << " j: " << j << "\n";
				if (gap == 0) {
					dp[i][j] = 0;
				} else if (gap == 1) {
					dp[i][j] = matrix[i]*matrix[j]*matrix[j+1];
				} else {
					int min_cost = INT_MAX;
					for (int k = i; k < j; k++) {
						int left_sum = dp[i][k];
						int right_sum = dp[k+1][j];
						int current = matrix[i]*matrix[k+1]*matrix[j+1];

						min_cost = minimum(min_cost, left_sum + right_sum + current);
					}
					dp[i][j] = min_cost;
				}
			}
	}
}

void print_dp() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cerr << dp[i][j] << " ";
		}
		cerr << "\n";
	}
}

int main() {
	cout << "Apurva Mishra 22BCE2791\n";
	get_input();
	print_dp();
	mcm();
	print_dp();
	cout << "Minimum multiplications required: " << dp[0][n-1] << endl;
}
