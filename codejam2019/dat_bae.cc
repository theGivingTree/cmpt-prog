#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <queue>
#include <algorithm>
using namespace std;
struct SearchUnit {
  int id_start, id_end;
  int start, end;
};
int main() {
  int TC, tc;
  scanf("%d", &TC);
  for(tc=1; tc<=TC; ++tc) {
    int n, b, f;
    int i, j;
    char query_input[1025], result[1025];
    scanf("%d %d %d", &n, &b, &f);
    query_input[n] = 0;

    int n_full_sects = n / (b+1), last_sect_size = n % (b+1);
    for(i=0; i<n_full_sects; ++i) {
      for(j=0; j<b+1; ++j) query_input[i*(b+1)+j] = '0' + (i&1);
    }
    for(j=0; j<last_sect_size; ++j) query_input[i*(b+1)+j] = '0' + (i&1);

    puts(query_input);
    fflush(stdout);
    scanf("%s", result);

    vector<int> broken_idx_list;
    vector<SearchUnit> search_list, new_search_list;

    broken_idx_list.reserve(b);
    search_list.reserve(1024);
    new_search_list.reserve(1024);

    char sent_digit;
    int old_j, n_brokens;
    for(i=0, j=0; i<n_full_sects; ++i) {
      sent_digit = '0' + (i&1);
      old_j = j;
      for(; result[j] == sent_digit; ++j);
      n_brokens = (b+1) - (j-old_j);
      if(n_brokens > 0) {
        search_list.push_back({ i*(b+1), (i+1)*(b+1), old_j, j });
      }
    }
    if(last_sect_size > 0) {
      sent_digit = '0' + (i&1);
      old_j = j;
      for(; result[j] == sent_digit; ++j);
      n_brokens = last_sect_size - (j-old_j);
      if(n_brokens > 0) {
        search_list.push_back({ i*(b+1), n, old_j, j });
      }
    }

    int att;
    for(att=1; att<f && !search_list.empty(); ++att) {
      new_search_list.clear();
      for(auto item: search_list) {
        int id_start = item.id_start, id_end = item.id_end;
        int id_mid = (id_start + id_end) / 2;
        i = id_start;
        for(; i<id_mid; ++i) query_input[i] = '0';
        for(; i<id_end; ++i) query_input[i] = '1';
      }

      puts(query_input);
      fflush(stdout);
      scanf("%s", result);

      for(auto item: search_list) {
        int id_start = item.id_start, id_end = item.id_end;
        int id_mid = (id_start + id_end) / 2;
        int start = item.start, end = item.end;
        int n_left, n_right;
        j = start;
        for(; j<end && result[j] == '0'; ++j);
        n_left = (id_mid - id_start) - (j - start);
        n_right = (id_end - id_mid) - (end - j);

        if(n_left > 0) {
          if(id_mid - id_start == n_left) {
            for(i=id_start; i<id_mid; ++i) broken_idx_list.push_back(i);
          }
          else new_search_list.push_back({ id_start, id_mid, start, j });
        }
        if(n_right > 0) {
          if(id_end - id_mid == n_right) {
            for(i=id_mid; i<id_end; ++i) broken_idx_list.push_back(i);
          }
          else new_search_list.push_back({ id_mid, id_end, j, end });
        }
      }

      search_list.swap(new_search_list);
    }

    sort(broken_idx_list.begin(), broken_idx_list.end());
    for(i=0; i<b-1; ++i) {
      printf("%d ", broken_idx_list[i]);
    }
    printf("%d\n", broken_idx_list[b-1]);
    fflush(stdout);

    int x;
    scanf("%d", &x);
    if(x == -1) {
      fputs("wrong answer!!", stderr);
      return 0;
    }
  }
  return 0;
}
