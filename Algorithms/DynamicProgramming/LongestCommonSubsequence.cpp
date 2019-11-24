#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) {
	return (a > b) ? a : b;
}

int lcs(char *X, char *Y, int m, int n) {

	int L[m+1][n+1];
	int i,j;

	for(int i=0;i<=m;i++) {
		for(int j=0;j<=n;j++) {
			if(i == 0 || j == 0)
				L[i][j] = 0;
			else if(X[i-1] == Y[j-1]){
				L[i][j] = L[i-1][j-1] + 1;
			}
			else {
				L[i][j] = max(L[i-1][j],L[i][j-1]);
			}
		}
	}

	return L[m][n];

}

int main() {

	char str1[] = "ABCDGH";
	char str2[] = "AEDFHR";

	int m = strlen(str1);
	int n = strlen(str2);

	cout << "Length of LCS is " << lcs(str1, str2, m, n) << "\n";

	return 0;

}