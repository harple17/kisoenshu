#include<stdio.h>

void upper_prnt(const char *p) {
    char prnt[64];
    int i=0;
    while ((*(p+i))!='\0') {
        prnt[i]=*(p+i);
        if (*(p+i)<='z'&&*(p+i)>'Z') {
            prnt[i]-='a'-'A';
        }
        i++;
    }
    prnt[i]='\0';
    printf("%s",prnt);
}
void lower_prnt(const char *p) {
    char prnt[64];
    int i=0;
    while ((*(p+i))!='\0') {
        prnt[i]=*(p+i);
        if (*(p+i)<'a'&&*(p+i)>='A') {
            prnt[i]+='a'-'A';
        }
        i++;
    }
    prnt[i]='\0';
    printf("%s",prnt);
}
void help() {
    printf("コンソールにおいてこのプログラムの実行命令をする際に、\n実行コマンドの後に1つスペースを空けて第一引数、もう1つスペースを空けて第二引数を入力してください。\n第一引数は動作モードの入力、第二引数は文字列の入力です。\n第一引数として有効なのは以下の3つで、その機能を示します。\n\n-u:第二引数として入力された文字列中のアルファベットをすべて小文字にして出力します。\n-l:第二引数として入力された文字列中のアルファベットをすべて大文字にして出力します。\n-h:この通り利用方法を出力します。\n");
}

int main(int argc, char *argv[]) {
    if (argc>3) {
        printf("引数が3つ以上あります。");
        return 0;
    }
    if (*argv[1]=='-'&&*(argv[1]+1)=='u') {
        upper_prnt(argv[2]);
    }
    else if (*argv[1]=='-'&&*(argv[1]+1)=='l') {
        lower_prnt(argv[2]);
    }
    else if (*argv[1]=='-'&&*(argv[1]+1)=='h') {
        help();
    }
    return 0;
}