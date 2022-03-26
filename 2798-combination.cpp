#include <iostream>
#include <cstdio>
using namespace std;
void Combination(int arr[],int n, int r, int index, int target, int comb_arr[], int M,int& output){
    int temp=0;
    if(r==0){
        for(int i=0; i<index;i++){
            temp += comb_arr[i];
        }
        // choice
        if(M>=temp && output<=temp){output = temp;}        
    }else if(target== n){
        return;

    }else{
        comb_arr[index] = arr[target];
        Combination(arr, n, r-1, index+1, target+1,comb_arr, M, output);
        Combination(arr, n, r,index, target+1,comb_arr, M, output);
    }
}

int main(){

    int N=0,M=0,output=0;
    cin >> N >> M;

    int* arr = new int[N];

    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }

    int* comb_arr = new int[N];

    Combination(arr,N,3,0,0,comb_arr, M, output);

    cout << output;

    return 0;
}





/*
void Combination(int arr[],int n, int r, int index, int target, int comb_arr[]){
    if(r==0){
        for(int i=0; i<index;i++){
            cout << comb_arr[i];
        }
        cout <<endl;
    }else if(target== n){
        return;

    }else{
        comb_arr[index] = arr[target];
        Combination(arr, n, r-1, index+1, target+1,comb_arr);
        Combination(arr, n, r,index, target+1,comb_arr);
    }
}
*/