#include<stdio.h>
#include<stdlib.h>

typedef int datatype;

#define HEAD 0 

struct NODE {
    struct NODE *next;
    datatype data;
};
struct NODE *create(datatype data) { //create data
    struct NODE *p = (struct NODE*)malloc(sizeof(struct NODE));
    p->next = NULL;
    p->data = data;
    return p;
}
void insert(struct NODE *p_next,struct NODE *p_obj) { //insert the data addressed by p_obj next to p_next
    p_obj->next=p_next->next;
    p_next->next=p_obj;
}
struct NODE *erase(struct NODE *p) { //erase the data "next to p"(not p)
    struct NODE *ptr=p->next;
    if (ptr!=NULL) {
        p->next=ptr->next;
        ptr->next=NULL;
    }
    return ptr;
}
struct NODE *split(struct NODE *p) { //split list at the position next to p
    struct NODE *ptr;
    if (p->next!=NULL) {
        ptr=create(HEAD);
        insert(p,ptr);
        p->next=NULL;
        return ptr;
    }　else {
        printf("cannnot be spited\n");
        return NULL;
    }
}
struct NODE *cat(struct NODE *p1, struct NODE *p2) { //concatenate lists begun by p1 and p2
    struct NODE *p1_end=p1->next;
    while (p1_end->next!=NULL) p1_end = p1_end->next;
    p1_end->next=p2->next;
    p2->next=NULL;
    return p1;
}

int main () {
    struct NODE *header1=create(HEAD);
    struct NODE *elm1=create(1);
    struct NODE *elm2=create(2);
    struct NODE *elm3=create(3);
    insert(header1,elm1);
    insert(elm1,elm2);
    insert(elm2,elm3); //list1

    struct NODE *p1=header1->next;
    printf("list1:");
    while (p1!=NULL) {
        printf("%2d",p1->data);
        p1=p1->next;
    }
    printf("\n");

    struct NODE *header2=create(HEAD);
    struct NODE *elm4=create(4);
    struct NODE *elm5=create(5);
    struct NODE *elm6=create(6);
    insert(header2,elm4);
    insert(elm4,elm5);
    insert(elm5,elm6); //list2

    struct NODE *p2=header2->next;
    printf("list2:");
    while (p2!=NULL) {
        printf("%2d",p2->data);
        p2=p2->next;
    }
    printf("\n");

    struct NODE *p3=cat(header1,header2)->next;
    printf("concatenated list:");
    while (p3!=NULL) {
        printf("%2d",p3->data);
        p3=p3->next;
    }
    printf("\n");

    struct NODE *p5=split(elm2)->next;
    struct NODE *p6=p5;
    struct NODE *p4=header1->next;
    printf("splited list1:");
    while (p4!=NULL) {
        printf("%2d",p4->data);
        p4=p4->next;
    }
    printf("\n");
    printf("splited list2:");
    while (p5!=NULL) {
        printf("%2d",p5->data);
        p5=p5->next;
    }
    printf("\n");

    erase(elm3);
    printf("erased list:");
    while (p6!=NULL) {
        printf("%2d",p6->data);
        p6=p6->next;
    }
    printf("\n");

    return 0;
}