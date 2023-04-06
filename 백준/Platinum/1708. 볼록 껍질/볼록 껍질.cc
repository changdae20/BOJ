#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

struct Point{
    long long x;
    long long y;
    int idx;
};

Point operator+(const Point &x, const Point &y){
    return Point{x.x+y.x, x.y+y.y};
}

std::istream& operator>>(std::istream &in, Point &pt){
    long long x, y;
    in >> x >> y;
    pt.x = x;pt.y = y;
    return in;
}

void swap(Point& pt1, Point& pt2){
    auto [x2,y2,idx2] = pt2;
    pt2 = pt1;
    pt1 = Point{x2,y2,idx2};
    return;
}

bool ccw(const Point& pt1, const Point& pt2, const Point& pt3){
    long long dx1 = pt2.x - pt1.x;
    long long dy1 = pt2.y - pt1.y;
    long long dx2 = pt3.x - pt2.x;
    long long dy2 = pt3.y - pt2.y;

    return (dx1*dy2 - dx2*dy1) > 0LL;
}

void make_convex_hull(std::vector<Point> &points){
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
        long long dx1 = pt1.x-x;
        long long dx2 = pt2.x-x;
        long long dy1 = pt1.y-y;
        long long dy2 = pt2.y-y;

        if(dy1*dx2 == dy2*dx1){ // 기울기가 같으면 가까운거 먼저 오도록 정렬
            return (dx1*dx1 + dy1*dy1) < (dx2*dx2 + dy2*dy2);
        }else{ // 아니면 기울기 큰게 나중에 가도록
            return (dy1*dx2) < (dy2*dx1);
        }
    });

    std::stack<Point> s;

    s.push(points[0]);
    s.push(points[1]);

    for(size_t i=2; i<points.size();){
        while(s.size()>=2){
            auto pt1 = s.top();
            s.pop();
            auto pt0 = s.top();

            if(ccw(pt0, pt1, points[i])){
                s.push(pt1);
                break;
            }
        }
        
        s.push(points[i]);
        ++i;
    }

    std::cout << s.size() << std::endl;
    return;
}
int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;

    
    int N;
    std::cin >> N;
    std::vector<Point> points(N);
    for(int i=0; i<N; ++i){
        Point pt;
        std::cin >> pt;
        pt.idx = i;
        points[i] = pt;
    }
    make_convex_hull(points);
	return 0;
}