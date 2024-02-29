#include <iostream>
using namespace std;

int len;
int** board;

void get_input() {
	cin >> len;
	board = new int*[len];
	for (int i = 0; i < len; i++) {
		board[i] = new int[len];
	}

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			board[i][j] = 0;
		}
	}
}

void print(int **board) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			std::cout << board[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

bool is_safe(int** board, int i, int j) {
	// check if placing queen at [i][j] is safe on boad
	cerr << "check " << i << ", " << j << "\n";
	
	for (int k = j-1; k >= 0; k--) {
		if (board[i][k] == 1) {
			return false;
		}
	}

	int d = 0;
	// goes north west
	while (i-d >= 0 && j-d >= 0) {
		if (board[i-d][j-d] == 1) {
			return false;
		}
		d += 1;
	}

	d = 0;
	// goes south 
	while (i+d <= len-1 && j-d >= 0) {
		if (board[i+d][j-d] == 1) {
			return false;
		}
		d += 1;
	}

	return true;
}

bool n_queen(int **board, int col, int queen_to_place) {
	cerr << "START " << col << "\n";
	if (queen_to_place == 0 || col >= len) {
		if (queen_to_place == 0) {
			print(board);
		}
		return true;
	}

	for (int i = 0; i < len; i++) {
		cerr << "ROW " << i << "\n";
		if (is_safe(board, i, col)) {
			board[i][col] = 1;
			n_queen(board, col + 1, queen_to_place - 1);
			board[i][col] = 0;
		}
	}

	return false;
}

int main() {
	cout << "Apurva Mishra 22BCE2791\n";
	get_input();
	n_queen(board, 0, len);
	return 0;
}
