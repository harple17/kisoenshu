#include<stdio.h>

struct rational {
    int num;
    int denum;
};

int gcd(int a,int b) {
    if (b==0) return a;
    else return gcd(b,a%b);
}
struct rational add(struct rational in1,struct rational in2){
    struct rational out;
    out.denum=in1.denum*in2.denum;
    out.num=in1.num*in2.denum+in2.num*in1.denum;
    int GCD = gcd(out.num,out.denum);
    out.denum/=GCD;
    out.num/=GCD;
    if (out.denum<0) {
        out.num*=-1;
        out.denum*=-1;
    }
    return out;
}
struct rational sub(struct rational in1,struct rational in2){
    struct rational out;
    out.denum=in1.denum*in2.denum;
    out.num=in1.num*in2.denum-in2.num*in1.denum;
    int GCD = gcd(out.num,out.denum);
    out.denum/=GCD;
    out.num/=GCD;
    if (out.denum<0) {
        out.num*=-1;
        out.denum*=-1;
    }
    return out;
}
struct rational mul(struct rational in1,struct rational in2) {
    struct rational out;
    out.denum = in1.denum*in2.denum;
    out.num = in1.num*in2.num;
    int GCD = gcd(out.num,out.denum);
    out.denum/=GCD;
    out.num/=GCD;
    if (out.denum<0) {
        out.num*=-1;
        out.denum*=-1;
    }
    return out;
}
struct rational div(struct rational in1,struct rational in2) {
    struct rational out;
    out.denum = in1.denum*in2.num;
    out.num = in1.num*in2.denum;
    int GCD = gcd(out.num,out.denum);
    out.denum/=GCD;
    out.num/=GCD;
    if (out.denum<0) {
        out.num*=-1;
        out.denum*=-1;
    }
    return out;
}

int main() {
    struct rational in1;
    struct rational in2;
    do {
        printf("分数を二つ入力して下さい。(入力される整数を順にa,b(≠0),c,d(≠0)とするとa/b,c/dの分数と解釈されます。)\n");
        scanf("%d",&in1.num);
        scanf("%d",&in1.denum);
        scanf("%d",&in2.num);
        scanf("%d",&in2.denum);
    } while (in1.denum==0||in2.denum==0);
    
    printf("%d/%d+%d/%d=%d/%d\n",in1.num,in1.denum,in2.num,in2.denum,add(in1,in2).num,add(in1,in2).denum);
    printf("%d/%d-%d/%d=%d/%d\n",in1.num,in1.denum,in2.num,in2.denum,sub(in1,in2).num,sub(in1,in2).denum);
    printf("%d/%d×%d/%d=%d/%d\n",in1.num,in1.denum,in2.num,in2.denum,mul(in1,in2).num,mul(in1,in2).denum);
    printf("%d/%d÷%d/%d=%d/%d\n",in1.num,in1.denum,in2.num,in2.denum,div(in1,in2).num,div(in1,in2).denum);
    return 0;
}