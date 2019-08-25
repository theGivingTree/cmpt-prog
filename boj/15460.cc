#include <cstdio>
#include <vector>
using namespace std;
int N;
int hw[100000];
vector<int> ans;
int main() {
  int i ;
  scanf("%d", &N);
  for(i=0; i<N; ++i) {
    scanf("%d", &hw[i]);
  }
  for(i=N-2; i>=0; --i) hw[i]+=hw[i+1];
  int v1=0, v2=1;
  for(i=1; i<N-1; ++i) {
    long long d = 1LL*hw[i]*v2 - 1LL*v1*(N-i);
    if(d>0) {
      v1=hw[i], v2=N-i;
      ans.clear();
      ans.push_back(i);
    }
    else if(d==0) {
      ans.push_back(i);
    }
  }
  for(int a: ans) {
    printf("%d\n", a);
  }
  return 0;
}
