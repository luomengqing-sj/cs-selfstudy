#include<stdio.h>
int sum_a(int(*rmp)[4],int n);
int ave_a(int(*rmp)[4],int n,int j);
int max_a(int(*rmp)[4],int n);


int main(void){
int n;
scanf("%d",&n);
int rmp[n+1][4];
for(int i=0;i<n;i++){
for(int j=0;j<4;j++){
scanf("%d",&rmp[i][j]);
}
}
printf("%d\n",sum_a(rmp,n));
for(int j=0;j<4;j++){
printf("%d ",ave_a(rmp,n,j));
}
printf("\n%d",max_a(rmp,n));




return 0;
}
int sum_a(int(*rmp)[4],int n){
int sum=0;
for(int i=0;i<n;i++){
for(int j=0;j<4;j++){
sum+=rmp[i][j];
}
}
return sum;
}
int ave_a(int(*rmp)[4],int n,int j){
int sum=0;
for(int i=0;i<n;i++){
sum+=rmp[i][j];
}
return sum/n;
}
int max_a(int(*rmp)[4],int n){
int maxn=0,maxs=-1;
for(int i=0;i<n;i++){
for(int j=0;j<4;j++){
if(rmp[i][j]*(1-2*(rmp[i][j]<0))>maxs)maxn=j;
}
}
return maxn;
}



