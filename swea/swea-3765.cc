#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAX_LEN 1000000

int go(int N, char M[]) {
	vector<int> f(N);
	f[0]=-1;
	int i=0, j=-1;
	while(i<N) {
		while(j>-1 && M[i]!=M[j]) j=f[j];
		++i, ++j;
		f[i]=j;
	}
	return i-j;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t) {
		int N;
		char M[MAX_LEN+1];
		scanf("%d %s", &N, M);
		printf("#%d %d\n", t, go(N, M));
	}
	return 0;
}