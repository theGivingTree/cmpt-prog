#include <cstdio>
using namespace std;
int m, n, q=0, totalQ = 60;
int ans;
bool tab[66];
int main() {
  scanf("%d %d", &m, &n);
  while(q<n) {
    printf("%d\n", 1); // correct answer: 1
    fflush(stdout);
    scanf("%d", &ans);
    if(ans==0) return 0;
      tab[q] = (1==ans);
    ++q;
  }

  int lo, hi, md;
  lo = 2, hi = m;
  int qi=0;
  while(lo<hi) {
    if(qi+n == 59) break;
    md = (lo+hi)/2;
    printf("%d\n", md);
    fflush(stdout);
    scanf("%d", &ans);
    if(ans==0) return 0;

    if(!tab[qi]) ans=-ans;
    
    if(ans == 1) {
      lo = md+1;
    }
    else {
      hi = md-1;
    }
    ++qi;
  }
  printf("%d\n", (lo+hi)/2);
  fflush(stdout);
}
