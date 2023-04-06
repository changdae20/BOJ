#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

int size;

int solve(std::vector<std::vector<std::pair<int,int>>> &board, std::vector<bool>& ver, int i) {
	if (i >= board.size()) return 0;

	int maxx = 0;
	for (auto[x, y] : board[i]) {
		if (ver[x - y + size]) { // 아직 가로줄 안놓였다면
			ver[x - y + size] = false;
			maxx = std::max(maxx, solve(board, ver, i + 2) + 1);
			ver[x - y + size] = true;
		}
	}
	maxx = std::max(maxx, solve(board, ver, i + 2));

	return maxx;
}

int main() {
	
	std::cin >> size;

	std::vector<std::vector<std::pair<int, int>>> board(2*size-1);
	std::vector<bool> ver(2 * size - 1, true);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int num;
			std::cin >> num;
			if (num) board[i + j].emplace_back(i, j);
		}
	}

	std::cout << solve(board, ver, 0) + solve(board, ver, 1);

	return 0;
}