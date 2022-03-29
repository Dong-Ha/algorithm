#include <iostream>
#include <cstdio>
using namespace std;

void ChessField_even(int i, int j, int &ref, char **arr)
{
    int min = 0;
    for(int N1 = i; N1<i+8; N1++)
    {
        for(int M1 = j; M1<j+8; M1++)
        {
            if( (N1+M1)%2 == 0 & arr[N1][M1] == 'B' ) min++; 
            cout << arr[N1][M1];
        }

        cout << endl;

        if(ref > min) ref = min;
        min = 0;
    }
    cout << endl;
}

int main()
{
    int num=10, M, N;
    int &min = num;

    cin >> N >> M;
    char **arr = new char* [N*M];
    for(int i=0; i<N;i++) arr[i] = new char[M];


    for(int i=0; i<N;i++)
    {
        for(int j=0; j<M;j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<N;i++)
    {
        for(int j=0; j<M;j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }


    for(int i=M-8; i>=0; i--)
    {
        for(int j=N-8; j>=0; j--)
        {
            //ChessField_even(i, j, min , arr);
        }
    }

    cout << min;

    for(int i=0; i<M; M++)delete[] arr[i];
    delete[] arr;
    return 0;
}


