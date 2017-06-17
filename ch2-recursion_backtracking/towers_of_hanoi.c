#include<stdio.h>

//pattern over here is:
//shift 'n-1' disks from A to B
//shift last disk from A to C
//shift 'n-1' disks from B to C


void hanoi(int N,char frompeg, char topeg, char auxpeg)
{
    if(N==1)
        printf("moving %d disks from %c to %c\n", N, frompeg,topeg);
    else
    {
        hanoi(N-1,frompeg,auxpeg,topeg);
        printf("moving %d disks from %c to %c\n", N, frompeg,topeg);
        hanoi(N-1,auxpeg,topeg,frompeg);
        
    }
}

int main()
{
   char topeg[1], frompeg[1], auxpeg[1];
   int N;
   scanf("%d %c %c %c", &N,frompeg,auxpeg,topeg);
   hanoi(N,frompeg[0],topeg[0],auxpeg[0]);
}
