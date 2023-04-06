#include <bits/stdc++.h>

int main(int argc, char** argv){
    long long a,b;
    std::cin >> a >> b;

    std::vector<bool> v(b-a+1,true);

    for( long long i=2; i*i<(b+1); ++i){
        for( long long j=(((a-1)/(i*i))+1)*i*i;j<=b;j+=i*i){
            v[j-a] = false;
        }
    }

    std::cout << std::count(v.begin(),v.end(),true) << std::endl;
    return 0;
}