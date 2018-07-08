#include <iostream>
#include <algorithm>
using namespace std;

int Answer;
int main() {
  int T, test_case;

  cin >> T;
  for(test_case = 0; test_case  < T; test_case++) {
    Answer = 0;
    int N, K, sil[200000];
    cin >> N >> K;
    int i, j;
    for(i=0; i<N; ++i) {
      cin >> sil[i];
    }
    sort(sil, sil+N);

    Answer = 0;
    for(i=0, j=0; j<N; ++i) {
      for(; j<N && sil[j] - sil[i] <= K; ++j) /* noop */;
      if(Answer < j - i) Answer = j - i;
    }

    cout << "Case #" << test_case+1 << endl;
    cout << Answer << endl;
  }

  return 0;
}
