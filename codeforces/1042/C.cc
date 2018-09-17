#include <cstdio>
#include <vector>
using namespace std;
int n, aa[200000];
vector<int> negs, zeros, poss;
int main() {
  int i, sz;
  scanf("%d", &n);
  int neghere = 0, poshere = 0, nickme = 0;
  bool oddneg = false;

  int negmax = 0x80000000;
  for(i=1; i<=n; ++i) {
    int a;
    scanf("%d", &a);
    if(a<0) {
      if(negmax < a) {
        nickme = i;
        negmax = a;
      }
      negs.push_back(i);
    }
    else if(a==0) zeros.push_back(i);
    else poss.push_back(i);
  }

  sz = poss.size();
  if(sz > 0) {
    poshere = poss[sz-1];
    for(i=1; i<sz; ++i) {
      printf("1 %d %d\n", poss[i-1], poss[i]);
    }
  }

  sz = negs.size();
  if(sz > 1) {
    int pr;

    if(sz%2 == 1) oddneg = true;
    else nickme = 0;

    if(oddneg && nickme == negs[0]) pr = 1;
    else pr = 0;
    for(i=pr+1; i<sz; ++i) {
      if(oddneg && nickme == negs[i]) continue;
      printf("1 %d %d\n", negs[pr], negs[i]);
      pr = i;
    }
    neghere = negs[pr];
  }

  sz = zeros.size();
  if(sz > 0) {
    int pidx;

    i = 1; pidx = zeros[0];
    if(nickme != 0) {
      i = 0; pidx = nickme;
    }
    for(; i<sz; ++i) {
      printf("1 %d %d\n", zeros[i], pidx);
    }
    nickme = pidx;
  }

  if(nickme != 0 && (poshere != 0 || neghere != 0)) {
    printf("2 %d\n", nickme);
  }

  if(neghere != 0 && poshere != 0) {
    printf("1 %d %d\n", neghere, poshere);
  }

  return 0;
}
