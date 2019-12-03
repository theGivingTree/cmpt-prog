#include <cstdio>
#include <vector>
using namespace std;
vector<int> alist[3000];
bool dead[3000];
bool check() {
}
int main() {
  int i;
  int N, M;
  scanf("%d%d",&N,&M);
  for(i=0; i<N; ++i) {
    int a, b;
    scanf("%d%d", &a,&b); --a, --b;
    alist[a].push_back(b);
    alist[b].push_back(a);
  }
  i=0;
  do {
    puts(check()?"YES":"NO");
    int c;
    scanf("%d",&c); --c;
  }
  return 0;
}
