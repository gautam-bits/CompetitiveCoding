#include<stdio.h>

int  main() {
    int x,y,z,i,j,k;
    i = 1;j=2;k=3;
    z = i-1 && j++ < k;
    x = y = z -= 1;
    ++x && ++y && ++z;
    printf("x=%d,y=%d,z=%d\n",x,y,z);
}