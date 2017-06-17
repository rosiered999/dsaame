#include<stdio.h>

int fact(int N)
{
    if(N==1||N==0)
        return 1;
    else return N*fact(N-1);
}

int main()
{
    int N;
    scanf("%d",&N);
    int M;
    M = fact(N);
    printf("%d\n", M);
}
