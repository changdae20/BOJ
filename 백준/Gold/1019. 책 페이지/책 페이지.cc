#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio( false );std::cin.tie( NULL );std::cout.tie( NULL );

constexpr void count_digit(std::array<unsigned long long, 10>& arr, int N) noexcept{
    while(N){
        ++arr[N%10];
        N /= 10;
    }
    return;
}

int main( int argc, char *argv[] ) {
#ifndef BOJ
    freopen( argv[ 1 ], "r", stdin );
#endif
    fastio;

    int N;
    std::cin >> N;
    std::map<int, std::array<unsigned long long, 10>> m;
    m[50000000] = {33888896, 45000000, 45000000, 45000000, 45000000, 35000001, 35000000, 35000000, 35000000, 35000000};
    m[100000000] = {68888897, 80000001, 80000000, 80000000, 80000000, 80000000, 80000000, 80000000, 80000000, 80000000};
    m[150000000] = {113888896, 175000001, 125000000, 125000000, 125000000, 115000001, 115000000, 115000000, 115000000, 115000000};
    m[200000000] = {148888897, 260000000, 160000001, 160000000, 160000000, 160000000, 160000000, 160000000, 160000000, 160000000};
    m[250000000] = {193888896, 305000000, 255000001, 205000000, 205000000, 195000001, 195000000, 195000000, 195000000, 195000000};
    m[300000000] = {228888897, 340000000, 340000000, 240000001, 240000000, 240000000, 240000000, 240000000, 240000000, 240000000};
    m[350000000] = {273888896, 385000000, 385000000, 335000001, 285000000, 275000001, 275000000, 275000000, 275000000, 275000000};
    m[400000000] = {308888897, 420000000, 420000000, 420000000, 320000001, 320000000, 320000000, 320000000, 320000000, 320000000};
    m[450000000] = {353888896, 465000000, 465000000, 465000000, 415000001, 355000001, 355000000, 355000000, 355000000, 355000000};
    m[500000000] = {388888897, 500000000, 500000000, 500000000, 500000000, 400000001, 400000000, 400000000, 400000000, 400000000};
    m[550000000] = {433888896, 545000000, 545000000, 545000000, 545000000, 485000002, 435000000, 435000000, 435000000, 435000000};
    m[600000000] = {468888897, 580000000, 580000000, 580000000, 580000000, 580000000, 480000001, 480000000, 480000000, 480000000};
    m[650000000] = {513888896, 625000000, 625000000, 625000000, 625000000, 615000001, 565000001, 515000000, 515000000, 515000000};
    m[700000000] = {548888897, 660000000, 660000000, 660000000, 660000000, 660000000, 660000000, 560000001, 560000000, 560000000};
    m[750000000] = {593888896, 705000000, 705000000, 705000000, 705000000, 695000001, 695000000, 645000001, 595000000, 595000000};
    m[800000000] = {628888897, 740000000, 740000000, 740000000, 740000000, 740000000, 740000000, 740000000, 640000001, 640000000};
    m[850000000] = {673888896, 785000000, 785000000, 785000000, 785000000, 775000001, 775000000, 775000000, 725000001, 675000000};
    m[900000000] = {708888897, 820000000, 820000000, 820000000, 820000000, 820000000, 820000000, 820000000, 820000000, 720000001};
    m[950000000] = {753888896, 865000000, 865000000, 865000000, 865000000, 855000001, 855000000, 855000000, 855000000, 805000001};
    m[1000000000] = {788888898, 900000001, 900000000, 900000000, 900000000, 900000000, 900000000, 900000000, 900000000, 900000000};

    int start = N - N%50000000;
    auto arr = m[start];

    for(int i = start+1; i<=N; ++i){
        count_digit(arr, i);
    }

    for(auto& el : arr) std::cout << el << ' ';
    std::cout << std::endl;
    return 0;
}