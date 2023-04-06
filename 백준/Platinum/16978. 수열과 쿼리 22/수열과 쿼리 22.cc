#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

long long get_sum(std::vector<long long>& tree, int cur_node, int start_of_this_node, int end_of_this_node, int start_of_interval, int end_of_interval) {
    if (start_of_this_node == start_of_interval && end_of_this_node == end_of_interval) {
        return tree[cur_node];
    }
    int mid = (start_of_this_node + end_of_this_node) / 2;

    if (end_of_interval <= mid) {
        return get_sum(tree, 2 * cur_node, start_of_this_node, mid, start_of_interval, end_of_interval);
    }
    else if (start_of_interval > mid) {
        return get_sum(tree, 2 * cur_node + 1, mid + 1, end_of_this_node, start_of_interval, end_of_interval);
    }
    else {
        return get_sum(tree, 2 * cur_node, start_of_this_node, mid, start_of_interval, mid) + get_sum(tree, 2 * cur_node + 1, mid + 1, end_of_this_node, mid + 1, end_of_interval);
    }
}

void update(std::vector<long long>& tree, int cur_node, int start_of_this_node, int end_of_this_node, int update_idx, int update_value) {
    if (start_of_this_node == end_of_this_node) {
        tree[cur_node] = update_value;
        return;
    }
    int mid = (start_of_this_node + end_of_this_node) / 2;
    if (update_idx <= mid) {
        update(tree, cur_node * 2, start_of_this_node, mid, update_idx, update_value);
    }
    else {
        update(tree, cur_node * 2 + 1, mid + 1, end_of_this_node, update_idx, update_value);
    }
    tree[cur_node] = tree[cur_node * 2] + tree[cur_node * 2 + 1];
    return;
}


int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin >> N;
    std::vector<long long> tree(4 * N);

    std::vector<std::tuple<int, int>> updates; // (i, v)
    std::vector<std::tuple<int, int, int, int>> queries; // (쿼리의 인덱스, k, i, j)
    for (int i = 1; i <= N; i++) {
        int num;
        std::cin >> num;
        update(tree, 1, 1, N, i, num);
    }
    int T;
    std::cin >> T;
    int q_cnt = 0;
    while (T--) {
        int mode;
        int i;
        std::cin >> mode;
        switch (mode) {
        case 1:
            int v;
            std::cin >> i >> v;
            updates.push_back(std::tuple(i, v));
            break;

        case 2:
            int k, j;
            std::cin >> k >> i >> j;
            queries.push_back(std::tuple(q_cnt++, k, i, j));
            break;
        }
    }

    std::vector<long long> ans(queries.size());
    std::sort(queries.begin(), queries.end(), [](const auto& first, const auto& second) {
        auto [first_q_cnt, first_k, first_i, first_j] = first;
        auto [second_q_cnt, second_k, second_i, second_j] = second;
        return first_k < second_k;
        });

    int ongoing_query = 0;
    for (auto [q_cnt, k, i, j] : queries) {
        if (ongoing_query < k) { // 다음 진행해야 하는 업뎃이 쿼리 요구치보다 버전이 낮은 경우
            while (ongoing_query < k) {
                auto [a, b] = updates[ongoing_query++];
                update(tree, 1, 1, N, a, b);
            }
        }
        ans[q_cnt] = get_sum(tree, 1, 1, N, i, j);
    }

    for (const auto& el : ans) {
        std::cout << el << "\n";
    }

    return 0;
}