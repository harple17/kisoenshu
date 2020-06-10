#include<stdio.h>
#include<math.h>
#undef complex

struct complex {
    double re;
    double im;
};

struct complex conj (struct complex in) {
    struct complex out;
    out.re = in.re;
    out.im = -in.im;
    return out;
}

double carg (struct complex in) {
    if (in.re== 0 && in.im==0) return -1;
    else return atan(in.im/in.re)*180/(atan(1.0)*4);
} 

double cabs (struct complex in) {
    return sqrt(in.re*in.re+in.im*in.im);
}

int main() {

    struct complex in;

    printf("複素数を入力してください。(入力される実数をa,bとすると、a+bi(iは虚数単位)と解釈されます。)\n");
    scanf("%lf%lf",&in.re,&in.im);
    if (conj(in).im==0) {
        printf("共役な複素数は%.1lfです。\n",conj(in).re);
    } else if (conj(in).re==0) {
        printf("共役な複素数は%.1lfiです。\n",conj(in).im);
    } else if (conj(in).im>0) {
        printf("共役な複素数は%.1lf+%.1lfiです。\n",conj(in).re,conj(in).im);
    } else {
        printf("共役な複素数は%.1lf%.1lfiです。\n",conj(in).re,conj(in).im);
    }
    if (carg(in)!=-1) printf("偏角は%.1lf°です。\n",carg(in));
    else printf("偏角は定義されていません。\n");
    printf("絶対値は%.1lfです。\n",cabs(in));

    return 0;
}