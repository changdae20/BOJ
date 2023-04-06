#include <iostream>
#include <deque>
#define endl "\n"

int main(void){
    std::ios_base::sync_with_stdio(NULL);
    std::cin.tie(NULL);

    int N,L;
    std::cin>>N>>L;
    std::deque<std::pair<int, int>> arr;


    for(int i=0;i<N;i++){
        int num;
        std::cin>>num;
        if(!arr.empty() && arr[0].second <= i-L) arr.pop_front();
        while(!arr.empty() && arr[arr.size()-1].first>num) arr.pop_back();
        arr.push_back(std::make_pair(num,i));
        std::cout<<arr[0].first<<" ";
    }
    return 0;
}