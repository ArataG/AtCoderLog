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
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << " :";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

//部分文字列のTが
// A <-> T
// C <-> G
// に並び替えできるかどうか
// Aの数と，Tの数，Cの数とGの数が一致している
// 左端を全てを探索．




int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;

  int ans = 0;

  REP(i,n){
    int cnt1 = 0, cnt2 = 0;
    REP2(j,i,n){
      if(s[j] == 'A') cnt1++;
      else if(s[j] == 'T') cnt1--;
      else if(s[j] == 'C') cnt2++;
      else cnt2--; // s[j]=='G'
      if(cnt1 == 0 && cnt2 == 0) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}