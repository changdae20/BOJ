#include <bits/stdc++.h>

class CCTV{
public:
    int x, y, type, mode, size;
    CCTV(int x, int y, int type): x(x), y(y), type(type) {
        switch(type){
            case 1:
                size = 4;
                break;
            case 2:
                size = 2;
                break;
            case 3:
                size = 4;
                break;
            case 4:
                size = 4;
                break;
            case 5:
                size = 1;
                break;
        }
    }
    void set_mode(int mode) { this->mode = mode; }
    virtual void watch(std::vector<std::vector<int>> &map) = 0;
};

class CCTV1: public CCTV{
public:
    CCTV1(int x, int y): CCTV(x, y, 1) {}
    void watch(std::vector<std::vector<int>> &map) override {
        switch(mode){
            case 0:
                for(int i = x - 1; i >= 0; i--){
                    if(map[i][y] == 6) break;
                    map[i][y] = -1;
                }
                break;
            case 1:
                for(int i = y + 1; i < map[0].size(); i++){
                    if(map[x][i] == 6) break;
                    map[x][i] = -1;
                }
                break;
            case 2:
                for(int i = x + 1; i < map.size(); i++){
                    if(map[i][y] == 6) break;
                    map[i][y] = -1;
                }
                break;
            case 3:
                for(int i = y - 1; i >= 0; i--){
                    if(map[x][i] == 6) break;
                    map[x][i] = -1;
                }
                break;
        }
    }
};

class CCTV2: public CCTV{
public:
    CCTV2(int x, int y): CCTV(x, y, 2) {}
    void watch(std::vector<std::vector<int>> &map) override {
        switch(mode){
            case 0:
                for(int i = x - 1; i >= 0; i--){
                    if(map[i][y] == 6) break;
                    map[i][y] = -1;
                }
                for(int i = x + 1; i < map.size(); i++){
                    if(map[i][y] == 6) break;
                    map[i][y] = -1;
                }
                break;
            case 1:
                for(int i = y + 1; i < map[0].size(); i++){
                    if(map[x][i] == 6) break;
                    map[x][i] = -1;
                }
                for(int i = y - 1; i >= 0; i--){
                    if(map[x][i] == 6) break;
                    map[x][i] = -1;
                }
                break;
        }
    }
};

class CCTV3: public CCTV{
public:
    CCTV3(int x, int y): CCTV(x, y, 3) {}
    void watch(std::vector<std::vector<int>> &map) override {
        switch(mode){
            case 0:
                for(int i = x - 1; i >= 0; i--){
                    if(map[i][y] == 6) break;
                    map[i][y] = -1;
                }
                for(int i = y + 1; i < map[0].size(); i++){
                    if(map[x][i] == 6) break;
                    map[x][i] = -1;
                }
                break;
            case 1:
                for(int i = y + 1; i < map[0].size(); i++){
                    if(map[x][i] == 6) break;
                    map[x][i] = -1;
                }
                for(int i = x + 1; i < map.size(); i++){
                    if(map[i][y] == 6) break;
                    map[i][y] = -1;
                }
                break;
            case 2:
                for(int i = x + 1; i < map.size(); i++){
                    if(map[i][y] == 6) break;
                    map[i][y] = -1;
                }
                for(int i = y - 1; i >= 0; i--){
                    if(map[x][i] == 6) break;
                    map[x][i] = -1;
                }
                break;
            case 3:
                for(int i = y - 1; i >= 0; i--){
                    if(map[x][i] == 6) break;
                    map[x][i] = -1;
                }
                for(int i = x - 1; i >= 0; i--){
                    if(map[i][y] == 6) break;
                    map[i][y] = -1;
                }
                break;
        }
    }
};

