#include <iostream>

int facto(int N){
    if(N<=1) return 1;
    else return (N*facto(N-1));

}

int main(){
    int M(0);
    std::cin >> M;

    M = facto(M);

    std::cout << M;
    return 0;
}