#include <iostream>
#include <numeric>
using namespace std;

struct item {
	float value;
	int weight;

	item(float v, int w) {
		value = v;
		weight = w;
	}
	item() {};
};

item *items;
int num;
int target;

float **dp;

void get_input() {
	cin >> num >> target;

	items = new item[num];
	for (int i = 0; i < num; i++) {
		item tmp;
		cin >> tmp.value >> tmp.weight;
		items[i] = tmp;
	}

	dp = new float*[num+1];
	for (int i = 0; i <= target; i++) {
		dp[i] = new float[target+1];
	}
	for (int i = 0; i <= num; i++) {
		for (int j = 0; j <= target; j++) {
			dp[i][j] = 0;
		}
	}
}

void print_input() {
	for (int i = 0; i < num; i++) {
		cerr << items[i].weight << " " << items[i].value << "\n";
	}
}

void print() {
	for (int i = 0; i <= num; i++) {
		for (int j = 0; j <= target; j++) {
			cerr << dp[i][j];
		}
		cerr << "\n";
	}
}

int max(float a, float b) { return a>b?a:b; }

void knapsack() {
	for (int i = 0; i <= num; i++) {
		for (int j = 0; j <= target; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			} else if (items[i-1].weight <= j) {
				// only compare with item in row above
				// item in prev column not compared
				// as we can take only 1 new item at a time in a row
				int exclude = dp[i-1][j];
				int include = dp[i-1][j - items[i-1].weight] + items[i-1].value;

				dp[i][j] = max(exclude, include);
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	print();
}

int main() {
	cout << "Apurva Mishra 22BCE2791\n";
	get_input();
	print_input();
	knapsack();
	cout << "Max Value: " << dp[num][target];
}
