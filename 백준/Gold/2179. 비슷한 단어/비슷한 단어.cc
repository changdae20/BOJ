#include <bits/stdc++.h>

int prefix(std::string &a, std::string &b){
    int i = 0;
    while(i < a.size() && i < b.size() && a[i] == b[i]) i++;
    return i;
}
int main(int argc, char** argv){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif

    int N;
    std::cin >> N;

    std::vector<std::pair<std::string, int>> dict(N);
    std::vector<std::pair<std::string, int>> copied_dict(N);
    std::vector<std::pair<int,int>> ans;
    int current_max = 0;

    for(int i=0; i<N; i++){
        std::cin >> dict[i].first;
        dict[i].second = i;
        copied_dict[i].first = dict[i].first;
        copied_dict[i].second = dict[i].second;
    }

    std::sort(dict.begin(), dict.end(), [](std::pair<std::string, int>& a, std::pair<std::string, int>& b){
        return std::strcmp(a.first.c_str(), b.first.c_str()) < 0;
    });

    
    for(auto it = dict.begin(); it != std::prev(dict.end(),1); it++){
        for(auto it2 = std::next(it, 1);it2!=dict.end();++it2){
            int count = prefix(it->first, it2->first);

            if(count==current_max){
                ans.push_back(std::make_pair(std::min<>(it->second, it2->second),std::max<>(it->second, it2->second)));
            }else if(count > current_max){
                current_max = count;
                ans.clear();
                ans.push_back(std::make_pair(std::min<>(it->second, it2->second),std::max<>(it->second, it2->second)));
            }else{
                break;
            }
        }
    }

    // for(auto& el : ans){
    //     std::cout << el.first << " " << el.second << std::endl;
    // }

    std::sort(ans.begin(), ans.end(), [](std::pair<int,int>& a, std::pair<int,int>& b){
        return (a.first == b.first) ? (a.second < b.second) : (a.first < b.first);
    });

    std::cout << copied_dict[ans[0].first].first << '\n';
    std::cout << copied_dict[ans[0].second].first << '\n';
    return 0;
}