#include<stdio.h>
#include<string.h>
int numofblack(char a[6][7],int h,int w) {
    int n=0;
    for (int i=0;i<h;i++) {
        for (int j=0;j<w;j++) {
            if(a[i][j]=='#') n++;
        }
    }
    return n;
}
void copy(char a[6][7],int h,int w,char b[6][7]) {
    int i;
    for (i=0;i<h;i++) {
        strcpy(b[i],a[i]);
    }
}
int main() {
    int h,w,k;
    int count=0;
    char grids[6][7],tmp[6][7];
    scanf("%d %d %d",&h,&w,&k);
  	for (int i=0;i<h;i++) scanf("%s",grids[i]);
  	int i,j;
    for (i=-1;i<h;i++) {
        for (j=-1;j<w;j++) {
            copy(grids,h,w,tmp);
            if(i!=-1) {
              	for (int l1=0;l1<w;l1++) {
                  	tmp[i][l1]='r';
                }
            }
            if(j!=-1){
              	for (int l2=0;l2<h;l2++) {
                  	tmp[l2][j]='r';
                }
            }
            if(numofblack(tmp,h,w)==k) count++;
        }
    }
    printf("%d\n",count);
    return 0;
}