#include<stdio.h>
#include<math.h>

void sort_as(int a[],int size) /*昇順にソート*/
{
    int tmp;
    for (int i=0;i<size-1;i++) {
        for (int j=i+1;j<size;j++) {
            if (a[i]>a[j]) {
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
}
void print_hist(int a[],int size)/*100点満点のテストを20点区切りにしたヒストグラムを表示*/
{
    int count[5]={0};
    for (int i=0;i<5;i++) {
        for (int j=0;j<size;j++) {
            if (i<4) {
                if (20*i<=a[j]&&a[j]<20*(i+1)) {
                    count[i]++;
                }                
            } else {
                /*0~79とは違って最後は一の位が9ではない*/
                if (20*i<=a[j]&&a[j]<=20*(i+1)) {
                    count[i]++;
                }
            }
        }
    }
    for (int i=0;i<5;i++) {
        if (i<4) {
            printf("%-3d-%3d:",i*20,(i+1)*20-1);
        } else {
            /*0~79とは違って最後は一の位が9ではない*/
            printf("%-3d-%3d:",i*20,(i+1)*20);
        }
        for (int j=0;j<count[i];j++) printf("*");
        printf("\n");
    }
}
void print_representative(int a[],int size)/*代表値を表示*/
{
    int s=0; 
    for (int i=0;i<size;i++) {
        s+=a[i];
    }
    double ave=s/size;

    sort_as(a,size);/*最高点と最低点、最頻値の計算をしやすくする*/

    double med; 
    if (size%2==0) med=((a[size/2-1]+a[size/2])/2.0);
    else med=a[size/2];

    int mode[30];
    /*複数の最頻値が現れる場合の処理も含める*/
    int count_max=0;
    int count=0;
    int index=0;
    for (int i=0;i<size;i++) {
        /*昇順ソートしているので同じ値は連続している.隣を見ていけば同じ値の連続数が算出できる*/
        if (a[i]==a[i+1]) count++;
        else count=0;
        if (count==count_max) { /*連続数が記録されている最大の連続数と同じとき追加*/
            mode[index]=a[i];
            index++;
        } else if (count>count_max) { /*連続数が記録されている最大の連続数より大きいとき更新*/
            count_max=count;
            mode[0]=a[i];
            index=1;
        }
    }
    printf("平均点:%.1f\n最高点:%d\n最低点:%d\n中央値:%.1f\n最頻値:",ave,a[size-1],a[0],med);
    for (int i=0;i<index;i++) {
        printf("%d ",mode[i]);
    }
    printf("\n");
}
void print_std(int a[],int size)
{
    int s=0;
    for (int i=0;i<size;i++) {
        s+=a[i];
    }
    double ave=s/size;

    double s2=0;
    for (int i=0;i<size;i++) {
        s2+=(a[i]-ave)*(a[i]-ave);
    }
    printf("標準偏差:%.1f",sqrt(s2/(size-1)));
}
int main()
{
    int score[30]={1,2,3,4,5,6,7,8,9,10,32,66,77,88,20,62,11,24,21,95,35,23,49,87,98,22,65,92,96,54};
    print_hist(score,30);
    print_representative(score,30);
    print_std(score,30);
    return 0;
}