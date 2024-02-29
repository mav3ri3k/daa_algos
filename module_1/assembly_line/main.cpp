#include <iostream>
#include <algorithm>
using namespace std;

int n;
int **a;
int **t;
int *e;
int *x;

void initialize() {
	cin >> n;
	a = new int*[2];
	t = new int*[2];
	e = new int[2];
	x = new int[2];

	for (int i = 0; i < n; i++) {
			a[i] = new int[n];
			t[i] = new int[n-1];
	}
}

void get_input() {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			cin >> t[i][j];
		}
	}

	for (int i = 0; i < 2; ++i) {
		cin >> e[i];
	}

	for (int i = 0; i < 2; ++i) {
		cin >> x[i];
	}
}

void set_values() {
	// utility to quicky set values while debugging
    // Set values for matrix a
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = (i == 0) ? (j == 0 ? 8 : (j == 1 ? 10 : (j == 2 ? 4 : (j == 3 ? 5 : 9)))) :
                      (j == 0 ? 9 : (j == 1 ? 6 : (j == 2 ? 7 : (j == 3 ? 5 : 6))));
        }
    }

    // Set values for matrix t
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            t[i][j] = (i == 0) ? (j == 0 ? 2 : (j == 1 ? 3 : (j == 2 ? 1 : 3))) :
                      (j == 0 ? 2 : (j == 1 ? 1 : (j == 2 ? 2 : 2)));
        }
    }

    // Set values for vector e
    for (int i = 0; i < n; ++i) {
        e[i] = (i == 0) ? 3 : 5;
    }

    // Set values for vector x
    for (int i = 0; i < n; ++i) {
        x[i] = (i == 0) ? 2 : 1;
    }
}


void print_values() {
    cerr << "Matrix a:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cerr << a[i][j] << " ";
        }
        cerr << endl;
    }

    cerr << "Matrix t:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            cerr << t[i][j] << " ";
        }
        cerr << endl;
    }

    cerr << "Vector e:\n";
    for (int i = 0; i < 2; ++i) {
        cerr << e[i] << " ";
    }
    cerr << endl;

    cerr << "Vector x:\n";
    for (int i = 0; i < 2; ++i) {
        cerr << x[i] << " ";
    }
    cerr << endl;
}

int assembly() { 
    int f1[n], f2[n]; 
 
    f1[0] = e[0] + a[0][0]; 
    f2[0] = e[1] + a[1][0]; 
 
    for(int j = 1; j< n; j++) { 
        f1[j] = min(f1[j - 1] + a[0][j], f2[j - 1] + t[1][j-1] + a[0][j]); 
        f2[j] = min(f2[j - 1] + a[1][j], f1[j - 1] + t[0][j-1] + a[1][j]); 
    } 
 
    return min(f1[4] + x[0], f2[4] + x[1]); 
} 

int main() { 
	cout << "Apurva Mishra 22BCE2791\n";
	initialize();
	get_input();
	//set_values();
	print_values();
    cout<<"Solution: "<< assembly(); 
} 
