#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  string s, t;
  cin >> s >> t;
  int ans = 0;
  REP(i,s.size()){
    if(s[i] != t[i]) ++ans;
  }

  cout << ans << endl;
  return 0;
}
