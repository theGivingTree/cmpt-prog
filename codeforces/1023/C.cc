#include <cstdio>
#include <vector>
using namespace std;
int k, n;
int tag[200000];
char s[200002];
int main() {
  int i, j;
  vector<int> st;
  scanf("%d%d%s",&n,&k,s);
  for(i=0; i<n; ++i) {
    if(s[i] == '(') {
      st.push_back(i);
    }
    else {
      j = st.back(); st.pop_back();
      tag[j] = i-j+1;
    }
  }

  i=0;
  while(i<n && k>0) {
    if(tag[i]>0 && tag[i] <= k) {
      for(j=0; j<tag[i]; ++j) {
        putchar(s[i+j]);
      }
      k -= tag[i];
      i += tag[i];
    }
    else ++i;
  }
  return 0;
}
