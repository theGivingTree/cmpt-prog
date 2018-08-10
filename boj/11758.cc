#include <iostream>
using namespace std;
int x1, y1, x2, y2, x3, y3;
int main() {
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  x1=x2-x1;
  y1=y2-y1;
  x2=x3-x2;
  y2=y3-y2;
  int cr = x1*y2 - x2*y1;
  cout << (cr>=0?cr==0?0:1:-1);
  return 0;
}
