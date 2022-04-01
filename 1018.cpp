#include <iostream>
#include <cstdio>
using namespace std;
/*
void ChessField_WB(int i, int j, int &ref, char **arr)
{
    int min1 = 0,min2=0;
    for(int N1 = i; N1<i+8; N1++)
    {
        for(int M1 = j; M1<j+8; M1++)
        {
            if((N1+M1)%2 == 0 & arr[N1][M1] == 'B' ) min1++;
            if((N1+M1)%2 == 1 & arr[N1][M1] == 'W' ) min1++;

            if((N1+M1)%2 == 0 & arr[N1][M1] == 'W' ) min2++;
            if((N1+M1)%2 == 1 & arr[N1][M1] == 'B' ) min2++;
        }
    }
    if(ref > min1) ref = min1;
    if(ref > min2) ref = min2;
}*/


int main()
{
    int num=65, M, N;

    cin >> N >> M;
    char **arr = new char* [N];

    for(int i=0; i<N;i++) arr[i] = new char[M];

    for(int i=0; i<N;i++)
    {
        for(int j=0; j<M;j++)
        {
            cin >> arr[i][j];
        }
    }
    
    cout << endl;
    for(int i=N-8; i>=0; i--)
    {
        for(int j=M-8; j>=0; j--)
        {
            int min1 = 0,min2=0;
            for(int N1 = i; N1<i+8; N1++)
            {
                for(int M1 = j; M1<j+8; M1++)
                {
                    if((N1+M1)%2 == 0){if(arr[N1][M1] == 'B' ) min1++;}
                    if((N1+M1)%2 == 1){if( arr[N1][M1] == 'W' ) min1++;}

                    if((N1+M1)%2 == 0){if( arr[N1][M1] == 'W' ) min2++;}
                    if((N1+M1)%2 == 1){if( arr[N1][M1] == 'B' ) min2++;}
                }
            }
            if(num > min1) num = min1;
            if(num > min2) num = min2;

        }
    }

    //cout << min;
    cout << num;

    for(int i=0; i<M; M++)delete[] arr[i];
    delete[] arr;
    return 0;
}


