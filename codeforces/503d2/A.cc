#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n, h, a, b, k;
bool aabb(int x) {
  return a<=x && x<=b;
}
int main() {
  cin >> n >> h >> a >> b >> k;
  while(k--) {
    int ta, fa, tb, fb;
    cin >> ta >> fa >> tb >> fb;
    if(ta == tb) {
      cout << abs(fa-fb) << '\n';
      continue;
    }

    if(aabb(fa) || aabb(fb)) {
      cout << abs(fa-fb) + abs(ta-tb);
      cout << '\n';
      continue;
    }

    if((fa < a && fb > b) || (fb < a && fa > b)) {
      cout << abs(fa-fb) + abs(ta-tb);
      cout << '\n';
      continue;
    }

    cout << min(abs(fa-a) + abs(fb-a), abs(fa-b) + abs(fb-b)) + abs(ta-tb);
    cout << '\n';
  }
  return 0;
}
