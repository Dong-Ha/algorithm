#include <iostream>
using namespace std;
int N;
int count = 0;

void change(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    cin >> N;
    int *arr = new int[N];

    for(int i=0; i<N;i++){
        cin >> arr[i];
    }

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(arr[i]>arr[j])change(arr[i],arr[j]);
        }
    }

    for(int i=0; i<N;i++){
        cout << arr[i] << '\n';
    }

    delete arr;
    return 0;
}