#include <iostream>
using namespace std;

void countingstar(int i, int j, int M) {
    if(1==(i/M)%3 && 1==(j/M)%3) cout << " ";
    else {
        if(M / 3 == 0) cout << "*";
        else countingstar(i,j,M/3);
    }

}

int main(){
    int M;
    cin >> M;
    for(int i=0; i<M;i++){
        for(int j=0; j<M;j++){
            countingstar(i,j,M);
        }

        if(i != M-1) cout << endl;
    }

    return 0;
}