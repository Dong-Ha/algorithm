#include <iostream> //https://shoark7.github.io/programming/algorithm/tower-of-hanoi
#include <cstdio>  
using namespace std;

void hanoi(int N, int start, int destination, int via){
    if(N==1){
        printf("%d %d\n",start,destination);
    }
    else{
        hanoi(N-1,start,via,destination);

        printf("%d %d\n",start, destination);

        hanoi(N-1,via,destination,start);
    }
}

int main(){
    int N;

    cin >> N;
    cout << (1<<N)-1 << endl;


    hanoi(N,1,3,2);

    return 0;
}