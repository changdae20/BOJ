#include <bits/stdc++.h>

int main( int argc, char *argv[] ) {
#ifndef BOJ
freopen( argv[ 1 ], "r", stdin );
#endif
    int N,M,x,y;
    std::cin >> N >> M;
    std::vector<std::vector<int>> map (N+1, std::vector<int>());
    std::vector<std::pair<bool, int>> visited (N+1, std::pair(false, INT_MAX));
    while(M--){
        std::cin >> x >> y;
        map[x].push_back(y);
    }

    std::queue<int> q;
    visited[1] = std::pair(false, 0);

    q.push(1);
    while(visited[N].first == false && !q.empty()){
        int curr = q.front();
        q.pop();
        if(visited[curr].first) continue; // 방문한 경우 continue
        visited[curr].first = true;
        for(auto &next : map[curr]){
            if(!visited[next].first){
                visited[next].second = std::min<>(visited[next].second, visited[curr].second + 1);
            }
            q.push(next);
        }
    }

    std::cout << ((visited[N].second==INT_MAX) ? -1 : visited[N].second) << std::endl;

    return 0;
}