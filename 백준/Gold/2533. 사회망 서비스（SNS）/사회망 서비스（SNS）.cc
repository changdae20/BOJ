#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio( false );std::cin.tie( NULL );std::cout.tie( NULL );

std::vector<int> cache; // -1이면 방문 안한거, 0이면 일반인, 1이면 얼리어댑터

std::vector<std::vector<int>> parse_tree(std::vector<std::vector<int>>& adjacency_matrix, int root_node = 1){
    std::vector<std::vector<int>> children(adjacency_matrix.size());
    std::bitset<1000001> visited;

    std::queue<int> q;

    q.push(root_node);
    visited[root_node] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(auto& adj : adjacency_matrix[curr]){
            if(!visited[adj]){
                children[curr].push_back(adj);
                q.push(adj);
                visited[adj] = true;
            }
        }
    }

    return children;
}

bool is_early_adaptor(std::vector<std::vector<int>>& children, int idx){
    if(children[idx].size() == 0) return false; // leaf-node는 무조건 얼리 어댑터가 아님.
    if(cache[idx] != -1) return cache[idx]; // memoization 되어있으면 그걸로 반환
    if(std::all_of(children[idx].begin(), children[idx].end(), [&children](auto& child){
        return is_early_adaptor(children, child);
    })){ // 내 자식들이 모두 얼리어댑터면 나는 아니어도 됨
        return cache[idx] = false;
    }else{ // 한명이라도 아니면 나는 얼리어댑터여야 함.
        return cache[idx] = true;
    }
}

int main( int argc, char *argv[] ) {
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif
    fastio;

    int N,a,b;
    std::cin >> N;
    std::vector<std::vector<int>> adjacency_matrix(N+1);
    cache = std::vector<int> (N+1, -1);
    for(int i=0; i<N; ++i){
        std::cin >> a >> b;
        adjacency_matrix[a].push_back(b);
        adjacency_matrix[b].push_back(a);
    }

    auto tree = parse_tree(adjacency_matrix);
    
    int count = 0;
    for(int i=1; i<=N; ++i){
        if(is_early_adaptor(tree, i)) ++count;
    }

    std::cout << count << std::endl;
    return 0;
}