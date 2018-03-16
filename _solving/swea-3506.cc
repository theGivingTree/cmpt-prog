#include <cstdio>
#include <vector>
#include <tuple>
#include <utility>
using namespace std;
using LL = long long;

vector<LL> S;
vector<LL> mergeBuf;
int N, P;

/* Find lower-bound L where S*[L] + det >= 0 */
int bs(int lo, int up, LL det) {
	while(up-lo>0) {
		int m = (lo+up-1)/2;
		if(S[m] + det < 0) lo = m+1;
		else up = m;
	}
	return lo;
}

tuple<LL, LL> dnq(int lo, int up) {
	LL count = 0, sum = 0;
	if(up - lo < 4) {
		for(int i=lo; i<up; ++i) {
			LL s = 0LL;
			for(int j=i; j<up; ++j) {
				s += S[j];
				count += (s - P*(j-i+1)) >= 0;
			}

			sum += S[i];
			S[i] = sum - P*(i-lo+1);
			for(int j=i; j>lo; --j) {
				if(S[j-1] > S[j]) {
					swap(S[j-1], S[j]);
				}
			}
		}
		/* S[lo, up) -> S*[lo, up): no original array S */
		/* S*[lo, up) consists of each determinant of S[lo, I) where I∈[lo, up)*/
		return make_tuple(count, sum);
	}

	LL lCount, rCount, lSum, rSum;
	int m = (up+lo)/2;
	tie(lCount, lSum) = dnq(lo, m);
	tie(rCount, rSum) = dnq(m, up);
	sum = lSum + rSum;

	/* Rearrange left half */
	LL detL = lSum - P*(m-lo);
	for(int i=lo; i<m-1; ++i) {
		int t = S[lo];
		S[lo] = detL - S[m-2-(i-lo)];
		S[m-2-(i-lo)] = detL - t;
	}

	/* Count Phase */
	for(int i=lo, nm=m; i<m && nm<up; ++i) {
		int lowB = bs(nm, up, S[i]);
		count += up - lowB;
		nm = lowB;
	}

	/* Merge Phase */
	if(up-lo != N) {
		int i=lo, j=m, k=0;
		while(i<m && j<up) mergeBuf[k++] = S[i] < detL + S[j] ? S[i++] : detL + S[j++];
		while(i<m) mergeBuf[k++] = S[i++];
		while(j<up) mergeBuf[k++] = detL + S[j++];

		for(int i=lo; i<up; ++i) {
			S[i] = mergeBuf[i-lo];
		}
	}

	return make_tuple(lCount + count + rCount, sum);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t) {
		scanf("%d %d", &N, &P);
		S.resize(N);
		mergeBuf.resize((N+1)/2);
		for(int i=0; i<N; ++i) {
			scanf("%lld", &S[i]);
		}
		LL answ;
		answ = get<0>(dnq(0, N));
		printf("#%d %lld\n", t, answ);
	}
	return 0;
}