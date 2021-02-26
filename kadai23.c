#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 32
#define MAX_ELM 100 //how many elements you can rec

struct PD {
    char student_num[N];
    char fam_name[N];
    char first_name[N];
    char phone_num[N];
    char post_code[N];
    struct PD *prev;
    struct PD *next;
};

void add(struct PD *header) {
    struct PD *p=(struct PD*)malloc(sizeof(struct PD));
    printf("input student number:"); scanf("%s",p->student_num);
    printf("input family name:"); scanf("%s",p->fam_name);
    printf("input first name:"); scanf("%s",p->first_name);
    printf("input phone number:"); scanf("%s",p->phone_num);
    printf("input postal code:");scanf("%s",p->post_code);
    header->prev->next=p;
    p->prev=header->prev;
    p->next=header;
    header->prev=p;
}
struct PD *delete(struct PD *header,int pos) {
    struct PD *p=header;
    for (int i=0;i<pos;i++) p=p->next;
    if (p==header) {
        printf("cannnot delete header\n");
        return NULL;
    }
    p->prev->next=p->next;
    p->next->prev=p->prev;
    p->next=p;
    p->prev=p;
    return p;
}
int search(struct PD *header,int mode,char c[N],struct PD **array) {
    struct PD *p=header;
    int i=0;
    switch (mode) {
    case 1:
        do {
            p=p->next;
            if (strcmp(p->student_num,c)==0) {
                array[i]=p;
                i++;
            }
        } while (p->next!=header);
        break;
    case 2:
        do {
            p=p->next;
            if (strcmp(p->fam_name,c)==0) {
                array[i]=p;
                i++;
            }
        } while (p->next!=header);
        break;
    case 3:
        do {
            p=p->next;
            if (strcmp(p->first_name,c)==0) {
                array[i]=p;
                i++;
            }
        } while (p->next!=header);
        break;
    case 4:
        do {
            p=p->next;
            if (strcmp(p->phone_num,c)==0) {
                array[i]=p;
                i++;
            }
        } while (p->next!=header);
        break;
    case 5:
        do {
            p=p->next;
            if (strcmp(p->post_code,c)==0) {
                array[i]=p;
                i++;
            }
        } while (p->next!=header);
        break;
    }
    return i;
}
int isselected(struct PD **array,int n,struct PD *p) {
    for (int i=0;i<n;i++) {
        if(array[i]==p) return 1;
    }
    return 0;
}
int sort(struct PD *header,int mode,struct PD **array) {
    struct PD *p1=header;
    struct PD *p2;
    struct PD *tmp;
    int i=0;
    switch (mode) {
    case 1:
        do {
            p1=p1->next;
            tmp=p1;
            p2=p1->next;
            do {
                if(p2!=header) {
                    if (strcmp(tmp->student_num,p2->student_num)>0&&isselected(array,i,p2)==0){
                        tmp=p2;
                    }
                }
                p2=p2->next;
            } while (p2!=p1);
            if(isselected(array,i,tmp)==0&&tmp!=header) {
                array[i]=tmp;
                i++;
            }
        } while (p1!=header);
        break;
    case 2:
        do {
            p1=p1->next;
            tmp=p1;
            p2=p1->next;
            do {
                if(p2!=header) {
                    if (strcmp(tmp->fam_name,p2->fam_name)>0&&isselected(array,i,p2)==0){
                        tmp=p2;
                    }
                }
                p2=p2->next;
            } while (p2!=p1);
            if(isselected(array,i,tmp)==0&&tmp!=header) {
                array[i]=tmp;
                i++;
            }
        } while (p1!=header);
        break;
    case 3:
        do {
            p1=p1->next;
            tmp=p1;
            p2=p1->next;
            do {
                if(p2!=header) {
                    if (strcmp(tmp->first_name,p2->first_name)>0&&isselected(array,i,p2)==0){
                        tmp=p2;
                    }
                }
                p2=p2->next;
            } while (p2!=p1);
            if(isselected(array,i,tmp)==0&&tmp!=header) {
                array[i]=tmp;
                i++;
            }
        } while (p1!=header);
        break;
    case 4:
        do {
            p1=p1->next;
            tmp=p1;
            p2=p1->next;
            do {
                if(p2!=header) {
                    if (strcmp(tmp->phone_num,p2->phone_num)>0&&isselected(array,i,p2)==0){
                        tmp=p2;
                    }
                }
                p2=p2->next;
            } while (p2!=p1);
            if(isselected(array,i,tmp)==0&&tmp!=header) {
                array[i]=tmp;
                i++;
            }
        } while (p1!=header);
        break;
    case 5:
        do {
            p1=p1->next;
            tmp=p1;
            p2=p1->next;
            do {
                if(p2!=header) {
                    if (strcmp(tmp->post_code,p2->post_code)>0&&isselected(array,i,p2)==0){
                        tmp=p2;
                    }
                }
                p2=p2->next;
            } while (p2!=p1);
            if(isselected(array,i,tmp)==0&&tmp!=header) {
                array[i]=tmp;
                i++;
            }
        } while (p1!=header);
        break;
    }
    return i;
}
void showData(struct PD *header,int mode) {
    struct PD *tmp=header;
    if (mode==1) {
        do {
            tmp=tmp->next;
            if(tmp==header) printf("empty\n");
            printf("student number:%s|family name:%s|first name:%s|phone number:%s|postal code:%s\n",tmp->student_num,tmp->fam_name,tmp->first_name,tmp->phone_num,tmp->post_code);
        } while (tmp->next!=header);
    }
    if (mode==2) {
        do {
            tmp=tmp->prev;
            if(tmp==header) printf("empty\n");
            printf("student number:%s|family name:%s|first name:%s|phone number:%s|postal code:%s\n",tmp->student_num,tmp->fam_name,tmp->first_name,tmp->phone_num,tmp->post_code);
        } while (tmp->prev!=header);
    }
}

