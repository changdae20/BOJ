#include <bits/stdc++.h>

int main(int argc, char* argv[]) {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    
    long long x1, y1, x2, y2, x3, y3, x4, y4;

    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    long long A,B,C,D,E,F;

    A = y2-y1;
    B = x1-x2;
    C = y4-y3;
    D = x3-x4;
    E = (y2-y1)*x1 - (x2-x1)*y1;
    F = (y4-y3)*x3 - (x4-x3)*y3;
    if(A*D == B*C) { // 두 선분이 평행함.
        if(A!=0ll){
            if(A*F != C*E){ //두 선분이 평행하지만 y절편이 다름
                std::cout << "0\n";
            }else{ // 두 선분이 평행하고 y절편이 같음. x범위 살펴봐야함
                if(std::min(x1,x2)!=std::max(x1,x2) || std::min(x3,x4)!=std::max(x3,x4)){
                    if(std::min(x3,x4) == std::max(x1,x2)){
                        std::cout << "1\n";
                        if(std::min(x3,x4) == x3) std::cout << x3 << ' ' << y3<< '\n';
                        else std::cout << x4 << ' ' << y4<< '\n';
                    }else if(std::min(x1,x2) == std::max(x3,x4)){
                        std::cout << "1\n";
                        if(std::max(x3,x4) == x3) std::cout << x3 << ' ' << y3<< '\n';
                        else std::cout << x4 << ' ' << y4 << '\n';
                    }else if(std::min(x1,x2) <= std::min(x3,x4) && std::min(x3,x4) <= std::max(x1,x2) ){
                        std::cout << "1\n";
                    }else if(std::min(x3,x4) <= std::min(x1,x2) && std::min(x1,x2) <= std::max(x3,x4) ){
                        std::cout << "1\n";
                    }else{
                        std::cout << "0\n";
                    }
                }else{
                    if(std::min(y3,y4) == std::max(y1,y2)){
                        std::cout << "1\n";
                        if(std::min(y3,y4) == y3) std::cout << x3 << ' ' << y3<< '\n';
                        else std::cout << x4 << ' ' << y4<< '\n';
                    }else if(std::min(y1,y2) == std::max(y3,y4)){
                        std::cout << "1\n";
                        if(std::max(y3,y4) == y3) std::cout << x3 << ' ' << y3<< '\n';
                        else std::cout << x4 << ' ' << y4 << '\n';
                    }else if(std::min(y1,y2) <= std::min(y3,y4) && std::min(y3,y4) <= std::max(y1,y2) ){
                        std::cout << "1\n";
                    }else if(std::min(y3,y4) <= std::min(y1,y2) && std::min(y1,y2) <= std::max(y3,y4) ){
                        assert(false);
                        std::cout << "1\n";
                    }else{
                        std::cout << "0\n";
                    }
                }
            }
        }else{
            if(B*F != D*E){ //두 선분이 평행하지만 y절편이 다름
                std::cout << "0\n";
            }else{ // 두 선분이 평행하고 y절편이 같음. x범위 살펴봐야함
                if(std::min(y1,y2)!=std::max(y1,y2) || std::min(y3,y4)!=std::max(y3,y4)){
                    if(std::min(y3,y4) == std::max(y1,y2)){
                        std::cout << "1\n";
                        if(std::min(y3,y4) == y3) std::cout << x3 << ' ' << y3<< '\n';
                        else std::cout << x4 << ' ' << y4<< '\n';
                    }else if(std::min(y1,y2) == std::max(y3,y4)){
                        std::cout << "1\n";
                        if(std::max(y3,y4) == y3) std::cout << x3 << ' ' << y3<< '\n';
                        else std::cout << x4 << ' ' << y4 << '\n';
                    }else if(std::min(y1,y2) <= std::min(y3,y4) && std::min(y3,y4) <= std::max(y1,y2) ){
                        std::cout << "1\n";
                    }else if(std::min(y3,y4) <= std::min(y1,y2) && std::min(y1,y2) <= std::max(y3,y4) ){
                        std::cout << "1\n";
                    }else{
                        std::cout << "0\n";
                    }
                }else{
                    if(std::min(x3,x4) == std::max(x1,x2)){
                        std::cout << "1\n";
                        if(std::min(x3,x4) == x3) std::cout << x3 << ' ' << y3<< '\n';
                        else std::cout << x4 << ' ' << y4<< '\n';
                    }else if(std::min(x1,x2) == std::max(x3,x4)){
                        std::cout << "1\n";
                        if(std::max(x3,x4) == x3) std::cout << x3 << ' ' << y3<< '\n';
                        else std::cout << x4 << ' ' << y4 << '\n';
                    }else if(std::min(x1,x2) <= std::min(x3,x4) && std::min(x3,x4) <= std::max(x1,x2) ){
                        std::cout << "1\n";
                    }else if(std::min(x3,x4) <= std::min(x1,x2) && std::min(x1,x2) <= std::max(x3,x4) ){
                        std::cout << "1\n";
                    }else{
                        std::cout << "0\n";
                    }
                }
            }
        }
    }else{ // 두 선분의 기울기가 다름. 제 5공준에 의해 선분을 연장했을 때 무조건 한 점에서 만난다.
        long long det = A*D - B*C;
        long long x = E*D - B*F;
        long long y = A*F - C*E;

        if(det > 0){
            if( std::min(x1,x2) * det <= x && x<= std::max(x1,x2)*det && std::min(x3,x4) * det <= x && x<= std::max(x3,x4)*det &&
                std::min(y1,y2) * det <= y && y<= std::max(y1,y2)*det && std::min(y3,y4) * det <= y && y<= std::max(y3,y4)*det ){ // 교차함
                std::cout << std::fixed;
                std::cout.precision(10);
                std::cout << "1\n";
                std::cout << static_cast<long double>(x) / static_cast<long double>(det) << ' ' << static_cast<long double>(y) / static_cast<long double>(det) << '\n';
            }else{
                std::cout << "0\n";
            }
        }else{
            if( std::min(x1,x2) * det >= x && x>= std::max(x1,x2)*det && std::min(x3,x4) * det >= x && x>= std::max(x3,x4)*det &&
                std::min(y1,y2) * det >= y && y>= std::max(y1,y2)*det && std::min(y3,y4) * det >= y && y>= std::max(y3,y4)*det ){ // 교차함
                std::cout << std::fixed;
                std::cout.precision(10);
                std::cout << "1\n";
                std::cout << static_cast<long double>(x) / static_cast<long double>(det) << ' ' << static_cast<long double>(y) / static_cast<long double>(det) << '\n';
            }else{
                std::cout << "0\n";
            }
        }
    }
    return 0;
}