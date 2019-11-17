#include<bits/stdc++.h>
using namespace std;
#define NUM_STATION 5

int min(int a, int b) {
 	return a<b ? a:b;
}

int minCostAssembly(int a[][NUM_STATION], int t[][NUM_STATION], 
	int *e, int *x) {
 	int f1[NUM_STATION],f2[NUM_STATION];

	// time taken to reach station S(1,0) line 1
	f1[0] = e[0] + a[0][0];

	// time taken to reach station S(2,0); line 2
	f2[0] = e[1] + a[1][0];

	for(int j=1;j<NUM_STATION;++j) {
	 	f1[j] = min(f1[j-1]+a[0][j],f2[j-1]+t[1][j]+a[0][j]);
		f2[j] = min(f2[j-1]+a[1][j],f1[j-1]+t[0][j]+a[1][j]);
	}

	return min(f1[NUM_STATION-1]+x[0],f2[NUM_STATION-1]+x[1]);
}

int main() {
 	
	// a refers to stations time cost
	int a[][NUM_STATION] = {
	 { 7, 9, 3, 4 ,8} , { 8, 5, 6, 4, 5}
	};
	
	// t refers to transfer to other line cost
	int t[][NUM_STATION] = {
	 { 0, 2, 3, 1, 3}, { 0, 2, 1, 2, 2}
	};

	// e refers to entry time of stations
	int e[] = { 2, 4};

	// x refers to exit times of stations
	int x[] = { 3, 6};

	cout << "Minimum cost for a car is : " << minCostAssembly(a, t, e, x) << "\n";

	return 0;



}
