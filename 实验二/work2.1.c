#include<stdio.h>
#include <cstdlib> 
#include <ctime>

int max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

int KnapsackDP(int n, int w[], int v[], int c){
    int m[n+1][c+1]; //表示前i个物品装入容量为j的背包中获得的最大价值
    //初始化
    for(int i=0; i<=n; i++){
        m[i][0] = 0;
    }
    for(int j=0; j<=c; j++){
        m[0][j] = 0;
    }
    for(int i = 1; i<=n; i++){
        for(int j=1; j<=c; j++){
            if(j < w[i-1]){
                m[i][j] = m[i-1][j];
            }
            else{
                m[i][j] = max(m[i-1][j],m[i-1][j-w[i-1]]+v[i-1]);
            }
        }
    }
    return m[n][c];
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
    //定义两个变量
    clock_t start, finish;

    //程序开始之前计时
    start = clock();

    int s; // 获得的最大价值
    int n;
    printf("请输入物品个数：\n");
    scanf("%d",&n);
    int c; //背包最大容量
    printf("请输入背包的最大容量:\n");
    scanf("%d",&c);

    int w[n]; //物品重量
    int v[n]; //物品价值
    
    printf("n个物品的重量为：\n");
    random(w, n, 0, 1000); //生成n个物品的重量
    printf("\n"); 
    
    printf("n个物品的价值为：\n");
    random(v, n, 0, 1000); //生成n个物品的价值
    printf("\n"); 

    s = KnapsackDP(n, w, v, c); //调用函数

    printf("最大物品价值为：\n");
    printf("%d\n",s);

    //程序结束后计时
    finish = clock();
    printf("程序运行时间为: %d s\n", finish - start);

    return 0;
}