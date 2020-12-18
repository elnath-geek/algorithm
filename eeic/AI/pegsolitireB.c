/* breadth first search */
#include <stdio.h>
#include <stdlib.h>
struct BOARD {
  char cell[49];
  struct BOARD *next;
  struct BOARD *back;
  int peg;
};

struct BOARD B0 = {
  -1,-1, 0, 0, 0,-1,-1,
  -1,-1, 1, 1, 1,-1,-1,
   0, 1, 1, 1, 1, 1, 0,
   0, 1, 1, 0, 1, 1, 0,
   0, 1, 1, 1, 1, 1, 0,
  -1,-1, 1, 1, 1,-1,-1,
  -1,-1, 0, 0, 0,-1,-1,
  NULL, NULL, -2 
};

struct BOARD BG = {
  -1,-1, 0, 0, 0,-1,-1,
  -1,-1, 0, 0, 0,-1,-1,
   0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 1, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0,
  -1,-1, 0, 0, 0,-1,-1,
  -1,-1, 0, 0, 0,-1,-1,
  NULL, NULL, -15
};

struct BOARD *q0 = NULL, *q1 = &B0, *q2 = &B0;

int nc = 0;
int ns = 0;

#define FN1 "Init.dat"
#define FN2 "Goal.dat"

void expand(struct BOARD *b);
void exchange(struct BOARD *b,int i,int j);
int equal(struct BOARD *b1,struct BOARD *b2);
void traceback(struct BOARD *b);
void printboard(struct BOARD *b);
void bornprint(struct BOARD *b);
void putq(struct BOARD *b);

int main(){
  struct BOARD *b;

  int i, nB0, nBG;
  for(i=0, nB0=0, nBG=0; i<49; i++){
    nB0 += B0.cell[i];
    nBG += BG.cell[i];
  }
  B0.peg = nB0;
  BG.peg = nBG;

  printf("Initial state is \n");
  printboard(&B0);
  printf("Goal state is \n");
  printboard(&BG);
  printf("Execution begins..\n");
    
  while (q1 != NULL) {
    //b:current board state. q1:initail state. q2:goal state.
    for (b=q1; b!=NULL; b=b->next){
      expand(b);
    }
    q0=q1;
    q1=q2;
    q2=NULL;
    printf("%d\n",nc);
  }
  
  return 0;
}


void expand(struct BOARD *b){
  register int i;
  for (i=0; i<49; i++){
    if (b->cell[i]==0){
      if((i>=14 && i<=34 && i%7>=2) || i%7 == 4){
        if(b->cell[i-1] == 1 && b->cell[i-2] == 1) exchange(b, i, -1);
      }
      if((i>=14 && i%7>=2 && i%7<=4) || (i>=28 && i<=34)){
        if(b->cell[i-7] == 1 && b->cell[i-14] ==1) exchange(b, i, -7);
      }
      if((i>=14 && i<=34 && i%7<=4) || i%7 == 2){
        if(b->cell[i+1] == 1 && b->cell[i+2] == 1) exchange(b, i, 1);
      }
      if((i<=34 && i%7>=2 && i%7<=4 || (i>=14 && i<=20))){
        if(b->cell[i+7] == 1 && b->cell[i+14] == 1) exchange(b, i, 7);
      }
    }
  }
  return;
}

void exchange(struct BOARD *b,int i,int j){
  //i, i+j, i+2*j
  struct BOARD *m;
  int k;
  m=(struct BOARD*)malloc (sizeof(struct BOARD));
  if (m==NULL) {
    printf("memory overflow\n");
    exit(2);
  }
  for (k=0;k<49;k++){
    m-> cell[k] = b->cell[k];
  }
  //cell[i] = 0, cell[i+j] = 1, cell[i+2*j] = 1 :before
  //cell[i] = 1, cell[i+j] = 0, cell[i+2*j] = 0 :after
  m-> peg = b->peg-1;
  m-> cell[i] = 1;
  m-> cell[i+j] = 0;
  m-> cell[i+2*j] = 0;
  m-> back = b;
  m-> next = NULL;
  if (equal(m,&BG)) { 
    bornprint(m);
    printf("**** Answer found... ****\n");
    traceback(m); 
    printf("No. of children is %d\n",nc);
    printf("Length of solution is %d\n",ns);
    exit(0); 
  }
  putq(m);
  return;
}

int equal(struct BOARD *b1,struct BOARD *b2){
  register int i,j;
  if(b1->peg!=b2->peg) return 0;
  for(i=0, j=0; i<49; i++,j++){
    if(b1->cell[i] != b2->cell[j]) break;     
  }
  if(i==49) return 1;
  for(i=0, j=6; i<49; i++,j=(j>=42)? j%7-1:j+7){
    if(b1->cell[i] != b2->cell[j]) break;     
  }
  if(i==49) return 1;
  for(i=0, j=48; i<49; i++, j--){
    if(b1->cell[i] != b2->cell[j]) break;    
  }
  if(i==49) return 1;
  for(i=0, j=42; i<49; i++, j=(j<=6)?43+j%7:j-7){
    if(b1->cell[i] != b2->cell[j]) break;     
  }
  if(i==49) return 1;
  return 0;
}

void traceback(struct BOARD *b){
  for (; b!=NULL; b=b->back){
    ns++;
    printboard(b);
  }
  return;
}

void printboard(struct BOARD *b){
  int i;
  for (i=0;i<49;i++) {
    if (b->cell[i]==1) putchar('*');
    else putchar(' ');
    if (i%7==6) {
      putchar('\n');
    }
  }
  putchar('\n');
  return;
}


void bornprint(struct BOARD *b){
  nc++;
  printboard(b->back);
  printf(" ----> \n");
  printboard(b);
  printf("\n");
  return;
}

void putq(struct BOARD *m){
  struct BOARD *n;
  //if current state is same as state before, free current state. 
  for (n=q0; n!=NULL; n=n->next)
    if (equal(m,n)) {free(m); return; }
  //
  if (q2==NULL) {
    q2=m;
    bornprint(q2);
  }
  //
  else {
    for (n=q2; n->next!=NULL; n=n->next)
      if (equal(m,n)) {free(m); return; }
    n -> next = m;
    //bornprint(m);
    printf("peg: %d, nc : %d\n",m->peg+16, nc++);
  }
}
