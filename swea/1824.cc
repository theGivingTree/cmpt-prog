#include <cstdio>
#include <cstring>
using namespace std;

int R, C;
char cc[20][21];

bool (*v)[20][16][4];

bool tilTheEnd(int, int, int, int);
void nextPos(int &, int &, int);
bool solve() {
  scanf("%d %d ", &R, &C);
  for(int i=0; i<R; ++i) {
    scanf("%s", cc[i]);
    memset(v[i], 0, sizeof(v[i]));
  }
  return tilTheEnd(0, 0, 0, 0);
}

bool tilTheEnd(int x, int y, int mem, int dir) {
  for(;;nextPos(x, y, dir)) {
    char cur = cc[y][x];
    if(v[y][x][mem][dir]) return false;
    v[y][x][mem][dir] = true;
    if(cur == '<') dir = 2;
    else if(cur == '>') dir = 0;
    else if(cur == '^') dir = 3;
    else if(cur == 'v') dir = 1;
    else if(cur == '_') dir = mem ? 2 : 0;
    else if(cur == '|') dir = mem ? 3 : 1;
    else if(cur == '?') {
      for(int d=0; d<4; ++d) {
        int nx = x, ny = y;
        nextPos(nx, ny, d);
        if(tilTheEnd(nx, ny, mem, d)) return true;
      }
      return false;
    }
    else if(cur == '@') return true;
    else if(cur == '.') {}
    else if(cur == '+') { if(mem++==15) mem = 0; }
    else if(cur == '-') { if(mem--==0) mem = 15; }
    else mem = cur - '0';
  }
}

void nextPos(int &x, int &y, int dir) {
  if(dir == 0) {
    if(++x == C) x = 0;
  }
  else if(dir == 1) {
    if(++y == R) y = 0;
  }
  else if(dir == 2) {
    if(x--==0) x = C - 1;
  }
  else if(y--==0) y = R - 1;
}

int main() {
  v = (bool (*)[20][16][4])new int[20*20*16*4];
  int T;
  scanf("%d", &T);
  for(int t=1; t<=T; ++t) {
    printf("#%d %s\n", t, solve() ? "YES" : "NO");
  }
  return 0;
}
