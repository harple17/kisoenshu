#include<stdio.h>
#define N 4
#define EMPTY -1

int rank(int *p,int n) {
    int i=0;
    for (i=0;i<N;i++) {
        if (*(p+i)==n) break;
    }
    return i;
}
int isempty(int a[N]) {
    int flag=0;
    for (int i=0;i<N;i++) {
        if (a[i]==EMPTY) {
            flag=1;
            break;
        }
    }
    return flag;
}
int isselected(int a[N],int x) {
    for (int i=0;i<N;i++) {
        if(a[i]==x) return 1;
    }
    return 0;
}

int main () {
    int hunter_fav[N][N]={{0,1,2,3},
                          {2,1,0,3},
                          {0,1,3,2},
                          {2,0,3,1}};

    int company_fav[N][N]={{0,1,2,3},
                           {1,0,3,2},
                           {1,2,0,3},
                           {0,3,2,1}};
    int hunt_rslt[N];
    for (int i=0;i<N;i++) hunt_rslt[i]=EMPTY;
    int i=0;
    int j=0;
    while (isempty(hunt_rslt)) {
        /*for (int k=0;k<N;k++) printf("company %d hunted job hunter %d\n",k,hunt_rslt[k]);*/
        if(hunt_rslt[hunter_fav[i][j]]==EMPTY) {
            hunt_rslt[hunter_fav[i][j]]=i;
            i=0;
            while(isselected(hunt_rslt,i))i++; //search not selected hunter
            j=0;
        } else {
            if (rank(company_fav[hunter_fav[i][j]],hunt_rslt[hunter_fav[i][j]])>rank(company_fav[hunter_fav[i][j]],i)) {
                int tmp=hunt_rslt[hunter_fav[i][j]];
                hunt_rslt[hunter_fav[i][j]]=i;
                i=tmp;
                j++;
            } else {
                j++;
            }
        }
    }
    for (int i=0;i<N;i++) {
        printf("company %d hunted job hunter %d\n",i,hunt_rslt[i]);
    }
    return 0;
}