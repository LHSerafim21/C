#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int max(int a, int b){
	return (a>b) ? a:b;
}

void lcs(char *s1, char *s2, int m, int n){
	int dp[m+1][n+1];

	for(int i = 0; i<= m; i++){
		for(int j = 0; j<= n; j++){
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}

	int index = dp[m][n];
	char lcs[index+1];
	lcs[index]= '\0';

	int i=m,j=n;
	while (i>0 && j>0){
		if(s1[i-1]==s2[j-1]){
			lcs[index-1]=s1[i-1];
			i--;
			j--;
			index--;
		}else if (dp[i-1][j]>dp[i][j-1]){
			i--;
		}else{
			j--;
		}
	}

	printf("LCS: %s\n",lcs);
}

int main(){
	char s1[MAX_LEN];
	char s2[MAX_LEN];

	printf("Digite a primeira String: ");
	scanf("%s",s1);

	printf("Digite a segunda String: ");
	scanf("%s",s2);

	int m = strlen(s1);
	int n = strlen(s2);

	lcs(s1,s2,m,n);

	return 0;
}

