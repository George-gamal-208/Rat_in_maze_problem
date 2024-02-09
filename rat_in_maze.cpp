#include <iostream>
#include <vector>
#include <string>
using namespace std;
//int count = 0;
//vector<int>v1;
int m[12][6] = { {1,0,0,1,1,1},{1,0,0,1,1,1},{1,1,1,1,0,1},{1,1,1,1,0,1},{0,1,0,1,1,1},{0,1,0,1,1,1},{1,1,1,0,0,0},{1,1,1,0,0,0},{1,0,1,1,1,1},{1,0,1,1,1,1},{1,0,0,1,0,1},{1,0,0,1,0,1} };
int n[12][6] = { {0,0,0,0,0,0},{0,0,0,0,0,0} ,{0,0,0,0,0,0} ,{0,0,0,0,0,0} ,{0,0,0,0,0,0} ,{0,0,0,0,0,0} ,{0,0,0,0,0,0} ,{0,0,0,0,0,0} ,{0,0,0,0,0,0} ,{0,0,0,0,0,0} ,{0,0,0,0,0,0} ,{0,0,0,0,0,0} };
void print(int M[12][6]) {
	int count = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << M[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}
int counter(int M[12][6]) {
	int count = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (M[i][j] == 1)
				count++;
		}
	}
	return count;
}
void solve_the_maze(int M[12][6], int row, int col, int N[12][6], vector<int>& vec) {
	if (row < 0 || col < 0 || row >= 12 || col >= 6 || M[row][col] == 0) {
		return;
	}
	else {
		N[row][col] = 1;
	}
	if (row == 11 && col == 5) {
		N[11][5] = 1;
		vec.push_back(counter(N));
		print(N);
		return;
	}
	M[row][col] = 0;
	solve_the_maze(M, row - 1, col, N, vec);
	solve_the_maze(M, row, col + 1, N, vec);
	solve_the_maze(M, row, col - 1, N, vec);
	solve_the_maze(M, row + 1, col, N, vec);
	M[row][col] = 1;
	N[row][col] = 0;
	return;
}
void solve_the_maze1(int M[12][6], int row, int col, int N[12][6], vector<int>& vec) {
	if (row < 0 || col < 0 || row >= 12 || col >= 6 || M[row][col] == 0) {
		return;
	}
	else {
		N[row][col] = 1;
	}
	if (row == 11 && col == 5) {
		N[11][5] = 1;
		vec.push_back(counter(N));
		return;
	}
	M[row][col] = 0;
	solve_the_maze1(M, row - 1, col, N, vec);
	solve_the_maze1(M, row, col + 1, N, vec);
	solve_the_maze1(M, row, col - 1, N, vec);
	solve_the_maze1(M, row + 1, col, N, vec);
	M[row][col] = 1;
	N[row][col] = 0;
	return;
}
vector<int>counter1() {
	vector<int>vec;
	solve_the_maze1(m, 0, 0, n, vec);
	return vec;
}
vector<int>v = counter1();
int fun() {
	int min = v[0];
	for (int i = 0; i < v.size(); i++) {
		if (min > v[i]) {
			min = v[i];
		}
	}
	return min;
}
void Find_Shortest_Path(int M[12][6], int row, int col, int N[12][6]) {
	static int count = 0;
	if (row < 0 || col < 0 || row >= 12 || col >= 6 || M[row][col] == 0) {
		return;
	}
	else {
		N[row][col] = 1;
	}
	if (row == 11 && col == 5) {
		N[11][5] = 1;
		if (counter(N) == fun()) {
			print(N);
			cout << counter(N);
			cout << "shortest" << endl;
		}
		count++;
		return;
	}
	M[row][col] = 0;
	Find_Shortest_Path(M, row - 1, col, N);
	Find_Shortest_Path(M, row, col + 1, N);
	Find_Shortest_Path(M, row, col - 1, N);
	Find_Shortest_Path(M, row + 1, col, N);
	M[row][col] = 1;
	N[row][col] = 0;
	return;
}

int main() {
	vector<int> vec;
	solve_the_maze(m, 0, 0, n,vec);
	//for (int i = 0; i < v.size(); i++) {
		//cout << v[i] << " ";
	//}
	//cout << endl;
	//fun();
	//for (int i = 0; i < v1.size(); i++) {
		//cout << v1[i] << " ";
	//} 
	//Find_Shortest_Path(m, 0, 0, n);
	//cout << v1.size();
	//solve_the_maze(m, 0, 0, n,vec);
}

