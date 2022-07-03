/*/Efetua infinas somas ate que o resultado seja 0/*/

#include <stdio.h>
int main() {
 long int a,b,s,x,l;
 char c[21];
 while(1){
  scanf("%d %d",&a,&b);
  if(a==0&&b==0){
   break;
  }
  s=a+b;
  l=sprintf(c,"%d",s);
  c[l+1]='\0';
  for(x=0;x<l;x++){
   if(c[x]!='0'){
    printf("%c",c[x]);
   }
  }
  printf("\n");
 }
 return 0;
}