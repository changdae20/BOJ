#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

struct Point{
    long long x;
    long long y;
};

Point operator - (Point p1, Point p2){
    return Point{p1.x-p2.x, p1.y-p2.y};
}

long double det(Point p1, Point p2){
    return static_cast<long double>(p1.x*p2.y - p1.y*p2.x);
}

int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	
	int N;
    std::cin >> N;
    std::vector<Point> v(N);
    for(auto& [x,y] : v) std::cin >> x >> y;

    long double ans = 0.0;
    for(int i=1; i<N;++i){
        ans += det(v[i-1]-v[0], v[i]-v[0]);
    }
    std::cout << std::fixed;
    std::cout.precision(1);
    ans = std::abs(ans/2.0);
    ans = std::round(ans*10)/10.0;
    std::cout << ans << std::endl;
    return 0;
}