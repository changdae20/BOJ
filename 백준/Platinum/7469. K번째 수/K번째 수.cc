#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>

void update(std::vector<std::vector<int>> &arr, int level, int start, int end, int idx, int num) {
	arr[level].push_back(num);
	if (start == end) return;

	int mid = (start + end) / 2;
	if (idx <= mid) {
		update(arr, 2 * level, start, mid, idx, num);
	}
	else {
		update(arr, 2 * level + 1, mid + 1, end, idx, num);
	}
}

int query(std::vector<std::vector<int>> &arr, int level, int start, int end, int i, int j, int k) {
	if (start == i && end == j) {
		return std::lower_bound(arr[level].begin(), arr[level].end(), k) - arr[level].begin();
	}
	int mid = (start + end) / 2;
	if (j <= mid) { // 왼쪽에 포함되는 경우
		return query(arr, 2 * level, start, mid, i, j, k);
	}
	else if (mid + 1 <= i) { // 오른쪽에 포함되는 경우
		return query(arr, 2 * level + 1, mid + 1, end, i, j, k);
	}
	else {
		return query(arr, 2 * level, start, mid, i, mid, k) + query(arr, 2 * level + 1, mid + 1, end, mid + 1, j, k);
	}
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N, M;
	std::cin >> N >> M;
	std::vector<std::vector<int>> arr(4 * N, std::vector<int>());
	int num;
	for (int i = 1; i <= N; i++) {
		std::cin >> num;
		update(arr, 1, 1, N, i, num);
	}

	std::for_each(arr.begin(), arr.end(), [](auto &el) mutable {std::sort(el.begin(), el.end()); });

	// 쿼리
	int q1, q2, q3;
	while (M--) {
		std::cin >> q1 >> q2 >> q3;

		int left = -1000000000;
		int right = 1000000000;
		int mid;
		while (left <= right) {
			mid = (left + right) / 2;
			auto q4 = query(arr, 1, 1, N, q1, q2, mid);
			if (q4 >= q3) {
				right = mid-1;
			}
			else {
				left = mid + 1;
			}
		}
		std::cout << left-1<< "\n";
	}
}