#include <cstdio>
using namespace std;
int N;
char S[10][10], sn[10];
int lo[10], up[10];
int main() {
  scanf("%d ", &N);
  for(int i=0; i<N; ++i) {
    lo[i] = 0, up[i] = 10;
    for(int j=i; j<N; ++j) {
      S[i][j] = getchar();
    }
    sn[i] = S[i][i];
    if(S[i][i] != '0') lo[i] = 1, up[i] = 10;
    else up[i] = 0;
  }
  for(int rp=0; rp<N-1; ++rp) {
    for(int i=0; i<N-1; ++i) {
      int x = i, y = i+1;
      char a = S[x][y];
      if(sn[x] != '0' && sn[y] != '0' && sn[x] != sn[y]) {
        if(a != '0') {
          if(a == sn[y]) x = i+1, y = i;
          lo[x] = lo[y] + 1; up[y] = up[x] - 1; // ay < ax
        }
        else {
          lo[x] = lo[y] = lo[x] > lo[y] ? lo[x] : lo[y];
          up[x] = up[y] = up[x] < up[y] ? up[x] : up[y];
        }
      }
    }
    for(int e=2; e<N; ++e) {
      for(int i=0; i<N-e; ++i) {
        int x = i, y = i+e;
        if(sn[x] == sn[y] && sn[x] != '0') {
          if(S[x][y-1] != S[x+1][y]) {
            if(sn[x] == S[x+1][y]) x = i+e, y = i;
            lo[x] = lo[y] + 1; up[y] = up[x] - 1;
          }
          else if(S[x][y-1] == '0') {
            lo[x] = lo[y] = lo[x] > lo[y] ? lo[x] : lo[y];
            up[x] = up[y] = up[x] < up[y] ? up[x] : up[y];
          }
        }
        if(S[x][y] == '0') {
for(int rp=0; rp<N-1; ++rp) {
          int ss = 0;
          for(int q=x; q<=y; ++q) {
            int a = lo[x];
            if(sn[a] == '-') a=-a;
            ss += a;
          }
          if(ss > 0) {
            while(ss) {
              int idx = 99, val = 99;
              for(int q=x; q<=y; ++q) {
                if(sn[q] == '-' && val > up[q] - lo[q] && up[q] - lo[q] >= 1) {
                  idx = q;
                  val = up[q] - lo[q];
                }
              }
              ++lo[idx];
              --ss;
            }
          }
          else if(ss < 0) {
            while(ss) {
              int idx = 99, val = 99;
              for(int q=x; q<=y; ++q) {
                if(sn[q] == '+' && val > up[q] - lo[q] && up[q] - lo[q] >= 1) {
                  idx = q;
                  val = up[q] - lo[q];
                }
              }
              ++lo[idx];
              ++ss;
            }
          }
        }
}
      }
    }
  }
  for(int i=0; i<N; ++i) {
    printf("[%d, %d]\n", lo[i], up[i]);
  }
  for(int i=0; i<N; ++i) {
    int a=lo[i];
    if(S[i][i] == '-') a=-a;
    printf("%d ", a);
  }
  return 0;
}
