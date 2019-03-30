#include <cstdio>
using namespace std;
int ids[26];
char h1[]="CEFGHIJKLMNSTUVWXYZ";
char h2[]="ADOPQR";
void setup(int N, char *list, int v) {
  for(int i=0; i<N; ++i) {
    ids[list[i] - 'A'] = v;
  }
}
int main() {
  ids['B'-'A'] = 3;
  setup(sizeof(h1) - 1, h1, 1);
  setup(sizeof(h2) - 1, h2, 2);

  int TC;
  scanf("%d", &TC);
  for(int tc=1; tc<=TC; ++tc) {
    char aa[11], bb[11];
    scanf("%s %s", aa, bb);

    int ia, ib;
    for(ia=0, ib=0; aa[ia] && bb[ib]; ++ia, ++ib) {
      if(ids[aa[ia] - 'A'] != ids[bb[ib] - 'A']) break;
    }

    bool issame = !aa[ia] && !bb[ib];
    printf("#%d %s\n", tc, issame ? "SAME" : "DIFF");
  }
}
