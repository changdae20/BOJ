#include <bits/stdc++.h>

double ans = 0;

class Map{
    public:
        bool visited[29][29];

        Map(){
            for(int i = 0; i < 29; i++){
                for(int j = 0; j < 29; j++){
                    visited[i][j] = false;
                }
            }
        }

        bool& operator()(int x, int y){
            if(x<-14 || x>14 || y<-14 || y>14){
                throw std::out_of_range("Map::Out of range");
            }
            return visited[x+14][y+14];
        }
};

void dfs(int x, int y, Map& map, std::vector<double> &prob, int count, int goal_count, double current_prob){
    if(count==goal_count){
        ans += current_prob;
        return;
    } 

    if(!map(x-1,y)){
        map(x-1,y) = true;
        dfs(x-1,y,map,prob,count+1,goal_count,current_prob*prob[0]);
        map(x-1,y) = false;
    }
    if(!map(x+1,y)){
        map(x+1,y) = true;
        dfs(x+1,y,map,prob,count+1,goal_count,current_prob*prob[1]);
        map(x+1,y) = false;
    }
    if(!map(x,y-1)){
        map(x,y-1) = true;
        dfs(x,y-1,map,prob,count+1,goal_count,current_prob*prob[2]);
        map(x,y-1) = false;
    }
    if(!map(x,y+1)){
        map(x,y+1) = true;
        dfs(x,y+1,map,prob,count+1,goal_count,current_prob*prob[3]);
        map(x,y+1) = false;
    }

    return;
}   
int main(int argc, char** argv){
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif

    Map m;

    m(0,0) = true;

    int N;
    int right, left, down, up;
    std::cin >> N >> right >> left >> down >> up;
    std::vector<double> prob{right/100.0, left/100.0, down/100.0, up/100.0};
    dfs(0,0,m, prob, 0, N, 1.0);
    std::cout << std::setprecision(10) << ans << std::endl;
    return 0;
}