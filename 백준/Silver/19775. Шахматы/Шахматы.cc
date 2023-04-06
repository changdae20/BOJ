#include <bits/stdc++.h>

int main(){
int N;
std::cin >> N;
std::vector<int> v(N,0);
for(int i=0;i<N;++i){
std::cin>>v[i];
}
int ans=1;
while(ans<N && (ans+1)<=v[ans]) ans++;
std::cout << ans << std::endl;
for(int i=1; i<=ans;++i){
std::cout<< i << " " << i << '\n';
}
return 0;
}