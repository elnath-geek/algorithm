/* A star search */
#include <stdio.h>
#include <stdlib.h>
struct BOARD{
    char cell[49];
    struct BOARD *next;
    struct BOARD *back;
    int peg;
    int depth, f;
};

struct BOARD B0 = {
    1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1,
    NULL, NULL,
};

struct BOARD BG = {
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    NULL, NULL,
};

struct BOARD *q0 = NULL, *q2 = &B0;

struct BOARD *getq(){
    struct BOARD *q;
    if (q2 == NULL)
        return NULL;
    q = q2;
    q2 = q2->next;
    return (q);
}

int nc = 0;
int ns = 0;
int diffMode = 1;

#define FN1 "Init.dat"
#define FN2 "Goal.dat"

void expand(struct BOARD *b);
void exchange(struct BOARD *b, int i, int j);
int equal(struct BOARD *b1, struct BOARD *b2);
void traceback(struct BOARD *b);
void printboard(struct BOARD *b);
void bornprint(struct BOARD *b);
void putq(struct BOARD *b);
void f_value(struct BOARD *b);
int diff(struct BOARD *b1, struct BOARD *b2);
int diff2(struct BOARD *b1, struct BOARD *b2);
void printQ(struct BOARD *b);
void updateBoard(struct BOARD *b1, struct BOARD *b2);

int main(int argc, char *argv[]){
    struct BOARD *b;
    struct BOARD *q1;

    if (argc > 1)
        diffMode = 1;
    else
        diffMode = 0; //legacy

    int i, nB0, nBG;
    for (i = 0, nB0 = 0, nBG = 0; i < 49; i++){
        nB0 += B0.cell[i];
        nBG += BG.cell[i];
    }
    B0.peg = nB0;
    BG.peg = nBG;

    B0.depth = 1;

    printf("Initial state is \n");
    printboard(&B0);
    printf("Goal state is \n");
    printboard(&BG);
    printf("Execution begins..\n");

    f_value(&B0);

    while ((q1 = getq()) != NULL)    {
        expand(q1);
        if (q0 == NULL)
            q0 = q1;
        else{
            q1->next = q0;
            q0 = q1;
        }
        /*	printf("Q0 is ...\n");
	printQ(q0);
	printf("Q2 is ...\n");
	printQ(q2);
    */
    }
    return 0;
}

void updateBoard(struct BOARD *b1, struct BOARD *b2){
    int k;
    for (k = 0; k < 49; k++)
        b1->cell[k] = b2->cell[k];
}

int diff2(struct BOARD *b1, struct BOARD *b2){
    int ans = 0, k;
    for (k = 0; k < 49; k++){
        if (b1->cell[k] != b2->cell[k]){
            if (k % 7 >= 2 && k % 7 <= 4 && k >= 16 && k <= 32)
                ans += 1;
            else if ((k >= 9 && k <= 11) || (k >= 37 && k <= 39) || ((k % 7 == 5 || k % 7 == 1) && k >= 14 && k <= 34))
                ans += 2;
            else
                ans += 3;
        }
    }
    return (ans);
}

int diff(struct BOARD *b1, struct BOARD *b2){
    int ans = 0, k;
    for (k = 0; k < 49; k++){
        if (b1->cell[k] != b2->cell[k]){
            ans++;
        }
    }
    return (ans);
}

void f_value(struct BOARD *b){
    int h;
    switch (diffMode){
        case 1:
            h = diff2(b, &BG);
            break; //normal
        case 0:
            h = diff(b, &BG);
            break; //legacy diff
    }
    b->f = b->depth + h;
}

void exchange(struct BOARD *b, int i, int j){
    struct BOARD *m;
    int k;

    m = (struct BOARD *)malloc(sizeof(struct BOARD));
    if (m == NULL){
        printf("memory overflow\n");
        exit(2);
    }

    for (k = 0; k < 49; k++){
        m->cell[k] = b->cell[k];
    }
    //cell[i] = 0, cell[i+j] = 1, cell[i+2*j] = 1 :before
    //cell[i] = 1, cell[i+j] = 0, cell[i+2*j] = 0 :after
    m->peg = b->peg - 1;
    m->cell[i] = 1;
    m->cell[i + j] = 0;
    m->cell[i + 2 * j] = 0;
    m->back = b;
    m->next = NULL;
    m->depth = b->depth + 1;

    if (equal(m, &BG)){
        f_value(b);
        bornprint(m);
        printf("**** Answer found... ****\n");
        traceback(m);
        printf("No. of children is %d\n", nc);
        printf("Length of solution is %d\n", ns);
        exit(0);
    }
    putq(m);
}

