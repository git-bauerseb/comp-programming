#include <iostream>

using namespace std;

int BOARD[9][9];

void getPosition(int* x, int* y) {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (BOARD[i][j] <= 0) {*x = j; *y = i; return;} 
		}
	}
}

bool isValid(int x, int y, int num) {
	// Check row/column
	for (int i = 0; i != 9; ++i) {
		if (BOARD[y][i] == num && i != x) return false;
		if (BOARD[i][x] == num && i != y) return false;
	}

	// Check box
	int boxX = x / 3;
	int boxY = y / 3;
	return BOARD[3*boxY][3*boxX] != num
		&& BOARD[3*boxY][3*boxX + 1] != num
		&& BOARD[3*boxY][3*boxX + 2] != num
		&& BOARD[3*boxY+1][3*boxX] != num
		&& BOARD[3*boxY+1][3*boxX+1] != num
		&& BOARD[3*boxY+1][3*boxX+2] != num
		&& BOARD[3*boxY+2][3*boxX] != num
		&& BOARD[3*boxY+2][3*boxX+1] != num
		&& BOARD[3*boxY+2][3*boxX+2] != num;
}

bool recBacktracking(int free) {
	if (free == 0) return true;
	int x, y;
	getPosition(&x, &y);
	for (int i = 1; i <= 9; ++i) {
		if (isValid(x,y,i)) {
			BOARD[y][x] = i;
			if (recBacktracking(free-1)) {return true;}
			BOARD[y][x] = 0;
		}
	}
	return false;
}


int main() {

	int free = 9*9;
	for (int i = 0; i != 9; ++i)
		for (int j = 0; j != 9; ++j)
		{cin >> BOARD[i][j]; free -= BOARD[i][j] == 0 ? 0 : 1;}

	recBacktracking(free);

	for (int i = 0; i != 9; ++i) {
		for (int j = 0; j != 9; ++j)
			cout << BOARD[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
