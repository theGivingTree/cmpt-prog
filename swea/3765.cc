#include <cstdio>
using namespace std;
#define MAX_LEN 1000000

int T, N;
char M[MAX_LEN];
int *f = new int[MAX_LEN];

int go() {
	f[0]=-1;
	int i=0, j=-1;
	for(i=0, j=-1; i<N; f[++i]=++j) {
		while(j>-1 && M[i]!=M[j]) j=f[j];
	}
	return i-j;
}

int main() {
	scanf("%d", &T);
	for(int t=1; t<=T; ++t) {
		scanf("%d ", &N);
		fread(M, 1, N, stdin);
		printf("#%d %d\n", t, go());
	}
	return 0;
}