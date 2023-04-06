#include <bits/stdc++.h>

void go(const double &d, double &x1, double &y1, const double &x2, const double &y2){ // move (x1, y1) towards (x2, y2)
    double dx = x2 - x1;
    double dy = y2 - y1;
    double size = std::sqrt(dx*dx + dy*dy);
    x1 += d*dx/size;
    y1 += d*dy/size;
    return;
}

bool catchable(const double& d, const double &x1, const double &y1, const double &x2, const double &y2){
    return std::sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)) <= (d+1);
}

int main( int argc, char *argv[] ) {
    std::cin.tie( 0 );
    std::ios::sync_with_stdio( false );
    std::cout.tie( 0 );
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif
    int N = 0;
    
    double d, x1, y1;

    std::cin >> d >> x1 >> y1;

    while(d != 0.0){
        int xx, yy;
        std::vector<std::pair<int, int>> firefly_coordinates;
        bool catched = false;
        do{
            std::cin >> xx >> yy;
            if(xx!=-1 && yy!=-1) firefly_coordinates.push_back(std::pair(xx,yy));
        }while(xx!=-1 && yy!=-1);

        for(auto &[x2, y2] : firefly_coordinates){
            double x2_d = static_cast<double>(x2);
            double y2_d = static_cast<double>(y2);
            if(catchable(d, x1,y1,x2_d,y2_d)){
                catched = true;
                std::cout << "Firefly " << ++N << " caught at (" << x2 << "," << y2 << ")\n"; 
                break;
            }
            // std::cout << "Teleporting (" << x1 << ", " << y1 << ") to ";
            go(d, x1,y1, x2_d, y2_d);
            // std::cout << "(" << x1 << ", " << y1 << "), goal : (" << x2_d << ", " << y2_d << ")\n";
        }


        if(!catched){
            std::cout << "Firefly " << ++N << " not caught\n";
        }

        std::cin >> d >> x1 >> y1;
    }

    return 0;
}