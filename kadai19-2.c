#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define STCK_MAX 100

int N;
int stack[STCK_MAX];
void init() {
    N=0;
}
void push(int x) {
    if (N>=STCK_MAX) printf("stack overflow\n");
    else stack[N++]=x;
}
int pop() {
    if (N<=0) printf("stack underflow\n");
    else return stack[--N];
}
void showStack(int stack[STCK_MAX]) {
    printf("before stack:");
    for (int i=0;i<N;i++) printf("%d,",stack[i]);
    printf("\n");
    int tmp=pop();
    printf("after stack:");
    for (int i=0;i<N;i++) printf("%d,",stack[i]);
    printf("\n");
    push(tmp);
}

int main () {
    FILE *fp;
    int c,p1,p2,mode;
    char buff[256]={0}; buff[0]=-1;//preparation for the condition of first number being negative
    char scanned[256]={0};
    int i=1;
    int n=0;
    init();
    printf("by which do you like to input data?\n0:text file(please prepare contents in stack.txt and put it in the same directory)\n1:keybord\n*caution*:put space next to one number in order to distinguish multi-digit number\n");
    scanf("%d",&mode);

    if (mode==0) {
        if ((fp=fopen("stack.txt","r"))==NULL) {
            printf("file cannot be opened\n");
            return 1;
        }
        while ((c=fgetc(fp))!=EOF) {
            if(isdigit(c)||(buff[i-1]<'0'||buff[i-1]>'9')&&c=='-') { //distinguish whether '-' is operant or representation of negative number
                buff[i]=c;
                i++;
            } else {
                switch(c) {
                case '+':
                    buff[i]='\0';
                    push(atoi(buff+1));
                    i=1;
                    p2=pop();
                    p1=pop();
                    push(p1+p2);
                    break;
                case '-':
                    buff[i]='\0';
                    push(atoi(buff+1));
                    i=1;
                    p2=pop();
                    p1=pop();
                    push(p1-p2);
                    break;
                case '*':
                    buff[i]='\0';
                    push(atoi(buff+1));
                    i=1;
                    p2=pop();
                    p1=pop();
                    push(p1*p2);
                    break;
                case '/':
                    buff[i]='\0';
                    push(atoi(buff+1));
                    i=1;
                    p2=pop();
                    p1=pop();
                    if(p2!=0) push(p1/p2);
                    else printf("impossible operation\n");
                case '.':
                    showStack(stack);
                    break;
                case ' ':
                    buff[i]='\0';
                    push(atoi(buff+1));
                    i=1;
                    break;
                }
            }
        }
        printf("result:%d\n",pop());
        fclose(fp);
    }
    
    if (mode==1) {
        fflush(stdin); //remove \n from the stream
        scanf("%[^\n]%*c",scanned);
        while ((c=scanned[n])!=EOF) {
            if(isdigit(c)||(buff[i-1]<'0'||buff[i-1]>'9')&&c=='-') {
                buff[i]=c;
                i++;
            } else {
                switch(c) {
                case '+':
                    buff[i]='\0';
                    push(atoi(buff+1));
                    i=1;
                    p2=pop();
                    p1=pop();
                    push(p1+p2);
                    break;
                case '-':
                    buff[i]='\0';
                    push(atoi(buff+1));
                    i=1;
                    p2=pop();
                    p1=pop();
                    push(p1-p2);
                    break;
                case '*':
                    buff[i]='\0';
                    push(atoi(buff+1));
                    i=1;
                    p2=pop();
                    p1=pop();
                    push(p1*p2);
                    break;
                case '/':
                    buff[i]='\0';
                    push(atoi(buff+1));
                    i=1;
                    p2=pop();
                    p1=pop();
                    if(p2!=0) push(pop()/p2);
                    else printf("impossible operation\n");
                case '.':
                    showStack(stack);
                    break;
                case ' ':
                    buff[i]='\0';
                    push(atoi(buff+1));
                    i=1;
                    break;
                }
            }
            n++;
        }
        for (int i=0;i<N;i++) {
            printf("%2d",stack[i]);
        }
        /*printf("result:%d\n",pop());*/
    }
    return 0;
}