#include<stdio.h>
#include <cstdlib> 
#include <ctime>
#include<sys/time.h>

//合并排序
void Merge(int a[], int left, int mid, int right){
    int result[right - left];
    int k = 0;
    int i = left; //首元素下标
    int j = mid + 1; 
    while(i <= mid && j <= right){
        if(a[i] > a[j]){
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
}

//递归调用
void MergeSort(int a[], int left, int right){
    if(left >= right)
        return;
    int mid = (left + right)/2;
    MergeSort(a, left, mid);
    MergeSort(a, mid+1, right);
    Merge(a, left, mid, right);
}

int KnapsackGreedy(int p[], int w[], int x[], int n, int M){
    for(int i=0; i<n; i++){
        x[i] = 0; //初始化，未装入背包
    }
    float cu = M; //更新背包容量
    int i;
    for(i=0; i<n; i++){
        if(cu < p[i]){
            break;
        }
        x[i] = 1;
        cu = cu -w[i];
    }
    if(i <= n){
        x[i] = cu/w[i];
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
    //定义两个结构体
    struct timeval start;
    struct timeval end;
    unsigned long timer;

    //程序开始之前计时
    gettimeofday(&start, NULL);

    int s; // 获得的最大价值
    int n;
    printf("请输入物品个数：\n");
    scanf("%d",&n);
    int c; //背包最大容量
    printf("请输入背包的最大容量:\n");
    scanf("%d",&c);
    
    int w[n]; //物品重量
    int v[n]; //物品价值
    int p[n]; //单位价值重量
    int x[n]; //解向量
    
    printf("n个物品的重量为：\n");
    random(w, n, 0, 2000); //生成n个物品的重量
    printf("\n"); 
    
    printf("n个物品的价值为：\n");
    random(v, n, 0, 2000); //生成n个物品的价值
    printf("\n"); 

    for(int i=0; i<n; i++){
        p[i] = v[i] / w[i];
    }

    MergeSort(p, 0, n); //调用合并排序

    KnapsackGreedy(p, w, x, n, c); //调用贪心算法

    //程序结束后计时
    gettimeofday(&end, NULL);
    timer = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec ;
    printf("time = %ld us\n", timer);

    return 0;
}