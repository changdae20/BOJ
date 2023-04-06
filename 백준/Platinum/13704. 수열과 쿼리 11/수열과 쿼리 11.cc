#include <bits/stdc++.h>

std::vector<unsigned long long> v( 100001, 0 ); // 누적 XOR값 저장
std::vector<unsigned long long> count( 1<<21, 0 ); // 누적 XOR값의 개수 저장 [current_l-1, current_r] 까지 저장함.

unsigned long long current_l = 0, current_r = 0;
unsigned long long ans = 0;
unsigned long long K;


class Query{
    public:
    int l, r, idx;
    Query( int l, int r, int idx ) : l(l), r(r), idx(idx) {}
    bool operator < ( const Query &other ) const{
        if( r / 316 != other.r / 316 ) return r / 316 < other.r / 316;
        return l < other.l;
    }

    unsigned long long run(){
        while( current_l > l ){ // add
            current_l -- ;
            count[ v[current_l] ]++;
            ans += count[ K ^ v[current_l-1] ];
        }
        while( current_r < r ) { // add
            current_r ++ ;
            ans += count[ K ^ v[current_r] ];
            ans += v[current_l-1] == (K^v[current_r]);
            count[ v[current_r] ]++;
        }
        while( current_l < l ){ // remove
            ans -= count[ K ^ v[current_l-1] ];
            count[ v[current_l] ]--;
            current_l ++ ;
        }
        while( current_r > r ){ // remove
            count[ v[current_r] ]--;
            ans -= count[ K ^ v[current_r] ];
            ans -= v[current_l-1] == (K^v[current_r]);
            current_r-- ;
        }
        return ans;
    }
};

int main( int argc, char *argv[] ) {
    std::cin.tie( 0 );
    std::ios::sync_with_stdio( false );
    std::cout.tie( 0 );
#ifndef BOJ
    freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout);
#endif

    int N, Q, l, r;
    std::cin >> N >> K;

    for( unsigned long long i = 1; i <= N; ++i ){
        std::cin >> v[i];
        v[i] ^= v[i-1];
    }

    current_l = current_r = 1;
    count[ v[current_l] ] = 1;
    if( v[1] == K ) ans++;

    std::cin >> Q;

    std::vector<Query> queries;
    queries.reserve(Q);

    for( unsigned long long i = 0; i < Q; ++i ){
        std::cin >> l >> r;
        queries.push_back(Query( l, r, i ));
    }

    std::sort( queries.begin(), queries.end(), std::less<>() );

    std::vector<unsigned long long> answer( Q );

    for( auto &q : queries ){
        answer[q.idx] = q.run();
    }

    for( auto &a : answer ){
        std::cout << a << '\n';
    }

    return 0;
}