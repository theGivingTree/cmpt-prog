#include <cstdio>
using namespace std;
int TC, tc;
int main() {
  scanf("%d", &TC);
  for(tc=1; tc<=TC; ++tc) {
    char aa[50001], bb[50001];
    scanf("%*d %s", aa);
    int i;
    for(i=0; aa[i]; ++i) {
      bb[i] = aa[i] == 'E' ? 'S' : 'E';
    }
    bb[i] = 0;
    printf("Case #%d: %s\n", tc, bb);
  }
  return 0;
}
