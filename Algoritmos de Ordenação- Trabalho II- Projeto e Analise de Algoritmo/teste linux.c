#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cost=0;
int main(){
int numcity ,a[151][151],visited[151],worthless,city1,city2,distance;
char citystring[2];
  a[1][1]=0;
  while(scanf("%s",citystring) != EOF){
  if(strcmp(citystring, "c") == 0){
    scanf("%d", &worthless);
    numcity++;
    }
  else if(strcmp(citystring, "a") == 0){
    scanf("%d %d %d",&city1,&city2,&distance);
    a[city1][city2] = distance;
    a[city2][city1] = distance;
    }
  }
  mincost(1,numcity,a,visited);
  printf("The minimum cost tour is %d",cost);

  return 0;
}

int mincost(int city,int n,int a[151][151],int visited[151]){
int i,ncity;
  visited[city]=1;
  printf("%d->",city);
  ncity=least(city,n,a,visited);
  if(ncity==999999){
    ncity=1;
    printf("%d",ncity);
    cost+=a[city][ncity];
  }
  mincost(ncity,n,a,visited);
}

int least(int c,int n,int a[151][151],int visited[10]){
int i,nc=999999,min=999999,kmin;
  for(i=1;i<=n;i++){
    if((a[c][i]!=0)&&(visited[i]==0)){
      if(a[c][i]<min){
        min=a[i][1]+a[c][i];
        kmin=a[c][i];
        nc=i;
      }
    }
  }
  if(min!=999999)
    cost+=kmin;
    return nc;
}