class CCTV4: public CCTV{
public:
    CCTV4(int x, int y): CCTV(x, y, 4) {}
    void watch(std::vector<std::vector<int>> &map) override {
        switch(mode){
            case 0:
                for(int i = x - 1; i >= 0; i--){
                    if(map[i][y] == 6) break;
                    map[i][y] = -1;
                }
                for(int i = y + 1; i < map[0].size(); i++){
                    if(map[x][i] == 6) break;
                    map[x][i] = -1;
                }
                for(int i = x + 1; i < map.size(); i++){
                    if(map[i][y] == 6) break;
                    map[i][y] = -1;
                }
                break;
            case 1:
                for(int i = y + 1; i < map[0].size(); i++){
                    if(map[x][i] == 6) break;
                    map[x][i] = -1;
                }
                for(int i = x + 1; i < map.size(); i++){
                    if(map[i][y] == 6) break;
                    map[i][y] = -1;
                }
                for(int i = y - 1; i >= 0; i--){
                    if(map[x][i] == 6) break;
                    map[x][i] = -1;
                }
                break;
            case 2:
                for(int i = x + 1; i < map.size(); i++){
                    if(map[i][y] == 6) break;
                    map[i][y] = -1;
                }
                for(int i = y - 1; i >= 0; i--){
                    if(map[x][i] == 6) break;
                    map[x][i] = -1;
                }
                for(int i = x - 1; i >= 0; i--){
                    if(map[i][y] == 6) break;
                    map[i][y] = -1;
                }
                break;
            case 3:
                for(int i = y - 1; i >= 0; i--){
                    if(map[x][i] == 6) break;
                    map[x][i] = -1;
                }
                for(int i = x - 1; i >= 0; i--){
                    if(map[i][y] == 6) break;
                    map[i][y] = -1;
                }
                for(int i = y + 1; i < map[0].size(); i++){
                    if(map[x][i] == 6) break;
                    map[x][i] = -1;
                }
                break;
        }
    }
};

class CCTV5: public CCTV{
public:
    CCTV5(int x, int y): CCTV(x, y, 5) {}
    void watch(std::vector<std::vector<int>> &map) override {
        for(int i = x - 1; i >= 0; i--){
            if(map[i][y] == 6) break;
            map[i][y] = -1;
        }
        for(int i = y + 1; i < map[0].size(); i++){
            if(map[x][i] == 6) break;
            map[x][i] = -1;
        }
        for(int i = x + 1; i < map.size(); i++){
            if(map[i][y] == 6) break;
            map[i][y] = -1;
        }
        for(int i = y - 1; i >= 0; i--){
            if(map[x][i] == 6) break;
            map[x][i] = -1;
        }
    }
};

int main(int argc, const char * argv[]) {
    std::cin.tie( nullptr );
    std::ios::sync_with_stdio( false );
    std::cout.tie( nullptr );
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    int rows, cols;
    std::cin >> rows >> cols;
    int n;

    std::vector<std::vector<int>> map(cols, std::vector<int>(rows));
    std::vector<std::shared_ptr<CCTV>> cctvs;

    for( int y = 0; y < rows; ++y ) {
        for( int x = 0; x < cols; ++x ) {
            std::cin >> n;
            if(n == 1){
                cctvs.push_back(std::make_shared<CCTV1>(x, y));
            }else if(n == 2){
                cctvs.push_back(std::make_shared<CCTV2>(x, y));
            }else if(n == 3){
                cctvs.push_back(std::make_shared<CCTV3>(x, y));
            }else if(n == 4){
                cctvs.push_back(std::make_shared<CCTV4>(x, y));
            }else if(n == 5){
                cctvs.push_back(std::make_shared<CCTV5>(x, y));
            }
            map[x][y] = n;
        }
    }

    int min = 64;

    for( int i = 0; i < std::accumulate(cctvs.begin(), cctvs.end(), 1, [](int a, std::shared_ptr<CCTV> b){ return a * b->size;}); ++i){
        int current_seed = i;
        for(auto &cctv: cctvs){
            cctv->set_mode(current_seed % cctv->size);
            current_seed /= cctv->size;
        }

        std::vector<std::vector<int>> map_copy(map);

        for(auto &cctv: cctvs){
            cctv->watch(map_copy);
        }

        min = std::min( min, std::accumulate(map_copy.begin(), map_copy.end(), 0, [](int a, std::vector<int> b){ return a + std::count(b.begin(), b.end(), 0);}));
    }

    
    std::cout << min << '\n';

    return 0;
}