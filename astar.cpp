#include <iostream>
using namespace std;
int Map[5][5]={ {1,1,1,1,1},   // 1 open , 0 close
                {1,1,1,1,1},
                {1,1,0,1,1},
                {1,1,1,1,1},
                {1,1,1,1,1}};

typedef struct node {
    bool visited = false;
    int parent_pos_y = -1, parent_pos_x = -1;
    int pos_y, pos_x;

    int f=100000,g=0,h=100000;
} NODE;

NODE List[5][5] = {0,};

NODE PATH[25]={0,};

int dst_y=4, dst_x=4;
int start_y=0, start_x=0;

int dy[4] = {0, 1, 0, -1}; //우 하 좌 상
int dx[4] = {1, 0, -1, 0};

void aStar(){
    int now_y = start_y;
    int now_x = start_x;
    
    List[now_y][now_x].visited = true;

    while( ((now_y != dst_y) || (now_x != dst_x)) ){
        
    for(int i=0;i<4;i++){
        if( (now_y+dy[i]<0) || (now_y+dy[i]>4) || (now_x+dx[i]<0) || (now_x+dx[i]>4)) continue;
        if( Map[now_y+dy[i]][now_x+dx[i]] == 0 ) continue;

        int temp_g = List[now_y+dy[i]][now_x+dx[i]].g + 1;
        int temp_h = (now_y+dy[i] - dst_y)*(now_y+dy[i] - dst_y) + (now_x+dx[i] - dst_x)*(now_x+dx[i] - dst_x);
        int temp_f = temp_g + temp_h;

        if(temp_f < List[now_y+dy[i]][now_x+dx[i]].f){
            List[now_y+dy[i]][now_x+dx[i]].f = temp_f;
            List[now_y+dy[i]][now_x+dx[i]].g = temp_g;
            List[now_y+dy[i]][now_x+dx[i]].h = temp_h;
            List[now_y+dy[i]][now_x+dx[i]].parent_pos_x = now_x;
            List[now_y+dy[i]][now_x+dx[i]].parent_pos_y = now_y;
            
        }
    }

    int min=100000;

    for(int j=0;j<5;j++){
        for(int i=0;i<5;i++){
            if(List[j][i].visited == true) continue;
            if(List[j][i].f < min ){
                min = List[j][i].f;
                now_y = j;
                now_x = i;
            }
        }
    }

    List[now_y][now_x].visited = true;
    
    }


    while((now_y != start_y) || (now_x != start_x)){
        cout << List[now_y][now_x].pos_y << " " << List[now_y][now_x].pos_x << '\n';
        now_y = List[now_y][now_x].parent_pos_y;
        now_x = List[now_y][now_x].parent_pos_x;
    }

}

int main(){
    for(int i=0;i<5;i++){
        for(int j=0; j<5; j++){
            List[j][i].pos_x = i;
            List[j][i].pos_y = j;
        }
    }
    
    aStar();

    return 0;
}