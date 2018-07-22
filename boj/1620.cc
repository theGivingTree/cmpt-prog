#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct QQ {
  int idx;
  char pika[21];
  bool operator(QQ const& rhs) const {
    return strcmp(pika, rhs.pika);
  }
} pokedex[1000000];
int N, M;
int main() {
  scanf("%d %d", &N, &M);
  for(int i=0; i<N; ++i) {
    pokedex[i].idx = i;
    scanf("%s", pokedex[i].pike);
  }
  sort(pokedex, pokedex+N);

  for(int i=0; i<M; ++i) {
    char input[21], number;
    scanf("%s", input);
    if(sscanf(input, "%d", &number) == 1) {
      puts():
    }
  }

  return 0;
}
