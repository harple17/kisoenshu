#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 32

struct NODE {
    int num;
    char name[N];
    struct NODE *left,*right;
};
struct NODE *root=NULL;

struct NODE *insert(int s_num,char s_name[N]) {
    struct NODE **p,*new;
    p=&root;
    while(*p!=NULL) {
        if (s_num==(*p)->num) {
            return NULL;
        }
        if (s_num>(*p)->num) {
            p=&(*p)->right;
        }
        else {
            p=&(*p)->left;
        }
    }
    new=(struct NODE*)malloc(sizeof(struct NODE));
    new->left=NULL;
    new->right=NULL;
    new->num=s_num;
    strcpy(new->name,s_name);
    *p=new;
    return new;
}
struct NODE *search(int s_num) {
    struct NODE *p=root;
    while(p!=NULL) {
        if (s_num==p->num) {
            return p;
        }
        if (s_num<p->num) {
            p=p->left;
        }
        if (s_num>p->num) {
            p=p->right;
        }
    }
    return NULL;
}
struct NODE *deletemin(struct NODE **p) {
    struct NODE *x;
    while ((*p)->left!=NULL) p=&(*p)->left;
    x=*p;
    *p=(*p)->right;
    return x;
}
int delete(int s_num) {
    struct NODE **p,*x;
    p=&root;
    while (*p!=NULL) {
        if(s_num==(*p)->num) {
            x=*p;
            if(x->left==NULL&&x->right==NULL) *p==NULL;
            if(x->left==NULL) *p=x->right;
            if(x->right==NULL) *p=x->left;
            else {
                *p=deletemin(&x->right);
                (*p)->left=x->left;
                (*p)->right=x->right;
            }
            free(x);
            return 1;
        }
        if (s_num<(*p)->num) p=&(*p)->left;
        else p=&(*p)->right;
    }
    return 0;
}
int count(struct NODE *p) {
    if (p==NULL) return 0;
    int lc=count(p->left);
    int rc=count(p->right);
    return lc+rc+1;
}
void preorder(struct NODE *p) {
    if (p==NULL) return ;
    printf("No.%d|NAME:%s\n",p->num,p->name);
    preorder(p->left);
    preorder(p->right);
}
void inorder(struct NODE *p) {
    if(p==NULL) return ;
    inorder(p->left);
    printf("No.%d|NAME:%s\n",p->num,p->name);
    inorder(p->right);
}
void postorder(struct NODE *p) {
    if (p==NULL) return ;
    postorder(p->left);
    postorder(p->right);
    printf("No.%d|NAME:%s\n",p->num,p->name);
}
int height(struct NODE *p) {
    if (p==NULL) return 0;
    int lh=height(p->left);
    int rh=height(p->right);
    if(lh>rh) return lh+1;
    else return rh+1;
}
int main() {
    int c,num;
    char name[N];
    while (1) {
        printf("choose an action. 1:add 2:search 3:delete 4:count ndoes 5:show data in preoreder 6: show data in inorder 7:show data in postorder 8:calcurate height 9:end\n");
        scanf("%d",&c);
        if (c==1) {
            printf("input number and name\nnumber:");
            scanf("%d",&num);
            printf("name:");
            scanf("%s",name);
            insert(num,name);
        }
        if (c==2) {
            printf("input number you want to search:");
            scanf("%d",&num);
            struct NODE *p=search(num);
            if (p==NULL) printf("NOT FOUND\n");
            else printf("#FOUND#\nnumber %d|name %s\n",p->num,p->name);
        }
        if (c==3) {
            printf("input number you want to delete:");
            scanf("%d",&num);
            if (delete(num)) printf("delete correctly\n");
            else printf("cannnot be deleted\n");
        }
        if (c==4) printf("the tree has %d nodes\n",count(root));
        if (c==5) preorder(root);
        if (c==6) inorder(root);
        if (c==7) postorder(root);
        if (c==8) printf("the hight of the tree is %d\n",height(root));
        if (c==9) break;
        else ;
    }
    return 0;
}