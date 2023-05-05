#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

struct Node {
    long long max;
    long long min;
    long long sum;
};

Node operator + (Node a, Node b) {
    Node ans;
    ans.max = std::max<>(a.max, b.max);
    ans.min = std::min<>(a.min, b.min);
    ans.sum = a.sum + b.sum;

    return ans;
}

long long mysqrt(long long n){ return std::floor(std::sqrt<>(n));}

void propagate(std::vector<Node>& tree, std::vector<std::pair<long long, long long>>& lazy, int idx, int s, int e) {
    auto [value, offset] = lazy[idx];

    if (s != e) {
        if(value){
            lazy[idx * 2].first = value;
            lazy[idx * 2 + 1].first = value;
            lazy[idx * 2].second = 0;
            lazy[idx * 2 + 1].second = 0;
        }
        if(offset){
            lazy[idx * 2].second += offset;
            lazy[idx * 2 + 1].second += offset;
        }
    }
    return;
}

Node get(std::vector<Node>& tree, std::vector<std::pair<long long, long long>>& lazy, int start_idx, int end_idx, int current_idx, int query_start, int query_end) {
    if (lazy[current_idx].first || lazy[current_idx].second) { 
        if(lazy[current_idx].first) {// 같은 값으로 변하는 lazy
            tree[current_idx].sum = lazy[current_idx].first * (end_idx - start_idx + 1);
            tree[current_idx].max = lazy[current_idx].first;
            tree[current_idx].min = lazy[current_idx].first;
        }
        if(lazy[current_idx].second){ // 같은 값만큼 더해지는 lazy
            tree[current_idx].sum += lazy[current_idx].second * (end_idx - start_idx + 1);
            tree[current_idx].max += lazy[current_idx].second;
            tree[current_idx].min += lazy[current_idx].second;
        }
        
        propagate(tree, lazy, current_idx, start_idx, end_idx);
        lazy[current_idx] = std::pair(0,0);
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
        tree[current_idx] = Node{ value, value, value };
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

void query_sqrt(std::vector<Node>& tree, std::vector<std::pair<long long, long long>>& lazy, int start_idx, int end_idx, int current_idx, int query_start, int query_end) {
    if (lazy[current_idx].first || lazy[current_idx].second) { 
        if(lazy[current_idx].first) {// 같은 값으로 변하는 lazy
            tree[current_idx].sum = lazy[current_idx].first * (end_idx - start_idx + 1);
            tree[current_idx].max = lazy[current_idx].first;
            tree[current_idx].min = lazy[current_idx].first;
        }
        if(lazy[current_idx].second){ // 같은 값만큼 더해지는 lazy
            tree[current_idx].sum += lazy[current_idx].second * (end_idx - start_idx + 1);
            tree[current_idx].max += lazy[current_idx].second;
            tree[current_idx].min += lazy[current_idx].second;
        }
        
        propagate(tree, lazy, current_idx, start_idx, end_idx);
        lazy[current_idx] = std::pair(0,0);
    }
    
    if (start_idx == query_start && end_idx == query_end) {
        // 최소와 최대의 sqrt가 같으면 전부 같은값으로 변함
        if (mysqrt(tree[current_idx].min) == mysqrt(tree[current_idx].max)) {
            lazy[current_idx].first = mysqrt(tree[current_idx].min);
            lazy[current_idx].second = 0;
            return;
        }else if(tree[current_idx].min + 1 == tree[current_idx].max){
        // 최소 + 1 == 최대인 경우 같은값만큼 빼주는거처럼 작용한다.
            lazy[current_idx].second += (mysqrt(tree[current_idx].min) - tree[current_idx].min);
            return;
        }
    }
    int mid = (start_idx + end_idx) / 2;
    if (query_end <= mid) {
        query_sqrt(tree, lazy, start_idx, mid, 2 * current_idx, query_start, query_end);
    }
    else if (mid + 1 <= query_start) {
        query_sqrt(tree, lazy, mid + 1, end_idx, 2 * current_idx + 1, query_start, query_end);
    }
    else {
        query_sqrt(tree, lazy, start_idx, mid, 2 * current_idx, query_start, mid);
        query_sqrt(tree, lazy, mid + 1, end_idx, 2 * current_idx + 1, mid + 1, query_end);
    }
    auto left = get(tree, lazy, start_idx, mid, 2 * current_idx, start_idx, mid);
    auto right = get(tree, lazy, mid + 1, end_idx, 2 * current_idx + 1, mid + 1, end_idx);

    tree[current_idx] = left + right;
    return;
}

void query_offset(std::vector<Node>& tree, std::vector<std::pair<long long, long long>>& lazy, int start_idx, int end_idx, int current_idx, int query_start, int query_end, long long value) {
    if (lazy[current_idx].first || lazy[current_idx].second) { 
        if(lazy[current_idx].first) {// 같은 값으로 변하는 lazy
            tree[current_idx].sum = lazy[current_idx].first * (end_idx - start_idx + 1);
            tree[current_idx].max = lazy[current_idx].first;
            tree[current_idx].min = lazy[current_idx].first;
        }
        if(lazy[current_idx].second){ // 같은 값만큼 더해지는 lazy
            tree[current_idx].sum += lazy[current_idx].second * (end_idx - start_idx + 1);
            tree[current_idx].max += lazy[current_idx].second;
            tree[current_idx].min += lazy[current_idx].second;
        }
        
        propagate(tree, lazy, current_idx, start_idx, end_idx);
        lazy[current_idx] = std::pair(0,0);
    }
    
    if (start_idx == query_start && end_idx == query_end) {
        lazy[current_idx].second += value;
        return;
    }

    int mid = (start_idx + end_idx) / 2;
    if (query_end <= mid) {
        query_offset(tree, lazy, start_idx, mid, 2 * current_idx, query_start, query_end, value);
    }
    else if (mid + 1 <= query_start) {
        query_offset(tree, lazy, mid + 1, end_idx, 2 * current_idx + 1, query_start, query_end, value);
    }
    else {
        query_offset(tree, lazy, start_idx, mid, 2 * current_idx, query_start, mid, value);
        query_offset(tree, lazy, mid + 1, end_idx, 2 * current_idx + 1, mid + 1, query_end, value);
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
    std::vector<Node> tree(4 * N, Node{ 0,0,0 });
    std::vector<std::pair<long long, long long>> lazy(4 * N, std::pair(0,0));
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
            query_offset(tree, lazy, 1, N, 1, l, r, v);
            break;
        case '2':
            query_sqrt(tree, lazy, 1, N, 1, l, r);
            break;
        case '3':
            std::cout << get(tree, lazy, 1, N, 1, l, r).sum << '\n';
            break;
        }
    }
    return 0;
}