void expand(struct BOARD *b){
    register int i;
    for (i = 0; i < 49; i++){
        if (b->cell[i] == 0){
            if ((i >= 14 && i <= 34 && i % 7 >= 2) || i % 7 == 4){
                if (b->cell[i - 1] == 1 && b->cell[i - 2] == 1)
                    exchange(b, i, -1);
            }
            if ((i >= 14 && i % 7 >= 2 && i % 7 <= 4) || (i >= 28 && i <= 34)){
                if (b->cell[i - 7] == 1 && b->cell[i - 14] == 1)
                    exchange(b, i, -7);
            }
            if ((i >= 14 && i <= 34 && i % 7 <= 4) || i % 7 == 2){
                if (b->cell[i + 1] == 1 && b->cell[i + 2] == 1)
                    exchange(b, i, 1);
            }
            if ((i <= 34 && i % 7 >= 2 && i % 7 <= 4 || (i >= 14 && i <= 20))){
                if (b->cell[i + 7] == 1 && b->cell[i + 14] == 1)
                    exchange(b, i, 7);
            }
        }
    }
    return;
}

int equal(struct BOARD *b1, struct BOARD *b2){
    register int i, j;
    if (b1->peg != b2->peg)
        return 0;
    for (i = 0, j = 0; i < 49; i++, j++){
        if (b1->cell[i] != b2->cell[j])
            break;
    }
    if (i == 49)
        return 1;
    for (i = 0, j = 6; i < 49; i++, j = (j >= 42) ? j % 7 - 1 : j + 7){
        if (b1->cell[i] != b2->cell[j])
            break;
    }
    if (i == 49)
        return 1;
    for (i = 0, j = 48; i < 49; i++, j--){
        if (b1->cell[i] != b2->cell[j])
            break;
    }
    if (i == 49)
        return 1;
    for (i = 0, j = 42; i < 49; i++, j = (j <= 6) ? 43 + j % 7 : j - 7){
        if (b1->cell[i] != b2->cell[j])
            break;
    }
    if (i == 49)
        return 1;
    return 0;
}

void traceback(struct BOARD *b){
    for (; b != NULL; b = b->back){
        ns++;
        printboard(b);
    }
}

void printboard(struct BOARD *b){
    int i;
    for (i = 0; i < 49; i++)    {
        if (b->cell[i] == 1)
            putchar('*');
        else
            putchar(' ');
        if (i % 7 == 6){
            putchar('\n');
        }
    }
    putchar('\n');
    return;
}

void printQ(struct BOARD *b){
    if (b == NULL)
        return;
    printboard(b);
    printf(" %d ==> \n", b->f);
    printQ(b->next);
}

void bornprint(struct BOARD *b){
    nc++;
    printboard(b->back);
    printf(" %d ----> %d \n", b->back->f, b->f);
    printboard(b);
    printf("\n");
}

void putq(struct BOARD *b){
    struct BOARD *n, *oldn = NULL;
    for (n = q0; n != NULL; n = n->next)
        if (equal(b, n)){
            free(b);
            return;
        }
    if (q2 == NULL){
        f_value(b);
        q2 = b;
        bornprint(b);
    }else{
        f_value(b);
        for (n = q2; n->next != NULL; n = n->next)
            if (equal(b, n)){
                free(b);
                return;
            }
        for (n = q2; n != NULL; oldn = n, n = n->next)
            if (n->f > b->f)
                break;
        b->next = n;
        if (oldn != NULL)
            oldn->next = b;
        else
            q2 = b;
        //bornprint(b);
        printf("peg: %d, nc : %d\n", b->peg + 16, nc++);
    }
}
