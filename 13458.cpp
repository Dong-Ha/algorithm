#include <iostream>
using namespace std;

int main()
{
    long long N; 
    int B,C;
    long long num=0;
    cin >> N;

    int *A = new int[N];

    for(int i=0; i<N;i++)
    {
        cin >> A[i];
    }

    cin >> B >> C;


    for(int i=0; i<N;i++)
    {
        A[i] -= B;
        num++;
        if(A[i]>0)
        {
            num += A[i]/C;

            if(A[i]%C) num +=1;
        }
    }

    cout << num;

    delete[] A;
    return 0;
}