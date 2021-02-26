#include<stdio.h>
#include<stdlib.h>

#define HEAD 100000

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
void add(struct NODE *header, int data, int pos) { // insert the elm of the data next to the elm at the number of pos in the list
    struct NODE *p=create(data);
    struct NODE *ins=header;
    for (int i=0;i<pos;i++) ins=ins->next;
    struct NODE *tmp=ins->next;
    ins->next=p;
    p->next=tmp;
}
struct NODE *delete(struct NODE *header, int pos) { //delete the elm next to the elm at the elm at the number of pos in the list
    struct NODE *p=header;
    for (int i=0;i<pos;i++) p=p->next;
    struct NODE *tmp=p->next;
    p->next=tmp->next;
    tmp->next=NULL;
    return tmp;
}

int main() {
    struct NODE *header=create(HEAD);
    for (int i=0;i<9;i++) add(header,i+1,i);
    struct NODE *p=header;
    for (int i=0;i<9;i++) p=p->next;
    p->next=header->next;

    for (p=header->next->next->next->next;p!=NULL;p=p->next->next->next->next) {
        printf("%d is deleted\n",delete(p,0)->value);
    }

    return 0;
}