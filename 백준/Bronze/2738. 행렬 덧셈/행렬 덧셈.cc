#include <iostream>
#include <vector>

int main(){
    #ifndef BOJ
    freopen("input.txt", "r", stdin);
    #endif
    
    int N,M;
    std::cin >> N >> M;

    // vector A
    std::vector<int> A(N*M);
    for(int i=0;i<N*M;i++){
        std::cin >> A[i];
    }

    // vector B
    std::vector<int> B(N*M);
    for(int i=0;i<N*M;i++){
        std::cin >> B[i];
    }

    // add A+B and print with newline at Mth element
    for(int i=0; i < N; i++){
        for(int j=0; j < M; j++){
            std::cout << A[i*M+j] + B[i*M+j] << (j!=M-1 ? " " : "");
        }
        std::cout << std::endl;
    }
}