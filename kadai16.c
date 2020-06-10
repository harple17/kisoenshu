#include<stdio.h>
#include<string.h>

int mystrcmp(const char *p1, const char *p2) {
    int c_p1=0;
    int c_p2=0;
    while(*(p1+c_p1)!='\0') c_p1++;
    while(*(p2+c_p2)!='\0') c_p2++;
    if (c_p1<c_p2) return -1;
    else if (c_p1>c_p2) return 1;
    else if (c_p1==c_p2) {
        int f=0;
        int f1=0;
        int f2=0;
        while (*(p1+f)==*(p2+f)) f++;
        if (*(p1+f)>='A'&&*(p1+f)<='Z') f1=2;
        if (*(p1+f)>='a'&&*(p1+f)<='z') f1=1;
        if (*(p1+f)>='0'&&*(p1+f)<='9') f1=0;
        if (*(p2+f)>='A'&&*(p2+f)<='Z') f2=2;
        if (*(p2+f)>='a'&&*(p2+f)<='z') f2=1;
        if (*(p2+f)>='0'&&*(p2+f)<='9') f2=0;
        if (f1>f2) return 1;
        if (f1<f2) return -1;
        if (f1==f2) {
            if (*(p1+f)>*(p2+f)) return 1;
            if (*(p1+f)<*(p2+f)) return -1;
            else return 0;
        }
    }

}
void charBubbleSort(char c[100][64],int n) {
    char tmp[64];
    for (int i=0;i<n-1;i++) {
        for (int j=n-1;j>i;j--) {
            if (mystrcmp(c[j-1],c[j])>0) {
                strcpy(tmp,c[j-1]); //swap
                strcpy(c[j-1],c[j]);
                strcpy(c[j],tmp);
            }
        }
    }
}
void charSelectSort(char c[100][64],int n) {
    char tmp[64];
    for (int i=0;i<n-1;i++) {
        int min=i;
        for (int j=i+1;j<n;j++) {
            if (mystrcmp(c[min],c[j])>0) min=j; //rec the index of min
        }
        strcpy(tmp,c[min]); //swap
        strcpy(c[min],c[i]);
        strcpy(c[i],tmp);
    }
}
void charInsertSort(char c[100][64],int n) {
    int j;
    for (int i=1;i<n;i++) {
        char tmp[64];
        strcpy(tmp,c[i]);
        for (j=i;j>0&&(mystrcmp(c[j-1],tmp)>0);j--) { //search insert point
            strcpy(c[j],c[j-1]); //slide
        }
        strcpy(c[j],tmp);
    }
}

int main() {
    char in1[100][64];
    printf("整数を入力してください。入力された整数の分だけ文字列が入力できます。:");
    int n1;
    scanf("%d",&n1);
    for (int i=0;i<n1;i++) { //input strings
        scanf("%s",in1[i]);
    }
    printf("バブルソートの結果\n");
    charBubbleSort(in1,n1);
    for (int i=0;i<n1;i++) { //show result
        printf("%s\n",in1[i]);
    }
    
    char in2[100][64];
    printf("整数を入力してください。入力された整数の分だけ文字列が入力できます。:");
    int n2;
    scanf("%d",&n2);
    for (int i=0;i<n2;i++) {
        scanf("%s",in2[i]);
    }
    printf("選択ソートの結果\n");
    charSelectSort(in2,n2);
    for (int i=0;i<n2;i++) {
        printf("%s\n",in2[i]);
    }
    
    char in3[100][64];
    printf("整数を入力してください。入力された整数の分だけ文字列が入力できます。:");
    int n3;
    scanf("%d",&n3);
    for (int i=0;i<n3;i++) {
        scanf("%s",in3[i]);
    }
    printf("挿入ソートの結果\n");
    charInsertSort(in3,n3);
    for (int i=0;i<n3;i++) {
        printf("%s\n",in3[i]);
    }
    
    return 0;
}