#include <iostream>
#include <algorithm>
using namespace std;
int const N_MAX = 1000;
struct AA {
  int id; int sum;
  bool operator<(AA rhs) const {
    return sum > rhs.sum || (sum == rhs.sum && id < rhs.id);
  }
} aaa[N_MAX];
int N;
int main() {
  int i, j;
  cin >> N;
  for(i=0; i<N; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    aaa[i].id = i+1;
    aaa[i].sum = a+b+c+d;
  }
  sort(aaa, aaa+N);
  for(i=0; i<N; ++i) {
    if(aaa[i].id == 1) {
      break;
    }
  }
  cout << i+1;
}
