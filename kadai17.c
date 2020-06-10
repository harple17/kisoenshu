#include<stdio.h>
#define SZ_LST 100
#define N 5
#define EN -1 //end 
#define UN -10 //unused

struct LIST {
    int val;
    int next;
};

int init(int A[N],struct LIST list[SZ_LST]) {
    if (N+1>SZ_LST) return -1;
    else {
        list[0].val=0;//header
        list[0].next=1;
        for (int i=1;i<=N;i++) {
            list[i].val=A[i-1];
            list[i].next=i+1;
        }
        list[N].next=EN; //end point
        for (int i=N+1;i<SZ_LST;i++) { // unused area
            list[i].next=UN;
        }
    }
    return 0;
}
void printList(struct LIST list[SZ_LST]) { //show list
    int i=list[0].next;
    printf("list:");
    while(i!=EN) {
        printf("%2d",list[i].val);
        i=list[i].next;
    }
    printf("\n");
}
int insert(int pos,int data,struct LIST list[SZ_LST]) {
    int i=0;
    while (list[i].next!=UN) { //search vacant pos
        i++;
        if (i>SZ_LST) return -1; 
    }
    list[i].val=data; //insert data in the vacant pos
    list[i].next=list[pos-1].next;
    list[pos-1].next=i;
    return 1;
}
void delete(int pos,struct LIST list[SZ_LST]) {
    int i=1;
    int del0=0;
    while (i<pos) {
        del0=list[del0].next;
        i++;
    }
    int del1=list[list[del0].next].next;//change next index
    list[list[del0].next].next=UN;
    list[del0].next=del1;
}

int main() {
    struct LIST list[SZ_LST];
    int A[N]={3,1,6,7,9};

    if (init(A,list)<0) {
        printf("配列の要素数に対しリストの要素数が足りません。\n");
        return 0;
    }
    printList(list);//show initial status

    if(insert(2,3,list)<0) {
        printf("挿入可能な場所がないため挿入できません。\n");
        return 0;
    }
    printList(list); //show inserted one

    delete(2,list);
    printList(list); //show deleted one

    if(insert(4,1,list)<0) {
        printf("挿入可能な場所がないため挿入できません。\n");
        return 0;
    }
    printList(list);

    delete(1,list);
    printList(list);

    return 0;
}