#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

struct Node {
    long long max;
    long long second_max;
    long long max_count;
    long long sum;
};

Node operator + (Node a, Node b) {
    Node ans;
    ans.max = std::max<>(a.max, b.max);
    ans.sum = a.sum + b.sum;
    if (a.max > b.max) {
        ans.second_max = std::max<>(a.second_max, b.max);
        ans.max_count = a.max_count;
    }
    else if (a.max < b.max) {
        ans.second_max = std::max<>(a.max, b.second_max);
        ans.max_count = b.max_count;
    }
    else { // a.max == b.max
        ans.second_max = std::max<>(a.second_max, b.second_max);
        ans.max_count = a.max_count + b.max_count;
    }

    return ans;
}

void propagate(std::vector<Node>& tree, std::vector<long long>& lazy, int idx, int s, int e) {
    // lazy 없을 경우 -1
    long long _lazy = lazy[idx];
    if (_lazy == -1) return;

    if (s != e) {
        if (lazy[idx * 2] == -1) lazy[idx * 2] = _lazy;
        else lazy[idx * 2] = std::min<>(lazy[idx * 2], _lazy);
        if (lazy[idx * 2 + 1] == -1) lazy[idx * 2 + 1] = _lazy;
        else lazy[idx * 2 + 1] = std::min<>(lazy[idx * 2 + 1], _lazy);
    }
    return;
}

Node get(std::vector<Node>& tree, std::vector<long long>& lazy, int start_idx, int end_idx, int current_idx, int query_start, int query_end) {
    if (lazy[current_idx] != -1) {
        if (lazy[current_idx] < tree[current_idx].max) {
            tree[current_idx].sum -= (tree[current_idx].max - lazy[current_idx]) * tree[current_idx].max_count;
            tree[current_idx].max = lazy[current_idx];
        }
        
        propagate(tree, lazy, current_idx, start_idx, end_idx);
        lazy[current_idx] = -1;
    }

    if (start_idx == query_start && end_idx == query_end) {
        return tree[current_idx];
    }

    int mid = (start_idx + end_idx) / 2;
    if (query_end <= mid) {
        return get(tree, lazy, start_idx, mid, 2 * current_idx, query_start, query_end);
    }
    else if (mid + 1 <= query_start) {
        return get(tree, lazy, mid + 1, end_idx, 2 * current_idx + 1, query_start, query_end);
    }
    else {
        auto left = get(tree, lazy, start_idx, mid, 2 * current_idx, query_start, mid);
        auto right = get(tree, lazy, mid + 1, end_idx, 2 * current_idx + 1, mid + 1, query_end);
        return left + right;
    }
}

void init_node(std::vector<Node>& tree, int start_idx, int end_idx, int current_idx, int idx, long long value) {
    if (start_idx == idx && idx == end_idx) {
        tree[current_idx] = Node{ value, 0, 1, value };
        return;
    }

    int mid = (start_idx + end_idx) / 2;
    if (idx <= mid) {
        init_node(tree, start_idx, mid, 2 * current_idx, idx, value);
    }
    else if (mid + 1 <= idx) {
        init_node(tree, mid + 1, end_idx, 2 * current_idx + 1, idx, value);
    }
    tree[current_idx] = tree[2 * current_idx] + tree[2 * current_idx + 1];
    return;
}


void update(std::vector<Node>& tree, std::vector<long long>& lazy, int start_idx, int end_idx, int current_idx, int query_start, int query_end, long long value) {
    if (tree[current_idx].max <= value) return;

    if (start_idx == query_start && end_idx == query_end) {
        if (tree[current_idx].second_max < value) {
            if (lazy[current_idx] == -1) lazy[current_idx] = value;
            else lazy[current_idx] = std::min<>(lazy[current_idx], value);
            // tree[current_idx].sum -= (tree[current_idx].max - value) * tree[current_idx].max_count;
            // propagate(tree, lazy, current_idx, start_idx, end_idx);
            return;
        }
    }
    int mid = (start_idx + end_idx) / 2;
    if (query_end <= mid) {
        update(tree, lazy, start_idx, mid, 2 * current_idx, query_start, query_end, value);
    }
    else if (mid + 1 <= query_start) {
        update(tree, lazy, mid + 1, end_idx, 2 * current_idx + 1, query_start, query_end, value);
    }
    else {
        update(tree, lazy, start_idx, mid, 2 * current_idx, query_start, mid, value);
        update(tree, lazy, mid + 1, end_idx, 2 * current_idx + 1, mid + 1, query_end, value);
    }
    auto left = get(tree, lazy, start_idx, mid, 2 * current_idx, start_idx, mid);
    auto right = get(tree, lazy, mid + 1, end_idx, 2 * current_idx + 1, mid + 1, end_idx);

    tree[current_idx] = left + right;
    return;
}

int main(int argc, char* argv[]) {
#ifndef BOJ
    freopen(argv[1], "r", stdin);
#endif
    fastio;

    int N, Q;
    std::cin >> N;
    std::vector<Node> tree(5 * N, Node{ 0,0,0,0 });
    std::vector<long long> lazy(5 * N, -1);
    long long x;
    for (int i = 1; i <= N; ++i) {
        std::cin >> x;
        init_node(tree, 1, N, 1, i, x);
    }
    std::cin >> Q;
    char q;
    int l, r, v;
    while (Q--) {
        std::cin >> q >> l >> r;
        switch (q) {
        case '1':
            std::cin >> v;
            update(tree, lazy, 1, N, 1, l, r, v);
            break;
        case '2':
            std::cout << get(tree, lazy, 1, N, 1, l, r).max << '\n';
            break;
        case '3':
            std::cout << get(tree, lazy, 1, N, 1, l, r).sum << '\n';
            break;
        }
    }
    return 0;
}