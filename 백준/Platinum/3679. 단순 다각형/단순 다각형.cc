#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

struct Point{
    int x;
    int y;
    int idx;
};

Point operator+(const Point &x, const Point &y){
    return Point{x.x+y.x, x.y+y.y};
}

std::istream& operator>>(std::istream &in, Point &pt){
    int x, y;
    in >> x >> y;
    pt.x = x+1;pt.y = y+1;
    return in;
}

void swap(Point& pt1, Point& pt2){
    auto [x2,y2,idx2] = pt2;
    pt2 = pt1;
    pt1 = Point{x2,y2,idx2};
    return;
}

void make_polygon(std::vector<Point> &points){
    // 먼저, 제일 왼쪽 아래에 있는 점을 고른다.
    auto leftmost_bottom = std::min_element(points.begin(), points.end(), [](auto& pt1, auto& pt2){
        if(pt1.x != pt2.x) return pt1.x < pt2.x;
        return pt1.y < pt2.y;
    });

    // 0번째 점이 제일 왼쪽 아래에 오도록 만든다.
    swap(points[0], *leftmost_bottom);

    // 기준점 x,y 저장
    auto [x, y, idx] = points[0];

    std::sort(std::next(points.begin()), points.end(), [x,y](auto& pt1, auto& pt2){
        int dx1 = pt1.x-x;
        int dx2 = pt2.x-x;
        int dy1 = pt1.y-y;
        int dy2 = pt2.y-y;

        if(dy1*dx2 == dy2*dx1){ // 기울기가 같으면 가까운거 먼저 오도록 정렬
            return (dx1*dx1 + dy1*dy1) < (dx2*dx2 + dy2*dy2);
        }else{ // 아니면 기울기 큰게 나중에 가도록
            return (dy1*dx2) < (dy2*dx1);
        }
    });

    auto last_pt = points.back(); // 마지막거랑

    // 기울기가 같은 놈들은 뒤집어 주려고 제일 처음거 탐색
    auto same_with_last = std::find_if(std::next(points.begin()), points.end(), [x,y,last_pt](auto& pt){
        int dx1 = pt.x-x;
        int dx2 = last_pt.x-x;
        int dy1 = pt.y-y;
        int dy2 = last_pt.y-y;

        return dy1*dx2 == dy2*dx1;
    });
    
    // 찾은놈 부터 마지막까지는 멀리 있는거부터 가까이있는 방향으로 해야되니까 뒤집어주기
    std::reverse(same_with_last, points.end());

    for(auto& el : points){
        std::cout << el.idx << ' ';
    }
    
    std::cout << '\n';

    return;
}
int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;

    int T;
    std::cin >> T;
    
    while(T--){
        int N;
        std::cin >> N;
        std::vector<Point> points(N);
        for(int i=0; i<N; ++i){
            Point pt;
            std::cin >> pt;
            pt.idx = i;
            points[i] = pt;
        }
        make_polygon(points);
    }
	return 0;
}