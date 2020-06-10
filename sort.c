#include<stdio.h>

/*void sort_as(int a[],int size) sort in ascending order
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
}*/

void sort(int a[],int n){

    // 最後の要素を除いて、すべての要素を並べ替えます
    for(int i=0;i<n-1;i++){
        
      // 下から上に順番に比較します
        for(int j=n-1;j>i;j--){

	        // 上の方が大きいときは互いに入れ替えます
	        if(a[j]<a[j-1]){
	            int t=a[j];
	            a[j]=a[j-1];
	            a[j-1]=t;
            }
        }
        for (int j=0;j<n;j++) {
            printf("%d ",a[j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[]={4,1,9,12,8,2,5,11,6,3};
    sort(a,10);
    return 0;
}