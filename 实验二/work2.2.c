#include<stdio.h>
#include <cstdlib> 
#include <ctime>

int count1 = 0;
int count2 = 0;

//递归算法
int DAC_f(int n){
    if(n == 1 || n == 2){
        return 1;
    }
    else{
        count1++;
        return DAC_f(n-1) + DAC_f(n-2);
    }
}

//动态规划算法
int DP_f(int n){
   int f[n];
   for(int i=0; i<n; i++){
        f[i] = 0;
   }
   for(int i=1; i<=n; i++){
    if(i == 1 || i ==2){
        f[i] = 1;
    }
    else{
        f[i] = f[i-1] + f[i-2];
        count2++;
    }
   }
   return f[n];
}

int main(){
    int n;
    printf("请输入数列的个数：\n");
    scanf("%d",&n);

    DAC_f(n);//递归算法求斐波那契数列
    printf("递归算法求斐波那契数列加法执行次数：%d\n",count1);

    DP_f(n); //动态规划法求斐波那契数列
    printf("动态规划求斐波那契数列加法执行次数：%d\n",count2);

    return 0;
}