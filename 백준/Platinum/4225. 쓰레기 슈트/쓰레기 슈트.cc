#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <functional>
#include <cmath>

using ll = long long;
struct Point {
    int x, y;
    int p, q;
    Point(int x1 = 0, int y1 = 0) : x(x1), y(y1), p(1), q(0) {}
};
 
bool comp(const Point &A, const Point &B) {
    if (1LL * A.q * B.p != 1LL * A.p*B.q)
        return 1LL * A.q * B.p < 1LL * A.p*B.q;
    else if (A.y != B.y)
        return A.y < B.y;
	else return A.x < B.x;
}
 
ll ccw(const Point &A, const Point &B, const Point &C) {
    return 1LL * (A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y);
}

std::vector<int> convex_hull(std::vector<Point>& v){
	//for(auto& pt : v)std::cout << "( " << pt.x << ", " << pt.y << " )\n";
	std::vector<int> ans;
	ans.reserve(v.size());
	ans.push_back(0);
	ans.push_back(1);
	int next = 2;

	while (next < v.size()) {
        while (ans.size() >= 2) {
            int first, second;
            second = ans[ans.size()-1];
            ans.pop_back();
            first = ans[ans.size()-1];
 
            // first, second, next가 좌회전 ( > 0 )이라면 second push
            // 우회전( < 0 )이라면 위의 while문 계속 반복
            if (ccw(v[first], v[second], v[next]) > 0) {
                ans.push_back(second);
                break;
            }
        }
 
        // next push
        ans.push_back(next++);
    }
	return ans;
}


double dist(Point& p1, Point& p2, Point& p3){
	return std::abs((p2.y-p1.y)*p3.x - (p2.x-p1.x)*p3.y + (p2.x*p1.y - p1.x*p2.y)) / std::sqrt((p2.y-p1.y)*(p2.y-p1.y) + (p2.x-p1.x)*(p2.x-p1.x));
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int N;
	int idx=0;
	int x,y;
	while(std::cin >> N){
		if(N==0) break;
		std::vector<Point> v;
		v.reserve(N);
		Point p;
		for(int i=0;i<N;++i){
			std::cin >> x >> y;
			v.emplace_back(x,y);
		}

		std::sort(v.begin(),v.end(),comp);
		for (int i = 1; i < v.size(); i++) {
			v[i].p = v[i].x - v[0].x;
			v[i].q = v[i].y - v[0].y;
		}
		std::sort(v.begin()+1,v.end(),comp);

		// Do Something
		std::vector<Point> hull;
		hull.reserve(N);
		for(auto& pt : convex_hull(v)){
			hull.push_back(v[pt]);
			//std::cout << "( " << v[pt].x << ", " << v[pt].y << " )\n";
		}

		std::vector<double> ans;
		ans.reserve(v.size());
		for(int first=0;first<hull.size();first++){
			std::vector<double> temp;
			temp.reserve(hull.size());
			int second;
			if(first==hull.size()-1) second = 0;
			else second = first+1;

			for(auto& third : hull){
				temp.push_back(dist(hull[first],hull[second],third));
			}
			ans.push_back(*std::max_element(temp.begin(),temp.end()));
		}
		
		std::cout << std::fixed;
		std::cout.precision(2);
		std::cout << "Case " << (++idx) << ": " << std::ceil(*std::min_element(ans.begin(),ans.end())*100)/100 << '\n';
	}
	return 0;
}