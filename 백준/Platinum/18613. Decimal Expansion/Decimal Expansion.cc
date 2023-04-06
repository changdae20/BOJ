#include <bits/stdc++.h>

// 오일러 오각수 정리에 의해서 1에서 시작해서 0.1의 거듭제곱이 - - + + - - + +의 순서로 나오는데, 이 -와 +가 자릿수에 따른 이차함수 형태가 된다.
// https://en.wikipedia.org/wiki/Pentagonal_number_theorem
// 즉, 이 문제에서 구하는 수는 x = 0.1로 뒀을 때
// 1 - x - x2 + x5 + x7 - x12 - x15 ... 의 형태이다.
enum class Term{ 
    MINUS_ONE,
    MINUS_TWO,
    PLUS_ONE,
    PLUS_TWO
};

// MINUS_ONE Term은 1, 12, ...
// MINUS_TWO Term은 2, 15, ...
// PLUS_ONE Term은 5, 22, ...
// PLUS_TWO Term은 7, 26, ...
long long calc_num(const long long k, Term t){
    switch(t){
        case Term::MINUS_ONE:
            return (2LL + (6LL * k * k ) - 7LL * k);
        case Term::MINUS_TWO:
            return (1LL + (6LL * k * k ) - 5LL * k);

        case Term::PLUS_ONE:
            return (6LL * k * k) - k;
        case Term::PLUS_TWO:
            return (6LL * k * k) + k;
    }
    assert(false);
    return 0LL;
}

long long binary_search( long long N, Term t ){
    long long l = 0;
    long long r = 410000000; // 4.1억번째 PLUS_TWO term이 10.08 * 10^18 정도라서 이 index안에는 모든 term이 포함됨.

    while(l+1<r){
        long long mid = calc_num( (l+r)/2LL, t );
        if(mid <= N) l = (l+r)/2LL;
        else r = ((l+r)/2LL);
    }

    return calc_num( l, t );
}

int ans(long long n){
    long long m1 = binary_search( n, Term::MINUS_ONE );
    long long m2 = binary_search( n, Term::MINUS_TWO );
    long long p1 = binary_search( n, Term::PLUS_ONE );
    long long p2 = binary_search( n, Term::PLUS_TWO );

    if( m1 == n ) return 8;
    if( m2 == n ) return 9;
    if( p1 == n ) return 1;
    if( p2 == n ) return 0;

    long long maxx = std::max<>({m1, m2, p1, p2});

    if( m1 == maxx ) return 9;
    if( m2 == maxx ) return 0;
    if( p1 == maxx ) return 0;
    if( p2 == maxx ) return 9;
    assert(false);
    return 0;
}

int main() {
    std::cin.tie( 0 );
    std::ios::sync_with_stdio( false );
    std::cout.tie( 0 );
    int T;
    long long n;
    std::cin >> T;
    while(T--){
        std::cin >> n;
        std::cout << ans(n) << (T ? " " : "");
    }
    std::cout << std::endl;
    return 0;
}