#include <iostream>
#define Y_MAX 5
#define X_MAX 5
#define NOT_VISITED 0
#define OPEN_LIST 1
#define CLOSE_LIST 2
using namespace std;
int Map[Y_MAX][X_MAX]={ {1,1,0,1,0},   // 1 open , 0 close
                        {1,1,0,0,1},
                        {1,1,0,1,1},
                        {1,1,1,1,1},
                        {1,1,1,1,1}};

typedef struct node {
    char visited = NOT_VISITED;
    int parent_pos_y = -1, parent_pos_x = -1;
    int pos_y, pos_x;

    int f=100000,g=0,h=100000;
} NODE;

NODE List[Y_MAX][X_MAX] = {0,};

NODE PATH[Y_MAX*X_MAX]={0,};

int dst_y=4, dst_x=4;
int start_y=0, start_x=0;
int temp;

int dy[4] = {0, 1, 0, -1}; //우 하 좌 상
int dx[4] = {1, 0, -1, 0};

void aStar(){
    int now_y = start_y;
    int now_x = start_x;
    
    List[now_y][now_x].visited = CLOSE_LIST;

    while( ((now_y != dst_y) || (now_x != dst_x)) ){
        
    for(int i=0;i<4;i++){
        if( (now_y+dy[i]<0) || (now_y+dy[i]>=Y_MAX) || (now_x+dx[i]<0) || (now_x+dx[i]>=X_MAX)) continue;
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
            List[now_y+dy[i]][now_x+dx[i]].visited = OPEN_LIST;
        }
    }

    int min=100000;
/*
    for(int j=0;j<5;j++){
        for(int i=0;i<5;i++){
            
            if( (List[j][i].visited == OPEN_LIST) && (List[j][i].f < min )){
                min = List[j][i].f;
                now_y = j;
                now_x = i;
            }
        }
    }
*/
    for(int i=0;i<4;i++){
        if( (now_y+dy[i]<0) || (now_y+dy[i]>=Y_MAX) || (now_x+dx[i]<0) || (now_x+dx[i]>=X_MAX)) continue;
        if( (List[now_y+dy[i]][now_x+dx[i]].visited == OPEN_LIST) && (List[now_y+dy[i]][now_x+dx[i]].f < min )){
            min = List[now_y+dy[i]][now_x+dx[i]].f;
            now_y = now_y+dy[i];
            now_x = now_x+dx[i];
        }
    }
    List[now_y][now_x].visited = CLOSE_LIST;
    
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

    while( (dst_y != start_y) || (dst_x != start_x)) {
        cout << List[dst_y][dst_x].pos_y << " " << List[dst_y][dst_x].pos_x << '\n';
        temp  = List[dst_y][dst_x].parent_pos_y;
        dst_x = List[dst_y][dst_x].parent_pos_x;
        dst_y = temp;
    }

    
    return 0;
}