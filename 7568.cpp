#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){

    int N;
    cin >> N;
    int arr[N][2];
    int rank[N];

    for(int k=0; k<N; k++)
    {
        cin >> arr[k][0] >> arr[k][1];
        rank[k] = 1;
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if( (arr[i][0] > arr[j][0]) & (arr[i][1] > arr[j][1]) )
            {
                rank[j]++;
            }
        }
    }

    for(int i=0; i<N; i++)
    {
        cout << rank[i] << " ";
    }


    return 0;
}