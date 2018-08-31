#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
using ll = long long;

struct vector2
{
  ll x, y;
  explicit vector2(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
  bool operator==(const vector2& rhs) const
  {
    return x == rhs.x && y == rhs.y;
  }
  bool operator<(const vector2& rhs) const
  {
    return x != rhs.x ? x < rhs.x : y < rhs.y;
  }
  vector2 operator+(const vector2& rhs) const
  {
    return vector2(x + rhs.x, y + rhs.y);
  }
  vector2 operator-(const vector2& rhs) const
  {
    return vector2(x - rhs.x, y - rhs.y);
  }
  vector2 operator*(ll rhs) const
  {
    return vector2(x * rhs, y * rhs);
  }
  ll dot(const vector2& rhs) const
  {
    return x * rhs.x + y * rhs.y;
  }
  ll cross(const vector2& rhs) const
  {
    return x * rhs.y - rhs.x * y;
  }
  double norm() const
  {
    return hypot(x, y);
  }
};

ll ccw(vector2 a, vector2 b)
{
  return a.cross(b);
}
ll ccw(vector2 p, vector2 a, vector2 b)
{
  return ccw(a-p, b-p);
}
bool isParallel(vector2 a, vector2 b, vector2 c, vector2 d)
{
  return (a-b).cross(c-d) == 0;
}
bool segmentIntersect(vector2 a, vector2 b, vector2 c, vector2 d)
{
  ll ab = ccw(a, b, c) * ccw(a, b, d);
  ll cd = ccw(c, d, a) * ccw(c, d, b);

  if(ab == 0 && cd == 0)
  {
    if(b < a) swap(a, b);
    if(d < c) swap(c, d);
    return !(b < c || d < a);
  }
  return ab <= 0 && cd <= 0;
}
struct Compare {
  vector2 origin;
  Compare(int _x, int _y): origin(_x, _y) {}
  bool operator()(vector2 lhs, vector2 rhs) const {
    long long val = ccw(origin, lhs, rhs);
    return val>0 || (val == 0 && lhs.norm() < rhs.norm());
  }
};
vector2 parr[100000];
int main() {
  int i, j, II, xmin;
  int N;
  cin >> N;
  II=0; xmin=0x7fFFffFF;
  for(i=0; i<N; ++i) {
    cin >> parr[i].x >> parr[i].y;
    if(xmin > parr[i].x) {
      xmin = parr[i].x;
      II = i;
    }
  }
  swap(parr[II], parr[N-1]);
  sort(parr, parr+N-1, Compare(parr[N-1].x, parr[N-1].y));

  vector<vector2> res;
  res.push_back(parr[N-1]);
  for(i=0; i<N-1; ++i) {
    while(res.size() >= 2 && ccw(res[res.size()-1] - res[res.size()-2], parr[i] - res[res.size()-1]) <= 0) res.pop_back();
        res.push_back(parr[i]);
  }
  cout << res.size();
  return 0;
}
