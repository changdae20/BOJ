#include <bits/stdc++.h>

std::vector<int> priority_count(101,0);

class Container {
    public:
    int weight = 0;
    int priority = 0;

    operator std::string() const{
        return std::string("(") + std::to_string(priority) + std::string(", ") + std::to_string(weight) + std::string(")");
    }
};

std::istream& operator >> (std::istream& is, Container& c) {
    is >> c.priority >> c.weight;
    ++priority_count[c.priority];
    return is;
}

std::ostream& operator << (std::ostream& os, Container& c) {
    os << static_cast<std::string>(c);
    return os;
}

int main(int argc, char** argv) {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);
#ifndef BOJ
    auto f = freopen(argv[1], "r", stdin);
#endif

    int N,M;

    std::cin >> N >> M;

    std::queue<Container> rail;
    std::vector<Container> storage;
    
    for(int i = 0; i < N; i++) {
        Container c;
        std::cin >> c;
        rail.push(c);
    }

    int ans = 0;

    while(!rail.empty()){
        auto c = rail.front();
        rail.pop();
        if(c.priority!=M){ // 현재 필요한 우선순위가 아니면 다시 레일로 돌려보낸다
            ans += c.weight;
            rail.push(c);
        }else if(storage.empty()){ // 창고가 비어있으면 그냥 추가
            storage.push_back(c);
            ans += c.weight;
            --priority_count[c.priority];
        }else{ // 현재 필요한 우선순위를 넣고싶은데 창고가 비어있지 않다
            auto top = storage.back();

            // top과 우선순위가 같으면 무게를 비교해야함
            if(top.priority == c.priority){
                auto it = std::find_if(storage.rbegin(), storage.rend(), [&c](auto &el){
                    return (c.priority!=el.priority) || (c.priority==el.priority && c.weight<=el.weight);
                }); // 넣을 곳을 찾아서
                int sum_of_rearrange = std::accumulate(storage.rbegin(), it, 0, [](int acc, auto& el){return acc+el.weight;}); // 그때 까지의 합은 2배로 적용(뺐다가 다시 적재)
                storage.insert(std::next(storage.begin(), storage.size() - std::distance(storage.rbegin(), it)), c); // 창고에 넣어주고
                ans += (2*sum_of_rearrange) + c.weight; // 코스트 계산
                --priority_count[c.priority];
            }else{// top과 우선순위가 다르면 그냥 넣어도 됨
                storage.push_back(c);
                ans += c.weight;
                --priority_count[c.priority];
            }
        }
        if(priority_count[M]==0){
            --M;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}