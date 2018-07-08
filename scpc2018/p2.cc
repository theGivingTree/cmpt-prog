#include <iostream>
#include <vector>
using namespace std;

int Answer;
int main() {
  int i, j, k;
  int ddd[10001], basePal[] = {0, 1, 11, 101, 1001};
  int trace[10001];
  vector<int> pList[5];
  for(i=1; i<=4; ++i) pList[i].reserve(90);

  for(i=1; i<=10000; ++i) ddd[i] = 0;
  for(i=1; i<=4; ++i) {
    for(j=1; j<=9; ++j) {
      int num;
      num = basePal[i] * j;
      ddd[num] = 1;
      trace[num] = 0;
      pList[i].push_back(num);
      int e, num2;
      for(k=i-2, e=10; k>=1; k-=2, e*=10) {
        for(auto item: pList[k]) {
          num2 = num + item * e;
          ddd[num2] = 1;
          trace[num2] = 0;
          pList[i].push_back(num2);
        }
      }
    }
  }

  for(i=10; i<=10000; ++i) {
    for(j=1; j<=4; ++j) {
      for(auto pal: pList[j]) {
        int diff = i - pal;
        if(diff <= 0 || diff > 10000 || ddd[diff] == 0 || (ddd[i] !=0 && ddd[i] < ddd[diff] + 1)) continue;
        ddd[i] = ddd[diff] + 1;
        trace[i] = diff;
        if(ddd[i] > 3) ddd[i] = 0;
      }
    }
  }

  int T, test_case;
  cin >> T;
  for(test_case = 0; test_case  < T; test_case++) {

    int n;
    cin >> n;
    cout << "Case #" << test_case+1 << endl;
    cout << ddd[n] << " ";
    if(ddd[n] > 0) {
      int cur = n;
      while(cur) {
        cout << cur - trace[cur] << " ";
        cur = trace[cur];
      }
      cout << endl;
    }
  }

  return 0;
}
