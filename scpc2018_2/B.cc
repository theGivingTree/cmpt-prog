#include <iostream>
using namespace std;
int T, test_case;
int N;
struct AA {
  y, w;
  bool operator()(AA a, AA b) const {
    return a.y < b.y;
  }
} aaa[10000];
int dp[10000][10000];
int S[10001];
int main() {
  cin >> T;
  for(int test_case=1; test_case<=T; ++test_case) {
    int i, j;
    cin >> T;
    S[0]  =0;
    for(i=0; i<N; ++i) {
      int x, y, w;
      cin >> x >> y >> w;
      AA.y = y;
      AA.w = w;
    }
    sort(aaa, aaa+N);
  }
  for(i=1; i<=N; ++i) {
    S[i] = aaa[i].w;
  }

  for(j=0; j<N; ++j) {
    int bot, top, yy;
    bot = aaa[j].y - S[j+1];
    top = aaa[j].y - S[j+1] + S[0];
    yy = aaa[0].y;

    if(bot<= yy & yy <= top)  dp[0][j]=1;
    else dp[0][j]=0;
  }

  for(i=1; i<N; ++i) {
    for(j=0; j<N; ++j) {
      int bot, top, yy;
      bot = aaa[j].y + S[i] - S[j];
      top = aaa[j].y + S[i+1] - S[j];
      yy = aaa[i].y;

      if(bot<= yy & yy <= top)  dp[i][j]=d[i-1][j]+1;
      else d[i][j] = d[i-1][j];

      for(k=0; k<N; ++k) {
        if(aaa[k] - S[k+1] > aaa[j] - S[j+1]) continue;
        if(i<=j) continue;
      }
      d[i][j] = 
    }
  }
  return 0;
}
