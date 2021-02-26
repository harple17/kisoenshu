#include<stdio.h>
#include<stdlib.h>

#define HEAD 100000
#define N 6

struct NODE {
    struct NODE *next;
    int value;
};

struct NODE *create(int data) { //create element
    struct NODE *p=(struct NODE*)malloc(sizeof(struct NODE));
    p->next=NULL;
    p->value=data;
    return p;
}
struct NODE *createEmpty(struct NODE *header) { // create empty set
    struct NODE *p=header->next;
    while(p!=NULL) {
        struct NODE *tmp=p->next;
        free(p);
        p=tmp;
    }
    free(p);
    header->next=NULL;
    return header;
}
int isincluded(struct NODE *header, int x){ // tell wheter x is in the list or not
    struct NODE *p=header->next;
    while(p!=NULL) {
        if (p->value==x) return 1;
        p=p->next;
    }
    return 0;
}
struct NODE *createUnion(struct NODE *header1, struct NODE *header2) {
    struct NODE *header=create(HEAD);
    struct NODE *p1=header1->next;
    struct NODE *p2=header2->next;
    struct NODE *p=header;
    while(p1!=NULL) {
        p->next=create(p1->value);
        p=p->next;
        p1=p1->next;
    }
    while(p2!=NULL) {
        if(isincluded(header,p2->value)==0) {
            p->next=create(p2->value);
            p=p->next;
        }
        p2=p2->next;
    }
    return header;
}
struct NODE *createDef(struct NODE *header1, struct NODE *header2) {
    struct NODE *header=create(HEAD);
    struct NODE *p1=header1->next;
    struct NODE *p=header;
    while(p1!=NULL) {
        if (isincluded(header2,p1->value)==0) {
            p->next=create(p1->value);
            p=p->next;
        }
        p1=p1->next;
    }
    return header;
}
struct NODE *createProd(struct NODE *header1, struct NODE *header2) {
    struct NODE *header=create(HEAD);
    struct NODE *p1=header1->next;
    struct NODE *p=header;
    while(p1!=NULL) {
        if (isincluded(header2,p1->value)==1) {
            p->next=create(p1->value);
            p=p->next;
        }
        p1=p1->next;
    }
    return header;
}
void add(struct NODE *header, int data, int pos) { // insert the elm of the data next to the elm at the number of pos in the list
    if(isincluded(header,data)){
        printf("the element already exists in the set\n");
    } else {
    struct NODE *p=create(data);
    struct NODE *ins=header;
    for (int i=0;i<pos;i++) ins=ins->next;
    struct NODE *tmp=ins->next;
    ins->next=p;
    p->next=tmp;
    }
}
struct NODE *delete(struct NODE *header, int pos) { //delete the elm next to the elm at the elm at the number of pos in the list
    struct NODE *p=header;
    for (int i=0;i<pos;i++) p=p->next;
    struct NODE *tmp=p->next;
    p->next=tmp->next;
    tmp->next=NULL;
    return tmp;
}
void assignset(struct NODE *header1,struct NODE *header2) { //asssign the list addressed by header1 to the one addressed by header2
    createEmpty(header2);
    int i=0;
    for (struct NODE *p=header1->next;p!=NULL;p=p->next) {
        add(header2,p->value,i);
        i++;
    }
}
int setcmp(struct NODE *header1,struct NODE *header2) { //compare the list addressed by header1 to the one addressed by header2
    int a1[N]={0};
    int a2[N]={0};
    for (struct NODE *p=header1->next;p!=NULL;p=p->next) {
        a1[p->value-1]=1;
    }
    for (struct NODE *p=header2->next;p!=NULL;p=p->next) {
        a2[p->value-1]=1;
    }
    int flag=0;
    for (int i=0;i<N;i++) {
        if(a1[i]!=a2[i]) {
            flag=1;
            break;
        }
    }
    return flag;
}
struct NODE *find(struct NODE *header,int x) { // find the elm of x in the list addressed by header
    struct NODE *p;
    for (p=header->next;p!=NULL;p=p->next) {
        if (p->value==x) break;
    }
    return p;
}

int main() {
    struct NODE *set1=create(HEAD);
    add(set1,1,0);
    add(set1,2,1);
    add(set1,3,2);

    struct NODE *set2=create(HEAD);
    add(set2,4,0);
    add(set2,2,1);
    add(set2,3,2);

    for (struct NODE *p=createUnion(set1,set2)->next;p!=NULL;p=p->next) printf("%d ",p->value);
    printf("\n");

    for (struct NODE *p=createDef(set1,set2)->next;p!=NULL;p=p->next) printf("%d ",p->value);
    printf("\n");

    for (struct NODE *p=createProd(set1,set2)->next;p!=NULL;p=p->next) printf("%d ",p->value);
    printf("\n");

    delete(set2,0);
    add(set2,1,0);

    for(struct NODE *p=set1->next;p!=NULL;p=p->next) printf("%d ",p->value);
    printf("\n");

    if(setcmp(set1,set2)==0) printf("the sets are the same\n");

    if(find(set1,2)!=NULL) printf("%d is found in the set\n",find(set1,2)->value);

    printf("%d\n",delete(set1,1)->value);
    assignset(set1,set2);

    for (struct NODE *p=set2->next;p!=NULL;p=p->next) printf("%d ",p->value);
    printf("\n");

    if(setcmp(set1,set2)==0) printf("the sets are the same\n");

    return 0;
}