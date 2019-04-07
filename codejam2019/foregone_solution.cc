#include <cstdio>
using namespace std;
int TC, tc;
int main() {
  scanf("%d", &TC);
  for(tc=1; tc<=TC; ++tc) {
    char digits[102];
    char A[102], B[102];
    scanf("%s", digits);

    int i;
    for(i=0; digits[i]; ++i) {
      if(digits[i] == '4') {
        A[i] = '3';
        B[i] = '1';
      }
      else {
        A[i] = digits[i];
        B[i] = '0';
      }
    }
    A[i] = B[i] = 0;
    for(i=0; B[i] == '0'; ++i);
    printf("Case #%d: %s %s\n", tc, A, B+i);
  }
  return 0;
}
