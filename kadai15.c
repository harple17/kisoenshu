#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N_MAX 99

void printMoved(int a[], int size) {
    printf("moved position:");
    for (int i=0;i<size;i++) {
        if (a[i]==0) {
            printf(".");
        } else {
            printf("*");
        }
    }
    printf("\n");
}
void bubbleSort(int a[], int size, int rec[]) {
    printf("initial status:"); //show initial status of array
    for (int j=0;j<size;j++) {
        printf("%3d",a[j]);
    }
    printf("\n");
    for (int i=0;i<size-1;i++) { 
        for (int j=0;j<size;j++) { // initiate rec array
            rec[j]=0;
        }
        int flag=0;
        for (int j=size-1;j>i;j--) {
            if (a[j]<a[j-1]) {
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                rec[j]=rec[j-1]=flag=1;
            }
        }
        if (flag==0) break; //if there is no change
        printMoved(rec,size);
        printf("%d times:",i+1); //show processing status
        for (int j=0;j<size;j++) {
            printf("%3d",a[j]);
        }
        printf("\n");
    }
}
void selectSort(int a[],int size, int rec[]) {
    printf("initial status:"); //show initial status of array
    for (int j=0;j<size;j++) {
        printf("%3d",a[j]);
    }
    printf("\n");
    for (int i=0;i<size-1;i++) {
        for (int j=0;j<size;j++) { // initiate rec array
            rec[j]=0;
        }
        int minadd=i; // rec min element
        for (int j=i+1;j<size;j++) {
            if (a[minadd]>a[j]) minadd=j;
        }
        int tmp = a[i];
        a[i] = a[minadd];
        a[minadd] = tmp;
        if (minadd!=i) rec[minadd] = rec[i] = 1;
        printMoved(rec,size);
        printf("%d times:",i+1);
        for (int j=0;j<size;j++) {
            printf("%3d",a[j]);
        }
        printf("\n");
    }
}
void insertSort(int a[],int size, int rec[]) {
    printf("initial status:"); //show initial status of array
    for (int j=0;j<size;j++) {
        printf("%3d",a[j]);
    }
    printf("\n");
    for (int i=1;i<size;i++) {
        for (int j=0;j<size;j++) { // initiate rec array
            rec[j]=0;
        }
        int tmp = a[i];
        int j;
        for (j=i;j>0 && a[j-1]>tmp;j--) {
            a[j] = a[j-1];
            rec[j] = rec[j-1] = 1;
        }
        a[j] = tmp;
        if (i!=j) rec[j]=1;
        printMoved(rec,size);
        printf("%d times:",i);
        for (int k=0;k<size;k++) {
            printf("%3d",a[k]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int in1[N_MAX]={0};
    int in2[N_MAX]={0};
    int in3[N_MAX]={0};
    int rec[N_MAX] ={0};
    int n;
    printf("入力された数だけ乱数を配列内に代入します。ただし100未満を入力してください。:");
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        in1[i]=rand()%100;
    }
    for (int i=0;i<n;i++) {
        in2[i]=rand()%100;
    }
    for (int i=0;i<n;i++) {
        in3[i]=rand()%100;
    }
    printf("bubble sort\n");
    bubbleSort(in1,n,rec);
    printf("\nselect sort\n");
    selectSort(in2,n,rec);
    printf("\ninsert sort\n");
    insertSort(in3,n,rec);
    return 0;
}
