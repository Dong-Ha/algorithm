#include <iostream>
using namespace std;

void countingstar(int i, int j, int M){
    if(M != 3){
        if(1==i/3 && 1==j/3) cout << " ";
        else countingstar(i/3,j/3,M/3);
    } else{
        if((1==i%3 && 1==j%3)/*||(1==i/3&&1==j/3)*/) cout << " ";
        else cout << "*";
    }

}

int main(){
    int M;
    cout << "press number : ";
    cin >> M;
    for(int i=0; i<M;i++){
        for(int j=0; j<M;j++){
            countingstar(i,j,M);
        }

        cout << endl;
    }

    return 0;
}