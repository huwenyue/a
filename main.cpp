#include <stdio.h>
#include <stdlib.h>
#define max 4
//sum 用于描述解的可能个数
int queen[max], sum=0; //max为棋盘最大坐标
void show(){
    int i;  //行数为i，queen[i]表示当前行元素所处的列数
    printf("(");
    //注意此处下标从0开始
    for (i=0; i<max; i++) {
        printf("%d",queen[i]+1);   //数组queen[i]从0开始，但棋盘列数从1开始
    }
    printf(")\n");
    //每次输出一种解时，它的解的数量就会增加1
    sum++;
}

//判断当前皇后是否可以放在此位置
int place(int n){
    int i;
    for (i=0; i<n; i++) {
        if (queen[i]==queen[n]||abs(queen[i]-queen[n])==abs(i-n)) {
            //判断皇后是否在同一列或同一对角线
            return 0;
        }
    }
    return 1;
}
//回溯法
void nqueens(int n){
    //n 为横坐标
    int i;
    for (i=0; i<max; i++) {
        queen[n]=i; //将皇后摆到当前循环到的位置
        if (place(n)) {
            if (n==max-1) {
                show(); //若全部摆好，则输出所有皇后的坐标
            }
            else{
                nqueens(n+1);  //否则继续摆放下一个皇后
            }
        }
    }
}
int main(){
    nqueens(0); //从横坐标为0开始
    printf("总共的解法有%d\n",sum);
    return 0;
}
