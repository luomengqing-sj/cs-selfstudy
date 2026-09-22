#include<cstdio>
#include<cstdlib>
int main(){
    int*a=(int*)malloc(4*sizeof(int));
    a[4]=42;
    printf("%d\n",a[4]);
    free(a);
    return 0;



}
