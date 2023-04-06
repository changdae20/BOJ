#include <numeric>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>

double ans(int n1, int m1, int n2, int m2){
    double s = 0.0;
    double a = 1.0;
    for(int i=0;i<=n2;i++){
        a *= static_cast<double>(n1-m1+i+1)/(n1+i+2);
    }
    s += a;
    for(int i=1;i<=m2;i++){
        s += (a *= static_cast<double>(m1+i)*(n2+2-i)/i/(n1+n2+2-m1-i));
    }
    return s;
}
int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
    int n1,m1,n2,m2;
    std::cin >> T;
    while(T--){
        std::cin >> n1 >> m1 >> n2 >> m2;
        std::cout << ans(n1,m1,n2,m2) << '\n';
    }
	return 0;
}