#include <iostream>
using namespace std;

const int inf = INT_MAX;

int n;
int **w;

void get_input() {
	cout << "Number of vertices: ";
	cin >> n;

	w = new int*[n];
	for (int i = 0; i < n; i++) {
		w[i] = new int[n];
	}

	cout << "Inter graph edge matrix. For unreachable vertices, use negative number.\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];

			if (w[i][j] <= 0) {
				w[i][j] = inf;
			}
		}
	}
}

void pseudo_input() {
	w = new int*[n];
	*w = new int[n];

	int w1[] = { 7, 5, inf, inf}; 
	int w2[] = {7, inf, inf, 2}; 
	int w3[] = {inf, 3, inf, inf}; 
	int w4[] = {4, inf, 1, inf}; 
	int *w5[] = {w1, w2, w3, w4};

	w = w5;
}

void print_weights(bool debug) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (debug) {
				if (w[i][j] == INT_MAX) {
					cerr << "i" << " "; // infinite
				} else {
					cerr << w[i][j] << " ";
				}
			} else {
				if (w[i][j] == INT_MAX) {
					cout << "i" << " ";
				} else {
					cout << w[i][j] << " ";
				}
			}
		}
		if (debug) {
			cerr << "\n";
		} else {
			cout << "\n";
		}
	}
}

int fancy_add(int a, int b) {
	// returns int_max + something = int_mac
	if (a == inf || b == inf) {
		return inf;
	} else {
		return a + b;
	}
}

void fwa() {
	for (int i = 0; i < n; i++) {
		for (int s = 0;  s < n; s++) {
			for (int d = 0; d < n; d++) {
				if (s == i || d == i) {
					continue;
				}
				int sid = fancy_add(w[s][i], w[i][d]); // source intermediate destination
				if ( w[s][d] > sid) {
					w[s][d] = sid;
				}
			}
		}
	}
}

int main() {
	cout << "Apurva Mishra 22BCE2791\n";
	cerr << "Input" << endl;
	// input negative values to show infinite
	get_input();
	cout << "Input:" << endl;
	print_weights(true);
	fwa();
	cout << "Final distances: " << endl;
	print_weights(false);
}
