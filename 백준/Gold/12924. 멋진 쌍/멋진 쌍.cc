#include <bits/stdc++.h>

int pow_ten[7] = {1,10,100,1000,10000,100000,1000000};
int get_digit(int N){
    if(N==0) return 0;
    else return get_digit(N/10) + 1;
}

int count_good(int N, int M, int digit){
    if(digit == 1) return 0;

    int count = 0;

    std::set<int> s;
    for(int i=1; i<digit;++i){
        int front = N / pow_ten[i];
        int back = N % pow_ten[i];

        int new_one = (back * pow_ten[digit-i] + front);
        if( N < new_one && new_one <= M && s.count(new_one)==0){
            ++count;
            s.insert(new_one);
        }
    }
    return count;
}

int main(int argc, char* argv[]){
    #ifndef BOJ
    freopen(argv[1], "r", stdin);
    #endif

    int N, M;
    std::cin >> N >> M;
    int digits = get_digit(N);
    int count = 0;
    for(int x = N; x < M; ++x){
        count += count_good(x, M, digits);
    }
    std::cout << count << std::endl;
    return 0;
}