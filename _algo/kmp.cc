#include <cstdio>
#include <cstring>
using namespace std;

void pre(char pat[], int patLen, int T[]) {
  int i, j;
  T[0]=-1;
  for(i=1, j=0; i<=patLen; ++i, ++j) {
    if(pat[i] == pat[j]) {
      T[i] = T[j];
    }
    else {
      T[i] = j;
      j = T[j];
      while(j>=0 && pat[i] != pat[j]) j=T[j];
    }
  }
}

void kmp(char text[], int textLen, char pat[], int patLen, int rIndices[]) {
  int i, j;
  int T[101];
  pre(pat, patLen, T);
  for(int i=0; i<=patLen; ++i) {
    printf("%d ", T[i]);
  }
  puts("");
}

int main() {
  char text[101], pat[101];
  scanf("%s %s", text, pat);

  int textLen, patLen;
  textLen = strlen(text);
  patLen = strlen(pat);

  int rIndices[101];
  memset(rIndices, 0xff, 101*sizeof(int));
  kmp(text, textLen, pat, patLen, rIndices);

  for(int i=0; rIndices[i] != -1; ++i) {
    printf("i: %d, matched: %s\n", i, text+rIndices[i]);
  }
}

