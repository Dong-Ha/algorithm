#include <iostream>
using namespace std;

int main()
{
    int N, now=0, max=0, ref=0, target=0; // ref현재까지 금액 총합,  target 현재위치
    cin >> N;
    int **arr = new int*[N];
    for(int i=0;i<N;i++) arr[i] = new int[2];
    int *select = new int[N];

    for(int i=0;i<N;i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }

    while(now==N)
    {
        for(int i=0; i<N;i++)
        {
            
        }


        now++;
    }

    for(int i=0;i<N;i++) delete[] arr[i];
    delete[] arr;
    delete[] select;
    return 0;
}