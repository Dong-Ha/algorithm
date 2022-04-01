#include <iostream>
using namespace std;

int main()
{
    int number=0, now=0, overlap=0, cnt=0, N=0,M=0;

    cin >> N;

    while(M != N)
    {
        now = number;
        cnt = 0;
        overlap = 0;
        while((now/10) | (now%10))
        {
            if(6 == now%10){cnt++;overlap++;}
            if(6 != now%10)overlap=0;
            if(3 == overlap){M++;break;}

            now /= 10;
        }


        number++;
    }

    cout << number-1;

    return 0;
}