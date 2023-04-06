#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

int d;

struct Point{
	int x;
	int y;
	int idx;
};

int distpow(const Point& pt1, const Point& pt2){
	return (pt1.x-pt2.x)*(pt1.x-pt2.x) + (pt1.y-pt2.y)*(pt1.y-pt2.y);
}

bool ccw(const Point& pt1, const Point& pt2, const Point& pt3){
    int dx1 = pt2.x - pt1.x;
    int dy1 = pt2.y - pt1.y;
    int dx2 = pt3.x - pt2.x;
    int dy2 = pt3.y - pt2.y;

    return (dx1*dy2 - dx2*dy1) > 0;
}

bool operator==(Point pt1, const Point pt2){
	return pt1.x==pt2.x && pt1.y==pt2.y && pt1.idx==pt2.idx;
}

std::vector<Point> max_include(std::vector<Point>& points, Point& pt1, Point& pt2){ // 이거 하나가 
	auto d2 = distpow(pt1, pt2);
	std::vector<Point> Poi;

	// pt1, pt2를 farthest-point로 하는 set을 만들건데, 그렇기 때문에 pt1와 pt2까지의 거리가 pt1-pt2거리보다 짧은 점들만 일단 모아본다.
	// 이때 모아진 점들은 ()와 같은 바운더리 안에 들어오게 된다.
	std::copy_if(points.begin(), points.end(), std::back_inserter(Poi), [&pt1, &pt2, d2](auto& pt){
		return (distpow(pt,pt1)<=d2) && (distpow(pt,pt2)<=d2);
	});
	std::vector<Point> answer;
	// ROI안의 모든점과 무조건 통신이 되는 공동경비구역이 있다.()모양 중간에 ()를 90도 회전시킨 모양으로 조그맣게 생김
	std::copy_if(Poi.begin(), Poi.end(), std::back_inserter(answer), [&Poi](auto& pt){
		return std::all_of(Poi.begin(), Poi.end(), [&pt](auto& pt2){return distpow(pt,pt2)<=d;});
	});
	// 위에서 answer에 추가한건 지워줌 (remove - erase 패턴)
	auto it = std::remove_if(Poi.begin(), Poi.end(), [&answer](Point pt){
		return std::find(answer.begin(), answer.end(), Point{pt.x, pt.y, pt.idx}) != answer.end();
	});
	Poi.erase(it, Poi.end());
	// 이제 Poi에는 공동경비구역 이외의 점들만 남게되는데, 이 점들은 결국 pt1 - pt2를 잇는 선을 기준으로 나뉨. 지들끼린 다 연결됨.
	// 그건 이제 ccw를 통해서 pt1 - pt2를 잇는 선을 기준으로 어느쪽에 있는지 계산할 수 있다.
	std::vector<Point> up;
	std::copy_if(Poi.begin(), Poi.end(), std::back_inserter(up), [&pt1, &pt2](auto& pt){
		return ccw(pt1,pt2,pt);
	});

	std::vector<Point> down;
	std::copy_if(Poi.begin(), Poi.end(), std::back_inserter(down), [&pt1, &pt2](auto& pt){
		return !ccw(pt1,pt2,pt);
	});
	// 많은쪽 따라가기 때문에 많은걸 answer에 넣어주면 끝!
	if(up.size() > down.size()){
		answer.insert(answer.end(), up.begin(), up.end());
		// 마지막 발악으로 혹~시 down중에서 answer들과 compatible한게 있는지?
		std::vector<Point> erased;
		for(auto& residue : down){
			if(std::all_of(answer.begin(), answer.end(), [&residue](auto& pt){
				return distpow(residue, pt) <= d;
			})){
				answer.push_back(residue);
				erased.push_back(residue);
			}
		}
		for(auto& erased_ : erased) down.erase(std::find(down.begin(), down.end(),erased_));

		// 찐찐찐막으로 여러개점이 한개의 incompatible한점을 공유한다면?
		std::vector<std::vector<int>> v(101, std::vector<int>());
		for(auto& residue : down){
			if(std::count_if(answer.begin(), answer.end(), [residue](auto& ans){return distpow(residue, ans)>d;}) > 1) continue;
			for(auto& ans : answer){
				if(distpow(residue, ans)>d){
					v[ans.idx].push_back(residue.idx);
				}
			}
		}
		auto it = std::find_if(v.begin(), v.end(), [](auto& el){return el.size()>1;});
		if(it!=v.end()){ // 놀랍게도 한점을 지우고 두점을 넣을 수 있답니다,,
			answer.erase(std::find(answer.begin(), answer.end(), points[std::distance(v.begin(), it)-1]));
			for(auto& new_pt_idx : *it){
				answer.push_back(points[new_pt_idx-1]);
			}
		}
	}else{
		answer.insert(answer.end(), down.begin(), down.end());
		// 마지막 발악으로 혹~시 up중에서 answer들과 compatible한게 있는지?
		std::vector<Point> erased;
		for(auto& residue : up){
			if(std::all_of(answer.begin(), answer.end(), [&residue](auto& pt){
				return distpow(residue, pt) <= d;
			})){
				answer.push_back(residue);
				erased.push_back(residue);
			}
		}
		for(auto& erased_ : erased) up.erase(std::find(up.begin(), up.end(),erased_));

		// 찐찐찐막으로 여러개점이 한개의 incompatible한점을 공유한다면?
		std::vector<std::vector<int>> v(101, std::vector<int>());
		for(auto& residue : up){
			if(std::count_if(answer.begin(), answer.end(), [residue](auto& ans){return distpow(residue, ans)>d;}) > 1) continue;
			for(auto& ans : answer){
				if(distpow(residue, ans)>d){
					v[ans.idx].push_back(residue.idx);
				}
			}
		}
		auto it = std::find_if(v.begin(), v.end(), [](auto& el){return el.size()>1;});
		if(it!=v.end()){ // 놀랍게도 한점을 지우고 두점을 넣을 수 있답니다,,
			answer.erase(std::find(answer.begin(), answer.end(), points[std::distance(v.begin(), it)-1]));
			for(auto& new_pt_idx : *it){
				answer.push_back(points[new_pt_idx-1]);
			}
		}
	}

	return answer;
}

int main(int argc, char* argv[]) {
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif
    fastio;
	int N;
	int idx = 0;
	std::cin >> N >> d;
	d *= d;
	std::vector<Point> points(N);
	for(auto& pt : points){
		std::cin >> pt.x >> pt.y;
		pt.idx = ++idx;
	}
	std::vector<Point> ans = {points[0]};
	for(int i=0; i<N-1;++i){
		for(int j=i+1; j<N;++j){
			if(distpow(points[i], points[j]) > d) continue;
			auto temp = max_include(points, points[i], points[j]);
			if(temp.size() > ans.size()){
				ans = std::move(temp);
			}
		}
	}

	std::cout << ans.size() << '\n';
	for(auto& pt : ans){
		std::cout << pt.idx << ' ';
	}
	std::cout << '\n';
    return 0;
}