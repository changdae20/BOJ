#include <bits/stdc++.h>

int main(int argc, char** argv){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif

    int T;

    std::cin >> T;

    for(int t=1; t<=T; t++){
        int N, R;
        

        std::vector<std::vector<int>> components;

        std::cin >> N >> R;

        std::vector<std::vector<int>> arr(N);
        std::vector<bool> visited(N, false);

        int src, dst;
        for(int i=0; i<R; i++){
            std::cin >> src >> dst;
            arr[src].push_back(dst);
            arr[dst].push_back(src);
        }
        for(auto it = visited.begin(); std::any_of(it, visited.end(), [](bool v) { return !v; });){
            std::vector<int> component;
            std::queue<int> q;
            q.push(std::distance(visited.begin(), it));
            while(!q.empty()){
                int current = q.front();
                q.pop();
                if(visited[current]) continue;
                component.push_back(current);
                visited[current] = true;
                for(auto& el : arr[current]){
                    if(!visited[el]){
                        q.push(el);
                    }
                }
            }
            components.push_back(component);
            it = std::find_if(it, visited.end(), [](bool v){return !v;});
        }

        auto it = std::remove_if(components.begin(), components.end(), [](auto& el){return el.size() == 1;});
        components.erase(it, components.end());

        int even = std::accumulate(components.begin(), components.end(), 0, [&arr](int acc, auto& compenent){
            // component 안에 있는 모든 노드가 짝수개의 간선
            return acc + std::all_of(compenent.begin(), compenent.end(), [&arr](int node){
                return (arr[node].size() & 1) == 0;
            });
        });
        int odd = std::accumulate(components.begin(), components.end(), 0, [&arr](int acc, auto& compenent){
            // 각 component마다 홀수간선인 노드 개수 더한다
            return acc + std::count_if(compenent.begin(), compenent.end(), [&arr](int node){
                return (arr[node].size() & 1) == 1;
            });
        });

        if(components.size() == 1){
            if(even) std::cout << "Case #" << t << ": 0" << '\n';
            else std::cout << "Case #" << t << ": " << odd/2 << '\n';
        }else{  
            std::cout << "Case #" << t << ": " << (even + odd/2 ) << '\n';
        }
        // std::cout << "[main2.cpp L" << __LINE__ << "] " << std::endl;
        // for(int i=0; i<components.size(); i++){
        //     std::cout << "Component " << i << " : ";
        //     for(auto& el : components[i]){
        //         std::cout << el << " ";
        //     }
        //     std::cout << std::endl;
        // }
        // std::cout << "Case #" << T << ": " << std::endl;
    }

    return 0;
}