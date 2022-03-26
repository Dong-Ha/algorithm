#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, x, y, cnt=0;
    int arr[50];
    int rank[50];
    vector <pair<int,int>> v;
    vector <pair<int,int>> height;
    cin >> N;

    for(int i=0;i<N;i++)
    {
        cin >> x >> y;
        v.push_back( pair<int,int>( x,i ) );
        height.push_back( pair<int,int>( y,0 ) );
        //arr[i] = y;
        //cout << "arr["<< i <<"][0] : " << x << " & arr["<< i <<"][1] : " << y << endl;
    }

    sort(v.begin(), v.end());

    height[ v[N-1].second ].second = 1;
    for(int i=N-1;i>0;i--)
    {
        if(height[i].first == v[N-1].first) 
        {
            height[ i ].second = 1;
        }
    }
    //rank[N-1] = 1;

    for(int i=N-1;i>0;i--)
    {
        
            if(  height[ v[i].second ].first > height[ v[i-1].second ].first  ) 
            {
                if(v[i].first > v[i-1].first) 
                {
                    if(height[ v[i-1].second ].second != 1)
                    {
                        height[ v[i-1].second ].second = height[ v[i].second ].second +cnt+1;//rank[i-1] = rank[i]+cnt+1;
                    }
                }
                else 
                {
                    if(height[ v[i-1].second ].second != 1)
                    {
                        height[ v[i-1].second ].second = height[ v[i].second ].second;
                        //rank[i-1] = rank[i];
                        cnt++;
                    }
                }
            }
            else 
            {
                if(height[ v[i-1].second ].second != 1)
                {
                    height[ v[i-1].second ].second = height[ v[i].second ].second;
                    //rank[i-1] = rank[i];
                    cnt++;
                }
            }
        
    }

    for(int i=0;i<N;i++)
    {
        cout << height[i].second << " ";
    }

    return 0;
}
