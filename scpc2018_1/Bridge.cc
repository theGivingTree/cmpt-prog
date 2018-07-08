#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unistd.h>

using namespace std;
struct Vec2 {
  double x=0, y=0;
  Vec2() {}
  Vec2(double x, double y): x(x), y(y) {}
  Vec2 operator-(Vec2 const& rhs) const {
    return Vec2(x-rhs.x, y-rhs.y);
  }
  Vec2 operator+(Vec2 const& rhs) const {
    return Vec2(x+rhs.x, y+rhs.y);
  }
  Vec2 operator*(double scalar) {
    return Vec2(x*scalar, y*scalar);
  }
  bool operator==(Vec2 const& rhs) const {
    return x == rhs.x && y == rhs.y;
  }
};

double normSq(Vec2 v) {
  return 1.0*v.x*v.x + 1.0*v.y*v.y;
}
double norm(Vec2 v) {
  return sqrt(normSq(v));
}
double dot(Vec2 a, Vec2 b) {
  return a.x*b.x + a.y*b.y;
}
double orient(Vec2 v1, Vec2 v2) {
  return v1.x*v2.y - v1.y*v2.x;
}
double distToSegment(Vec2 v, Vec2 w, Vec2 p) {
  Vec2 s = w - v;
  double const L2 = normSq(s);
  double const t = min(max(dot(p-v, w-v) / L2, 0.0), 1.0);
  Vec2 proj = v + s*t;
  return norm(proj - p);
}

void setupPolygon(vector<Vec2>& v, vector<Vec2>& segs) {
  // v: list of points
  // segs: list of segments
  int L = v.size();
  double prevY = v[L-1].y;
  int j;
  // find index of y- most and x- most point
  for(j=0; j<L-1; ++j) {
    if(prevY > v[j].y && v[j].y <= v[j+1].y) {
      break;
    }
    prevY = v[j].y;
  }

  // reorder
  if(j != 0) rotate(v.begin(), v.begin() + j, v.end());

  Vec2 prevPoint = v[0];
  // Vec2 prevSeg;
  for(j=1; j<L; ++j) {
    segs[j-1] = v[j] - prevPoint;

    // if(orient(segs[j-1], prevSeg) == 0) {}

    prevPoint = v[j];
    // prevSeg = segs[j-1];
  }
  segs[L-1] = v[0] - prevPoint;
  
  return;
}

double solve() {
  int N, M;
  cin >> N >> M;
  vector<Vec2> A(N), B(M), Av, Bv;
  A.reserve(N+1);
  B.reserve(M+1);
  Av.resize(N+1);
  Bv.resize(M+1);

  for(int i=0; i<N; ++i) {
    int x, y;
    cin >> x >> y;
    A[i].x = x;
    A[i].y = y;
  }

  for(int j=0; j<M; ++j) {
    int x, y;
    cin >> x >> y;
    // note: origin symmetry
    B[j].x = -x;
    B[j].y = -y;
  }

  setupPolygon(A, Av);
  setupPolygon(B, Bv);

  // restore B
  for(auto& e : B) {
    e.x = -e.x;
    e.y = -e.y;
  }
  for(auto& e : Bv) {
    e.x = -e.x;
    e.y = -e.y;
  }


  A.resize(N+1);
  B.resize(M+1);
  A[N] = A[0];
  Av[N] = Av[0];
  B[M] = B[0];
  Bv[M] = Bv[0];

  Vec2 seg0, seg1, vert;
  struct State {
    int L;
    vector<Vec2> *K;
    vector<Vec2> *Kv;
    int idx;

    State(int l, vector<Vec2> *k, vector<Vec2> *kv, int i): L(l), K(k), Kv(kv), idx(i) {}

    Vec2 getCur(int offset = 0) {
      return (*K)[idx + offset];
    }
    Vec2 getCurV(int offset = 0) {
      return (*Kv)[idx + offset];
    }
    bool isDone() const {
      return L == idx;
    }
  } AS(N, &A, &Av, 0), BS(M, &B, &Bv, 0), *ONE, *ANOTHER;

  if(-orient(Av[0], Bv[0]) < 0) {
    seg0 = B[0];
    seg1 = B[1];
    vert = A[0];
    ONE = &BS;
    ANOTHER = &AS;
  }
  else {
    seg0 = A[0];
    seg1 = A[1];
    vert = B[0];
    ONE = &AS;
    ANOTHER = &BS;
  }

  // double ans = distToSegment(seg0, seg1, vert);
  double ans = HUGE_VAL;

  while(!ONE->isDone() || !ANOTHER->isDone()) {

    seg0 = ONE->getCur();
    seg1 = ONE->getCur(1);
    vert = ANOTHER->getCur();

    Vec2 Wall = ANOTHER->getCurV();
    // orient(-Wall, ONE->getCurV() <= 0)
    while(-orient(Wall, ONE->getCurV()) <= 0) {

      double new_ans = distToSegment(seg0, seg1, vert);
      if(ans > new_ans) ans = new_ans;

      cout << "Seg0: " << seg0.x << ", " << seg0.y << endl;
      cout << "Seg1: " << seg1.x << ", " << seg1.y << endl;
      cout << "vert: " << vert.x << ", " << vert.y << endl;
      cout << "Wall: " << -Wall.x << ", " << -Wall.y << endl;
      cout << "ans: " << new_ans << endl;
      usleep(1000*500);

      ++ONE->idx;
      if(ONE->isDone()) break;
      seg0 = ONE->getCur();
      seg1 = ONE->getCur(1);
    }

    swap(ONE, ANOTHER);
  }

  return ans;
}
int main() {
  // cout.precision(10);
  int t, T;
  cin >> T;
  for(t=0; t<T; ++t) {
    cout << "Case #" << t << endl;
    cout << solve() << endl;
  }
  return 0;
}
