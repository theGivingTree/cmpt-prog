#include <cstdio>
#include <cstring>
using namespace std;
int TC;
int D, W, K;
unsigned char Alayer[20], Blayer[20];
unsigned char layers[14][20], layers_[14][20];
int ans;
void go(int end, int n_adm) {
  if(ans < n_adm) return;
  if(end == D) {
    for(int j=0; j<W; ++j) {
      unsigned char c=255;
      int n=0, mn=0;
      for(int i=0; i<=D; ++i) {
        if(layers_[i][j] != c) {
          if(mn < n) mn = n;
          c = layers_[i][j];
          n = 1;
        }
        else ++n;
      }
      if(mn < K) return;
    }
    ans = n_adm;
    return;
  }

  go(end+1, n_adm);
  memcpy(layers_[end], Alayer, W);
  go(end+1, n_adm+1);
  memcpy(layers_[end], Blayer, W);
  go(end+1, n_adm+1);
  memcpy(layers_[end], layers[end], W);
}
int main() {
  for(int i=0; i<20; ++i) {
    Blayer[i] = 1;
  }
  scanf("%d", &TC);
  for(int tc=1; tc<=TC; ++tc) {
    scanf("%d %d %d", &D, &W, &K);
    for(int i=0; i<D; ++i) {
      for(int j=0; j<W; ++j) {
        int a;
        scanf("%d", &a);
        layers[i][j] = a;
        layers_[i][j] = a;
      }
    }
    for(int j=0; j<W; ++j) {
      layers[D][j] = 255;
      layers_[D][j] = 255;
    }
    ans = 0x7fFFffFF;
    go(0, 0);
    printf("#%d %d\n", tc, ans);
  }
  return 0;
}

