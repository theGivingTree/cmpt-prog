#include <iostream>
#include <algorithm>
using namespace std;

struct Vec2d {
  int x, y;
  Vec2d() {}
  Vec2d(int _x, int _y): x(_x), y(_y) {}
  Vec2d operator-(Vec2d rhs) {
    return Vec2d(x-rhs.x, y-rhs.y);
  }
  bool operator==(Vec2d rhs) {
    return x == rhs.x && y == rhs.y;
  }
  bool operator!=(Vec2d rhs) {
    return x != rhs.x || y != rhs.y;
  }
  bool operator<(Vec2d rhs) {
    return x < rhs.x || x == rhs.x && y < rhs.y;
  }
};

void orderVec2d(Vec2d& lhs, Vec2d& rhs) {
  if(lhs.x > rhs.x) swap(lhs, rhs);
  else if(lhs.x == rhs.x && lhs.y > rhs.y) swap(lhs, rhs);
}

int cross(Vec2d v1, Vec2d v2) {
  return v1.x*v2.y - v1.y*v2.x;
}

int cross(Vec2d p, Vec2d a, Vec2d b) {
  return cross(a-p, b-p);
}

int ccw(Vec2d P1, Vec2d P2, Vec2d P3) {
  int val = cross(P1, P2, P3);
  return val < 0 ? -1 : val > 0 ? 1 : 0;
}

bool isPara(Vec2d P1, Vec2d P2, Vec2d Q1, Vec2d Q2) {
  return cross(P2-P1, Q2-Q1) == 0;
}

bool isOnto(Vec2d P1, Vec2d P2, Vec2d Q1, Vec2d Q2) {
  if(!isPara(P1, P2, Q1, Q2)) return false;
  return cross(P1, P2, Q1) == 0;
}

int intersect(Vec2d baseA, Vec2d baseB, Vec2d P1, Vec2d P2) {
  if(isOnto(baseA, baseB, P1, P2)) {
    Vec2d excluded = baseB;
    orderVec2d(baseA, baseB);
    orderVec2d(P1, P2);

    if(baseB < P1 || P2 < baseA) return 0;

    if(baseB == P1) {
      return excluded != baseB;
    }
    if(P2 == baseA) {
      return excluded != baseA;
    }

    return 0x7fFFffFF;
  }

  if(isPara(baseA, baseB, P1, P2)) {
    return 0;
  }

  if(
    ccw(baseA, baseB, P1)*ccw(baseA, baseB, P2) == 1 ||
    ccw(P1, P2, baseA)*ccw(P1, P2, baseB) == 1
  ) {
    return 0;
  }

  if(baseB == P1 || baseB == P2) return 0;
  if(cross(P1-baseB, P2-baseB) == 0) return 0;

  return 1;
}



int T;
int submain() {
  int x0, y0, x1, y1;
  int x2, y2, x3, y3;
  cin >> x0 >> y0 >> x1 >> y1;
  cin >> x2 >> y2 >> x3 >> y3;
  Vec2d BL(x0, y0), BR(x1, y0), TL(x0, y1), TR(x1, y1);
  Vec2d segA(x2, y2), segB(x3, y3);

  int k1, k2, k3, k4;
  k1 = intersect(BL, BR, segA, segB);
  k2 = intersect(BR, TR, segA, segB);
  k3 = intersect(TR, TL, segA, segB);
  k4 = intersect(TL, BL, segA, segB);

  if(max({k1, k2, k3, k4}) == 0x7fFFffFF) return 4;
  return k1+k2+k3+k4;
}
int main() {
  cin >> T;
  while(T--) {
    printf("%d\n", submain());
  }
  return 0;
}
