/* depth first search */
#include <stdio.h>
#include <stdlib.h>

struct BOARD {
  char cell[49];
  struct BOARD *next;
  struct BOARD *back;
  int peg;
  int depth;
};

struct BOARD B0 = {
  -1,-1, 0, 0, 0,-1,-1,
  -1,-1, 1, 1, 1,-1,-1,
   0, 1, 1, 1, 1, 1, 0,
   0, 1, 1, 0, 1, 1, 0,
   0, 1, 1, 1, 1, 1, 0,
  -1,-1, 1, 1, 1,-1,-1,
  -1,-1, 0, 0, 0,-1,-1,
  NULL, NULL,
};

struct BOARD BG = {
  -1,-1, 0, 0, 0,-1,-1,
  -1,-1, 0, 0, 0,-1,-1,
   0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 1, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0,
  -1,-1, 0, 0, 0,-1,-1,
  -1,-1, 0, 0, 0,-1,-1,
  NULL, NULL,
};

struct BOARD *q0 = NULL, *q2 = &B0;

int nc = 0;
int ns = 0;

#define FN1 "Init.dat"
#define FN2 "Goal.dat"

int depth_limit = 32;
int depth_increase = 32;

void expand(struct BOARD *b);
void readdata(struct BOARD *b,char *buf);
struct BOARD * exchange(struct BOARD *b,int i,int j);
int equal(struct BOARD *b1,struct BOARD *b2);
void traceback(struct BOARD *b);
void printboard(struct BOARD *b);
void bornprint(struct BOARD *b);
int putq(struct BOARD *b);

struct BOARD *getq() {
    struct BOARD *q,*oldn,*n; 
    if (q2==NULL) return NULL;

    if (depth_limit < 0) {
	q = q2;
	q2 = q2->next;
	return (q);
    }

    while (1){
	oldn = NULL;
	for (n=q2; n != NULL; oldn=n, n=n->next)
	    if (n->depth <= depth_limit) break;
	if (n==NULL) {
	    depth_limit = depth_limit + depth_increase;
	    continue;
	}
        //for de nannrakano shori wo saretara q2!=NULL nara
	if (oldn==NULL) q2 = n->next;
	else oldn->next = n->next;
	return(n);
    }
}


int main(){
    struct BOARD *b;
    struct BOARD *q1;
    int i, nB0, nBG;
    for(i=0, nB0=0, nBG=0; i<49; i++){
      nB0 += B0.cell[i];
      nBG += BG.cell[i];
    }
    B0.peg = nB0;
    BG.peg = nBG;
    
    B0.depth = 0;

    printf("Initial state is \n");
    printboard(&B0);
    printf("Goal state is \n");
    printboard(&BG);
    printf("Execution begins..\n");
    
    //getqはOPENの最初のノードを取り出している。
    while ((q1 = getq()) != NULL) {
	expand(q1);
	if (q0==NULL) q0 = q1;
	else {
	    q1 -> next = q0;
	    q0 = q1;
	}
    }
    return 0;
}


struct BOARD *exchange(struct BOARD *b,int i,int j){
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
    m-> peg = b->peg - 1;
    m-> cell[i] = 1;
    m-> cell[i+j] = 0;
    m-> cell[i+2*j] = 0;
    m-> back = b;
    m-> next = NULL;
    m-> depth = b -> depth + 1;
    
    if (equal(m,&BG)) {
      printf("as\n");
	bornprint(m);
	printf("**** Answer found... ****\n");
	traceback(m); 
	printf("No. of children is %d\n",nc);
	printf("Length of solution is %d\n",ns);
	exit(0); 
    }
    return(m);
}

void expand(struct BOARD *b){
  register int i, k1,k2,k3,k4;
  for (i=0; i<49; i++){
    if (b->cell[i]==0){
      struct BOARD *m1=NULL,*m2=NULL,*m3=NULL,*m4=NULL;
      if((i>=14 && i<=34 && i%7>=2) || i%7 == 4){
        if(b->cell[i-1] == 1 && b->cell[i-2] == 1) m1=exchange(b, i, -1);
      }
      if((i>=14 && i%7>=2 && i%7<=4) || (i>=28 && i<=34)){
        if(b->cell[i-7] == 1 && b->cell[i-14] ==1) m2=exchange(b, i, -7);
      }
      if((i>=14 && i<=34 && i%7<=4) || i%7 == 2){
        if(b->cell[i+1] == 1 && b->cell[i+2] == 1) m3=exchange(b, i, 1);
      }
      if((i<=34 && i%7>=2 && i%7<=4 || (i>=14 && i<=20))){
        if(b->cell[i+7] == 1 && b->cell[i+14] == 1) m4=exchange(b, i, 7);
      }
      
    if (m4!=NULL) k4=putq(m4);
    if (m3!=NULL) k3=putq(m3);
    if (m2!=NULL) k2=putq(m2);
    if (m1!=NULL) k1=putq(m1);

    if ((m1!=NULL)&&(k1==1)) printf("peg: %d, nc : %d\n",m1->peg+16, nc++);//bornprint(m1);
    if ((m2!=NULL)&&(k2==1)) printf("peg: %d, nc : %d\n",m2->peg+16, nc++);//bornprint(m2);
    if ((m3!=NULL)&&(k3==1)) printf("peg: %d, nc : %d\n",m3->peg+16, nc++);//bornprint(m3);
    if ((m4!=NULL)&&(k4==1)) printf("peg: %d, nc : %d\n",m4->peg+16, nc++);// bornprint(m4);
    }
  }
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

void traceback(struct BOARD *b) {
    for (; b!=NULL; b=b->back) {
	ns++;
        printf("ns = %d\n",ns);
	printboard(b);
    }
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

int putq(struct BOARD *b){
    struct BOARD *n; 
    for (n=q0; n!=NULL; n=n->next)
	if (equal(b,n)) {free(b); return 0; }
    if (q2==NULL) {
	q2=b;
	return 1;
    }
    else {
	for (n=q2; n->next!=NULL; n=n->next)
	    if (equal(b,n)) {free(b); return 0; }
	b -> next = q2;
	q2 = b;
	return 1;
    }
}


    
