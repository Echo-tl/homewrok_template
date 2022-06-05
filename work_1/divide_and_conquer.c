#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static long seed = 13;
static long a;
static long c;
static long m;

//冒泡排序
void BubbleSort(int a[],int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j< n-1-i; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

//合并排序
void Merge(int a[], int left, int mid, int right){
    int result[right - left];
    int k = 0;
    int i = left; //首元素下标
    int j = mid + 1; 
    while(i <= mid && j <= right){
        if(a[i] < a[j]){
            result[k++] = a[i++];
        }
        else{
            reslut[k++] = a[j++];
        }
    }
    if(i == mid+1){
        while(j <= right){
            reslut[k++] = a[j++];
        }
    }
    if(j == right+1){
        while(i < mid){
            reslut[k++] = a[i++];
        }
    }
    for(j = 0; i =left; j<k; i++,j++){
        a[i] = result[j];
    }
}

//递归调用
void MergeSort(int a[], int left, int right){
    if(left >= right)
        return;
    int mid = (left + right)/2;
    MergeSort(a, left, mid);
    MergeSort(a, mid+1， right);
    Merge(a, left, mid, right);
}

//快速排序
int partition(int a[], int low, int high){
    int key = a[low];
    whiel(low < high){
        while(low < high && a[high] >= key){
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
    retur low;
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

//线性同余生成随机数
long random(){
    seed = (a * seed +c)%m;
    return seed;
}