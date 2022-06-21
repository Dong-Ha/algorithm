#include <iostream>

using namespace std;

int N, K,input,output,cnt,step=0;
int* belt; int* doll;

void belt_move(){
    if(input != 1) input--;
    else input = 2*N;

    if(output != 1) output--;
    else output = 2*N;
}

void olligi_naeligi(){
    if(belt[input] != 0) {
        doll[input]++;
        belt[input]--;
    }
    if(belt[output] != 0){
        doll[output]--;
    }
}

void robot_move(int var){
    if(var == 1){
        if( (doll[1] != 0)  & (belt[2*N] != 0) ){
            doll[1]--;
            doll[2*N]++;
            belt[2*N]--;
        }
    }
    else{
        if( (doll[var] != 0)  & (belt[var+1] != 0) ){
            doll[var]--;
            doll[var+1]++;
            belt[var+1]--;
        }
    }
    if(doll[output]) doll[output]--;
}

int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

cin >> N >> K;

belt = new int[N*2];
doll = new int[N*2];

for(int i=0; i<N*2; i++){
    cin >> belt[i];
    doll[i]=0;
}

input = 1;
output = N;

doll[input]++;
belt[input]--;

if(belt[input+1] != 0){
    doll[input]--;
    doll[input+1]++;
    belt[input+1]--;
}
while(1){
    step++;
    belt_move();
    olligi_naeligi();
    for(int i=0; i<N; i++) robot_move(i);

    for(int i=0; i<2*N; i++){
        if(belt[i]==0) cnt++;
    }
    if(cnt == K)break;
    cnt = 0;
}
cout << step;


    delete[] belt;
    delete[] doll;
    return 0;
}