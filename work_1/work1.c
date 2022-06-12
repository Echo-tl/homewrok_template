#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib> 
#include <ctime>

int count2 = 0;
int count3 = 0;

//冒泡排序
void BubbleSort(int a[],int n){
    int count1 = 0;
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j< n-1-i; j++){
            if(a[j] > a[j+1]){
                count1++;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("冒泡排序的比较次数为：%d\n",count1);
}

//合并排序
int Merge(int a[], int left, int mid, int right){
    int result[right - left];
    int count = 0;
    int k = 0;
    int i = left; //首元素下标
    int j = mid + 1; 
    while(i <= mid && j <= right){
        if(a[i] < a[j]){
            count++;
            result[k++] = a[i++];
        }
        else{
            result[k++] = a[j++];
        }
    }
    if(i == mid+1){
        while(j <= right){
            result[k++] = a[j++];
        }
    }
    if(j == right+1){
        while(i < mid){
            result[k++] = a[i++];
        }
    }
    for(j = 0; i =left, j<k; i++,j++){
        a[i] = result[j];
    }
    return count;
}

//递归调用
void MergeSort(int a[], int left, int right){
    if(left >= right)
        return;
    int mid = (left + right)/2;
    MergeSort(a, left, mid);
    MergeSort(a, mid+1, right);
    count2 += Merge(a, left, mid, right);
}

//快速排序
int partition(int a[], int low, int high){
    int key = a[low];
    while(low < high){
        while(low < high && a[high] >= key){
            count3++;
            high--;
        }
        if(low < high){
            a[low++] = a[high];
        }
        while(low < high && a[low] < key){
            low++;
        }
        if(low < high){
            a[high--] = a[low];
        }
    }
    a[low] = key;
    return low;
}

//快速排序递归调用
void QuickSort(int a[], int start, int end){
    int pos;
    if(start < end){
        pos = partition(a, start, end);
        QuickSort(a, start, pos-1);
        QuickSort(a, pos+1, end);
    }
}

//生成随机数
void random(int a[], int n, int l, int r){
    srand(time(0)); //设置时间种子
    for(int i = 0; i<n; i++){
        a[i] = rand()%(r-l+1)+1; //生成区间r-l的随机数
        printf("%d ",a[i]);
    }
}

int main(){
    int n;
    printf("请输入随机数个数：");
    scanf("%d",&n);
    int a[n],b[n],c[n];
    printf("生成的随机数依次为：\n");
    random(a, n, 0, 32767);
    printf("\n");
    for(int i=0; i<n; i++){
        b[i] = a[i];
        c[i] = a[i];
    }

    BubbleSort(a, n); //测试冒泡排序
    MergeSort(b, 0, n); //合并排序
    printf("合并排序的比较次数：%d\n",count2);
    
    QuickSort(c, 0 ,n); //快速排序
    printf("快速排序比较次数为：%d",count3);
    return 0;
}