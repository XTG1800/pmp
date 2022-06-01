#include<stdio.h>

void qsort(int a[], int left, int right)
{
    if(left>right) //递归的基线条件
    {
        return;
    }

    int pivot = a[left]; //以左边第一个数为基准数
    int temp = 0;
    int i = left;
    int j = right;

    while(i!=j)
    {
        while(i<j && a[j]>=pivot) //要从右边开始找
        {
            j--;
        }
        while(i<j && a[i]<=pivot)
        {
            i++;
        }
        if(i<j) //交换两个数在数组中的位置
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    //最终将基准数归位
    a[left] = a[i];
    a[i] = pivot;

    qsort(a,left,i-1); //继续处理左分区
    qsort(a,j+1,right); //继续处理右分区
}

int main()
{
    int a[] = {5,2,3,4,0,9,8,7,1,6};
    int length = sizeof(a)/sizeof(int);
    qsort(a,0,length-1);
    for(int i=0;i<length;i++)
    {
        printf("a[%d] = %d\n",i,a[i]);
    }
    return 0;
}
