#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
  vector<int> solve(vector<int> &t, vector<int> &dir) {
    queue<pair<int, int>> exit, entry; // pair <time[index], index>
    int N = t.size();
    vector<int> res(N);

    for (int i = 0; i < N; i++) {
      if (dir[i] == 1)
        exit.push({t[i], i});
      else
        entry.push({t[i], i});
    }

    int ct = 0, lc = -1; // ct is the current time & lc indicates who used
                         // turnstile in the previous second lc = -1 if none
                         // used the turnstile in the last second

    while (!exit.empty() || !entry.empty()) {
      // checking for exit queue
      if (!exit.empty() && exit.front().first <= ct &&
          (lc == 1 || lc == -1 || entry.empty() ||
           (entry.front().first > ct))) {
        res[exit.front().second] = ct;
        lc = 1;
        exit.pop();
      }
      // checking for entry queue
      else if (!entry.empty() && entry.front().first <= ct) {
        res[entry.front().second] = ct;
        lc = 0;
        entry.pop();
      } else {
        lc = -1;
      }

      ct++;
    }

    return res;
  }
};

static int i = 1;
void test(Solution &sol, vector<int> &t, vector<int> &dir,
          vector<int> &expected) {
  cout << "Run test case " << i++ << endl;
  auto res = sol.solve(t, dir);
  for (auto &item : res)
    cout << item << " ";
  cout << endl;
  for (auto &item : expected)
    cout << item << " ";
  cout << endl;

  assert(res == expected);
  cout << "Success!" << endl;
}

int main() {
  Solution sol;
  vector<int> t = {0, 0, 1, 5};
  vector<int> dir = {0, 1, 1, 0};
  vector<int> expected = {2, 0, 1, 5};
  test(sol, t, dir, expected);

  vector<int> t2 = {1, 2, 4};
  vector<int> dir2 = {0, 1, 1};
  vector<int> expected2 = {1, 2, 4};
  test(sol, t2, dir2, expected2);

  vector<int> t3 = {1, 1};
  vector<int> dir3 = {1, 1};
  vector<int> expected3 = {1, 2};
  test(sol, t3, dir3, expected3);

  vector<int> t4 = {1, 1, 3, 3, 4, 5, 6, 7, 7};
  vector<int> dir4 = {1, 1, 0, 0, 0, 1, 1, 1, 1};
  vector<int> expected4 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  test(sol, t4, dir4, expected4);

  return 0;
}
