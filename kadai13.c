#include<stdio.h>

char *searchWord(const char *str1, const char *str2, int num) {
    char *p=NULL;
    int size=0;
    while (*(str2+size)!='\0') {
        size++;
    }
    int count=0;
    int flag=0;
    for  (int i=0;*(str1+i)!='\0';i++) {
        if (*(str1+i)==*str2) {
            for (int j=0;j<size;j++) {         
                if (*(str1+i+j)!=*(str2+j)) {
                    break;
                }
                if (j==size-1) {
                    count++;
                    flag=0;
                }
            }           
        }
        if (count==num&&flag==0) {
            p=(char*)str1+i;
            flag=1;
        }
    }
    if (count<num) {
        printf("2つめの文字列の出現回数(%d)が指定された整数より小さいです。",count);
        p=NULL;
    }
    return p;
}

int main() {
    char in1[128],in2[128];
    int n;
    printf("文字列2つと1以上の整数を入力してください。1つめの文字列中に2つめの文字列が含まれれば、その先頭から表示します。\n(ただし、2つめの文字列が複数含まれる場合は指定された整数番目から表示します。)\n");
    scanf("%s %s %d",in1,in2,&n);
    printf("%s\n",searchWord(in1,in2,n));

    return 0;
}