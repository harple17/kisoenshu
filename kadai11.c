#include<stdio.h>
#include<string.h>
#define NUM_OF_STUDENT 5

typedef struct {
    char stdnt_num[32];
    char fam_name[32];
    char fst_name[32];
    char ph_num[16];
    char pst_code[8];
} personal_data; 

void search_data(personal_data data[NUM_OF_STUDENT], const char srch[32], int n, int result[NUM_OF_STUDENT]) {
    /*personal_data型の構造体配列のポインタを引数として取り、
    personal_data中の指定された項目ににsrchと同じ文字列があれば、resultに構造体配列の何番目か記録する関数*/
    switch (n) {
    case 0:
        for (int i=0;i<NUM_OF_STUDENT;i++) {
            if (strcmp(((data+i)->stdnt_num),srch)==0) {
                (*(result+i))++;
                continue;
            }
        }
        break;
    case 1:
        for (int i=0;i<NUM_OF_STUDENT;i++) {
            if (strcmp(((data+i)->fam_name),srch)==0) {
                (*(result+i))++;
            continue;
            }
        }
        break;
    case 2:
        for (int i=0;i<NUM_OF_STUDENT;i++) {
            if (strcmp(((data+i)->fst_name),srch)==0) {
                (*(result+i))++;
            continue;
            }
        }
        break;
    case 3:
        for (int i=0;i<NUM_OF_STUDENT;i++) {
            if (strcmp(((data+i)->ph_num),srch)==0) {
                (*(result+i))++;
            continue;
            }
        }
        break;
    case 4:
        for (int i=0;i<NUM_OF_STUDENT;i++) {
            if (strcmp(((data+i)->pst_code),srch)==0) {
                (*(result+i))++;
                continue;
            }
        }
        break;
    }
}

int main() {
    personal_data data[NUM_OF_STUDENT] = {
        {"01C00000","Akashi","Tomohiro","0120111111","2100082"},
        {"03G12124","Tanimoto","Yoko","0707897564","5210332"},
        {"07U12312","Tanimoto","Tomohiro","08099224455","5056532"},
        {"08T00101","Kiritani","Shunsuke","070765268933","5210332"},
        {"09C19143","Takeda","Akashi","88887665432","5210332"}
    };
    
    printf("検索する項目を選択してください。0:学籍番号 1:氏 2:名 3:電話番号 4:郵便番号");
    int n;
    scanf("%d",&n);
    printf("検索：");
    char srch[32];
    int result[NUM_OF_STUDENT]={0};
    scanf("%s",srch);
    search_data(data,srch,n,result);
    int cnt=0;
    for (int i=0;i<NUM_OF_STUDENT;i++) {
        if (result[i]!=0) {
            printf("該当%d人目\n学籍番号：%s\n氏：%s\n名：%s\n電話番号：%s\n郵便番号：%s\n",cnt+1,data[i].stdnt_num,data[i].fam_name,data[i].fst_name,data[i].ph_num,data[i].pst_code);
            cnt++;
        }
    }
    return 0;
}