int main() {
    int choice1,choice2,i;
    char c[N];
    struct PD *rec[MAX_ELM];
    struct PD header={"HEAD","HEAD","HEAD","HEAD","HEAD",&header,&header};
    do {
        printf("Select an action\n1:Add data 2:Delete data 3:Search 4:Sort 5:Output 6:end\n");
        scanf("%d",&choice1);
        switch (choice1) {
        case 1:
            add(&header);
            break;
        case 2:
            printf("What number of element do yoy want to delete?(the numbers are given along the order of addition. confirm through action 5)\n1:countinue\n2:back\n");
            scanf("%d",&choice2);
            if (choice2==2) break;
            printf("input the number:");
            scanf("%d",&choice2);
            delete(&header,choice2);
            break;
        case 3:
            printf("What item do you want to search ?\n1:student name\n2:family name\n3:first name\n4:phone number\n5:postal code\n");
            scanf("%d",&choice2);
            printf("input number/name/code:"); scanf("%s",c);
            printf("result\n");
            for (i=0;i<search(&header,choice2,c,rec);i++) {
                printf("student number:%s|family name:%s|first name:%s|phone number:%s|postal code:%s\n",rec[i]->student_num,rec[i]->fam_name,rec[i]->first_name,rec[i]->phone_num,rec[i]->post_code);
            }
            if (i==0) printf("NOT FOUND\n");
            break;
        case 4:
            printf("By which do you want to sort data?\n1:student number\n2:family name\n3:first name\n4:phone number\n5:postal code\n");
            scanf("%d",&choice2);
            printf("result\n");
            for (i=0;i<sort(&header,choice2,rec)&&header.next!=&header;i++) {
                printf("student number:%s|family name:%s|first name:%s|phone number:%s|postal code:%s\n",rec[i]->student_num,rec[i]->fam_name,rec[i]->first_name,rec[i]->phone_num,rec[i]->post_code);
            }
            if(header.next==&header) printf("no data\n");
            break;
        case 5:
            printf("How do you want to see data?\n1:additon order\n2:reversed addition order\n");
            scanf("%d",&choice2);
            showData(&header,choice2);
            break;
        case 6:
            break;
        default:
            printf("invalid input\n");
            break;
        }
    } while (choice1!=6);
    return 0;
}