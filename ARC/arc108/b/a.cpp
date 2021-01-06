#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;

/*
  O[n]
  スタックに積んで，末尾を参照．
  一致していたらpopする．
*/
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;

  string stk; // スタック

  REP(i,n){
    stk += s[i];
    int it = stk.size();
    if(it < 3) continue;
    if(stk[it-1] == 'x' && stk[it-2]=='o' && stk[it-3] == 'f'){
      REP( _, 3) stk.pop_back();
    }
  }

  int ans = stk.size();

  cout << ans << endl;
  
  return 0;
}