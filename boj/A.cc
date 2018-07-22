#include <iostream>
using namespace std;
int N;
int main() {
  cin >> N;
  int i;
  for(i=0; i<=100; ++i) {
    if(1+i+i*i == N) break;
  }
  cout << i;
  return 0;
}
