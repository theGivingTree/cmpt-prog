#include <cstdio>
#include <vector>
using namespace std;
int n;
int lcnt[27], rcnt[27];
vector<int> idxl[27], idxr[27];
int sofar[26], sofar_ql, sofar_qr;
int ans;
void count(char *s, int *arr, vector<int> *idx) {
  int j = 1;
  while(*s) {
    int i;
    if(*s == '?') i = 26;
    else i = *s - 'a';
    idx[i].push_back(j);
    ++arr[i];
    ++s;
    ++j;
  }
}
int main() {
  char lb[150001], rb[150001];
  scanf("%d %s %s", &n, lb, rb);
  count(lb, lcnt, idxl);
  count(rb, rcnt, idxr);

  int lrem = 0, rrem = 0;
  for(int a=0; a<26; ++a) {
    int x = lcnt[a] < rcnt[a] ? lcnt[a] : rcnt[a];
    sofar[a] = x;
    ans += x;
    lrem += (lcnt[a]-x);
    rrem += (rcnt[a]-x);
  }

  int lmo = lcnt[26], rmo = rcnt[26];
  if(lmo < rrem) {
    ans += lmo;
    sofar_ql = lmo;
    lmo = 0;
  }
  else {
    ans += rrem;
    sofar_ql = rrem;
    lmo -= rrem;
  }

  if(rmo < lrem) {
    ans += rmo;
    sofar_qr = rmo;
    rmo = 0;
  }
  else {
    ans += lrem;
    sofar_qr = lrem;
    rmo -= lrem;
  }
  int fin = lmo < rmo ? lmo : rmo;
  ans += fin;
  printf("%d\n", ans);

  for(int a=0; a<26; ++a) {
    for(int i=0; i<sofar[a]; ++i) {
      printf("%d %d\n", idxl[a][i], idxr[a][i]);
    }
  }

  int q;

  q = 0;
  for(int a=0; a<26; ++a) {
    for(int i=sofar[a]; q<sofar_ql && i<idxr[a].size(); ++i, ++q) {
      printf("%d %d\n", idxl[26][q], idxr[a][i]);
    }
  }

  q = 0;
  for(int a=0; a<26; ++a) {
    for(int i=sofar[a]; q<sofar_qr && i<idxl[a].size(); ++i, ++q) {
      printf("%d %d\n", idxl[a][i], idxr[26][q]);
    }
  }

  int ql, qr;
  for(ql = sofar_ql, qr = sofar_qr, q = 0;  q < fin; ++q, ++ql, ++qr) {
    printf("%d %d\n", idxl[26][ql], idxr[26][qr]);
  }
  return 0;
}
