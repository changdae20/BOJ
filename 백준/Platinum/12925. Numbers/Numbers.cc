#include <iostream>
#include <cmath>

int get_pow(int num){
    int ans = 1;
    int temp = 4;
    while(num>0){
        if(num%2==1){
            ans = (ans * temp) % 1000;
        }
        temp = (temp * temp) % 1000;
        num /= 2;
    }
    return ans;
}

int calc(int num){
    if(num==0) return 2;
    else if(num==1) return 6;
    else if(num%2==0){
        int pre = calc(num/2);
        int ans = ((pre*pre) - (2*get_pow(num/2) )) % 1000;
        return ans>=0 ? ans : ans+1000;
    }else{
        int pre1 = calc(num/2);
        int pre2 = calc(num/2 + 1);
        int ans = ((pre1 * pre2) - (6*get_pow(num/2)))%1000;
        return ans>=0 ? ans : ans+1000;
    }
}
int main(void){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int Q;
    std::cin >> Q;
    for(int i=1;i<=Q;i++){
        int num;
        std::cin >> num;
        std::cout<<"Case #"<<i<<": ";
        std::cout.width(3);
        std::cout.fill('0');
        int ans = (calc(num)-1);
        std::cout<< (ans>0 ? ans : ans+1000) <<"\n";
        
    }
}