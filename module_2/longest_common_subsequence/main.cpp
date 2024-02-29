#include <iostream>
#include <string>
using namespace std;

int max(int a, int b) { return a>b?a:b; }

struct str {
	string s1;
	string s2;
} strings;

int **l;

void print_log(string name) {
	int m = strings.s1.length();
	int n = strings.s2.length();
	cerr << name << "\n";
	for (int i = 0; i < m+1; i++) {
		for (int j = 0; j < n+1; j++) {
			cerr << l[i][j];
		}
		cerr << "\n";
	}
}

int lcs() {
	int m = strings.s1.length();
	int n = strings.s2.length();

	l = new int*[m + 1];
	for (int i = 0; i < m+1; i++) {
		l[i] = new int[n+1];
	}
	
	for (int i = 0; i < m+1; i++) {
		for (int j = 0; j < n+1; j++) {
			l[i][j] = 0;
		}
	}

	print_log("initialize");

	for (int i = 0; i < m+1; i++) {
		for (int j = 0; j < n+1; j++) {
			if (i == 0 || j == 0) {
				l[i][j] = 0;
			} else if (strings.s1[i-1] == strings.s2[j-1]) {
				l[i][j] = l[i-1][j-1] + 1;
			} else {
				l[i][j] = max(l[i-1][j], l[i][j-1]);
			}
		}
	}
	print_log("output");
	return l[m][n];
}

void get_input() {
	getline(cin, strings.s1);
	getline(cin, strings.s2);
	cerr << "s1: " << strings.s1 << "\ns2: " << strings.s2 << "\n";
}


int main() {
	cout << "Apurva Mishra 22BCE2791\n";
	get_input();
	cout << "Longest Common Subsequence Length: "<< lcs() << "\n";
}
