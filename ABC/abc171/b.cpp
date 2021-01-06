#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

//-----------------------//
//    配列，sort,forループ
//-----------------------//

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  REP(i, n) cin >> p[i];

  sort(ALL(p));
  int sum = 0;
  REP(i, k) sum += p[i];

  cout << sum << endl;

  return 0;
}
