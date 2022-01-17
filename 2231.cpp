#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int N, target, temp=0, M=0, i=0, memory;
    cin >> N;
    target = N;

for(; i!=N; i++){
    memory = i;
    temp = i;
    while(i/10 != 0){
            temp += i%10;
            i /=10;
        }
        temp += i%10;
        
    i = memory;

    if(temp == N) break;
}


if(temp == N) cout << i;
else cout << 0;


    return 0;
}