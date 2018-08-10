#include <cstdio>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
char raw[1000001], _ansBuffer[1000030];
char *ansBuffer = _ansBuffer;

unordered_map<string, int> map;
set<string> aaaa[1000000];
unordered_set<int> banset[1000000];
int constantTable[1000000];

int useMe = 0;
int parent[1000000];
int find(int x) {
  return parent[x] = (x == parent[x] ? x : find(x));
}
bool chkgroup(int x, int y) {
  return find(x) == find(y);
}
void join(int x, int y) {
  int px = find(x), py = find(y);
  parent[px] = py;
}

int main() {
  scanf("%s", raw);
  int i=0;

  bool identityExp = false;
  bool isEqual = false;

  for(i=0; i<1000000; ++i) {
    constantTable[i] = 0x7fffffff;
    parent[i] = i;
  }

  while(true) {
    char delim;
    int j=0;
    while(true) {
      char ch = raw[i+j];
      if(ch == '&' || ch == 0) {
        delim = ch;
        break;
      }
      ++j;
    }
    // [i, i+j)
    char *curSingle = raw + i;

    int k = 0;
    bool isEqual;
    while(true) {
      char ch = curSingle[k];
      if(ch == '!' || ch == '=') {
        isEqual = (ch == '=');
        break;
      }
      ++k;
    }

    /* preprocess  */

    // length == k;
    bool isLhsConst = false, isRhsConst = false;
    int constlhs, constrhs;
    string varlhs, varrhs;

    if(curSingle[0] == '-' || isdigit(curSingle[0] )) {
      // constant
      isLhsConst = true;
      sscanf(curSingle, "%d", &constlhs);
    }
    else {
      varlhs = string(curSingle, k);
    }

    ////////////////////////////
    curSingle = curSingle + k+2;
    while(true) {
      char ch = curSingle[k];
      if(ch == '&' || ch == 0) {
        break;
      }
      ++k;
    }
    // length == k
    if(curSingle[0] == '-' || isdigit(curSingle[0] )) {
      // constant
      isRhsConst = true;
      sscanf(curSingle, "%d", &constrhs);
    }
    else {
      varrhs = string(curSingle, k);
    }


    /* real-real */

    if(!isLhsConst && !isRhsConst) {

      if(varlhs == varrhs) {
        if(isEqual) continue;
        else {
          identityExp = true;
          isEqual = false;
          break;
        }
      }

      auto lhsIter = map.find(varlhs);
      auto rhsIter = map.find(varrhs);

      if(lhsIter == map.end() && rhsIter == map.end()) {
        if(isEqual) {
          int id = useMe;
          map.insert({varlhs, id});
          aaaa[id].insert(varlhs);
          map.insert({varrhs, id});
          aaaa[id].insert(varrhs);
          ++useMe;
        }
        else {
          aaaa[useMe].insert(varlhs);
          map.insert({varlhs, useMe++});
          aaaa[useMe].insert(varrhs);
          map.insert({varrhs, useMe++});
        }
      }
      else if(lhsIter == map.end() && rhsIter != map.end()) {
        if(isEqual) {
          int id = rhsIter->second;
          aaaa[id].insert(varlhs);
          map.insert({varlhs, id});
        }
        else {
          aaaa[useMe].insert(varlhs);
          map.insert({varlhs, useMe++});
        }
      }
      else if(lhsIter != map.end() && rhsIter == map.end()) {
        if(isEqual) {
          int id = lhsIter->second;
          aaaa[id].insert(varrhs);
          map.insert({varrhs, id});
        }
        else {
          aaaa[useMe].insert(varrhs);
          map.insert({varrhs, useMe++});
        }
      }
      else {
        int id1 = lhsIter->second;
        int id2 = rhsIter->second;
        if(isEqual) {
          if(id1 != id2) {
            identityExp = true;
            isEqual = false;
            break;
          }
        }
        else {
          if(id1 == id2) {
            identityExp = true;
            isEqual = false;
            break;
          }
        }
      }
    }
    else if(isLhsConst != isRhsConst) {
      if(isLhsConst) {
        swap(constlhs, constrhs);
        swap(varlhs, varrhs);
      }

      auto lhsIter = map.find(varlhs);
      int id = lhsIter->second;
      int assigned = constantTable[id];
      auto const& theset = banset[id];
      if(isEqual) {
        if(assigned != 0x7fffffff) {
          if(assigned != constrhs) {
            identityExp = true;
            isEqual = false;
            break;
          }
        }
        else {
          if(theset.find(constrhs) != theset.end()) {
            identityExp = true;
            isEqual = false;
            break;
          }
          constantTable[id] = constrhs;
        }
      }
      else {
        if(assigned != 0x7fffffff) {
          if(assigned == constrhs) {
            identityExp = true;
            isEqual = false;
            break;
          }
        }
        else {
          theset.insert(constrhs)
        }
      }
    }
    else {
      if(constlhs != constrhs) {
        identityExp = true;
        isEqual = false;
        break;
      }
    }

    //////////////////////////////
    if(delim == '&') {
      i += 2;
    }
    else break;
  }
  // do what?
  if(useMe == 0) {
    identityExp = true;
    isEqual = true;
  }

  if(identityExp) {
    if(isEqual) {
      puts("0==0");
    }
    else {
      puts("0==1");
    }
  }
  else {
    char *ans = ansBuffer;
    int i, j;
    string shortestList[1000000];
    set<string>::iterator ffuck[1000000];

    int total = 0;
    for(i=0; i<useMe; ++i) {
      auto iiii = aaaa[i].begin();
      shortestList[i] = *iiii;
      ffuck[i] = ++iiii;
    }
    for(i=0; i<useMe; ++i) {
      for(j=1; j<useMe; ++j) {
        int written;
        written = sprintf(ansBuffer, "%s!=%s&&", shortestList[i].c_str(), shortestList[j].c_str());
        total += written;
        ansBuffer = ansBuffer + written;
      }
    }

    for(i=0; i<useMe; ++i) {
      for(auto it = ffuck[i]; it != aaaa[i].end(); ++it) {
        int written;
        written = sprintf(ansBuffer, "%s==%s&&", shortestList[i].c_str(), (*it).c_str());
        total += written;
        ansBuffer = ansBuffer + written;
      }
    }

    if(total == 0) {
      puts("0==0");
    }
    else {
      ans[total-2] = 0;
      puts(ans);
    }
  }
  return 0;
}
