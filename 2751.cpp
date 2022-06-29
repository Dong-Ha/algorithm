#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int num, tmp;
    vector<int> a;
    cin >> num;
    for(int i=0; i<num; i++){
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(),a.end());
    for(int i=0; i<num; i++){
        cout <<a[i] << '\n';
    }

    return 0;
}