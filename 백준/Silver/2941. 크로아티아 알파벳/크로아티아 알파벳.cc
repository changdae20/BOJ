#include <bits/stdc++.h>

int main(){
    #ifndef BOJ
    freopen("input.txt", "r",stdin);
    #endif

    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    int ans = 0;
    for(int i=0; i<s.size(); ++i){
        if(s.size()-i>=3 and s[i]=='d' and s[i+1]=='z' and s[i+2]=='=') i+=2;
        else if(s.size()-i>=2 and s[i]=='c' and s[i+1]=='=') i+=1;
        else if(s.size()-i>=2 and s[i]=='c' and s[i+1]=='-') i+=1;
        else if(s.size()-i>=2 and s[i]=='d' and s[i+1]=='-') i+=1;
        else if(s.size()-i>=2 and s[i]=='l' and s[i+1]=='j') i+=1;
        else if(s.size()-i>=2 and s[i]=='n' and s[i+1]=='j') i+=1;
        else if(s.size()-i>=2 and s[i]=='s' and s[i+1]=='=') i+=1;
        else if(s.size()-i>=2 and s[i]=='z' and s[i+1]=='=') i+=1;

        ++ans;
    }
    std::cout << ans << std::endl;
    return 0;
}