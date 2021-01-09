#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>

#define rep(i,n)    for(int i=0; i<(int)n; i++)

const int BOARD_ROW = 10;
const int BOARD_COLUMNS = 10;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct BOARD{
    struct BOARD *next;
    struct BOARD *back;
    char board[BOARD_ROW][BOARD_COLUMNS];
    int peg_num;
    int depth;
    double f;
    bool operator< (const BOARD &b0) const {
        return f < b0.f;
    }
};

struct BOARD BS = { // board start
    NULL, NULL,
    {
        // {0, 0, 0, 0, 0},
        // {0, 0, 0, 0, 0},
        // {0, 0, 0, 0, 0},
        // {1, 1, 1, 1, 1},
        // {0, 0, 1, 0, 0},
        // {0, 0, 1, 0, 0},
        // {0, 0, 1, 0, 0},

        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    },
};

struct BOARD BG = { // board goal
    NULL, NULL,
    {
        // {0, 0, 1, 0, 0},
        // {0, 0, 0, 0, 0},
        // {0, 0, 0, 0, 0},
        // {0, 0, 0, 0, 0},
        // {0, 0, 0, 0, 0},
        // {0, 0, 0, 0, 0},
        // {0, 0, 0, 0, 0},

        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    },
};

typedef std::pair<double, BOARD> pdB;
#define mp(a,b) std::make_pair(a,b)

void printboard(struct BOARD *b);

int main(int argc, char *argv[]){
    printf("Initial state is \n");
    printboard(&BS);
    printf("Goal state is \n");
    printboard(&BG);

    int num_BS = 0, num_BG = 0;
    int BG_y, BG_x;
    rep(i, BOARD_ROW) rep(j, BOARD_COLUMNS){
        if(BS.board[i][j] == 1) num_BS++;
        if(BG.board[i][j] == 1){
            num_BG++;
            BG_y = i;
            BG_x = j;
        }
    }
    BS.peg_num = num_BS;
    BG.peg_num = num_BG;

    BS.f = BS.depth = 0;

    std::priority_queue<pdB> que;
    que.push( mp(0,BS));
    long search_counter = 0;
    while(!que.empty()){
        search_counter++;
        BOARD B_now = que.top().second; que.pop();
        // printf("counter = %d, f= %f, peg_num = %d\n", search_counter, B_now.f, B_now.peg_num);
        // printboard(&B_now);

        bool goal_flag = 1;
        rep(i, BOARD_ROW) rep(j, BOARD_COLUMNS){
            if(BG.board[i][j] != B_now.board[i][j]) goal_flag = 0;
            if(B_now.board[i][j] == 1){
                rep(k,4){
                    int tmp_y = i + dy[k]*2;
                    int tmp_x = j + dx[k]*2;
                    // printf("y = %d, x = %d, tmp_y = %d, tmp_x = %d\n", i, j, tmp_y, tmp_x);
                    if(tmp_y < 0 || BOARD_ROW <= tmp_y || tmp_x < 0 || BOARD_COLUMNS <= tmp_x) continue; // 移動先もボード内か確認
                    if(B_now.board[tmp_y][tmp_x] == 1 || B_now.board[tmp_y - dy[k]][tmp_x - dx[k]] == 0) continue; // 隣に石があり、飛んだ先が空いてるか確認
                    BOARD B_next = {
                        NULL, &B_now,
                    };
                    // double B_meanY=0, B_meanX=0;
                    // double diff = 0;
                    rep(y, BOARD_ROW) rep(x, BOARD_COLUMNS){
                        B_next.board[y][x] = B_now.board[y][x];
                        if(y == i && x == j) B_next.board[y][x] = 0;
                        if(y == tmp_y && x == tmp_x) B_next.board[y][x] = 1;
                        if(y == tmp_y - dy[k] && x == tmp_x - dx[k]) B_next.board[y][x] = 0;

                        if(B_next.board[y][x] == 1){
                            // B_meanY = y;
                            // B_meanX = x;
                            // diff += sqrt( abs(y - BG_y) + abs(x - BG_x) );
                        }
                    }
                    B_next.peg_num = B_now.peg_num -1;
                    B_next.depth = B_now.depth + 1;
                    // B_next.f = -1 *( fabs( B_meanY/B_next.peg_num - BG_y) + fabs( B_meanX/B_next.peg_num - BG_x) );
                    // B_next.f = -1 * diff - B_next.depth*5 ;
                    B_next.f = (BG_y-i)*dy[k] + (BG_x-j)*dx[k] + B_now.f;
                    que.push( mp(B_next.f, B_next) );
                }
            }
        }
        if(goal_flag){
            printf("pegsolitire solved in %d depth !!! search_count = %ld \n", B_now.depth, search_counter);
            // ans = &B_now;
            break;
        }
    }
    // while(ans->back != NULL){
    //     printboard(ans);
    //     ans = ans->back;
    // }
}

void printboard(struct BOARD *b){
    rep(i, BOARD_ROW){
        rep(j, BOARD_COLUMNS){
            if(b->board[i][j] == 1) printf("* ");
            else printf("- ");
        }
        printf("\n");
    }
    printf("\n");
    return;
}
