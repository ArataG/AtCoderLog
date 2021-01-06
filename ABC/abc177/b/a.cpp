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

//全探索
//

int main(){
  string s, t;
  cin >> s >> t;
  int len = t.size();
  int n = s.size();
  int mincnt = 100000000;
  REP(i,n - len +1){
    int cnt = 0;
    REP2(j,i,i+len){
      if(s[j] != t[j-i]) cnt++;
    }
    mincnt = min(cnt,mincnt);
  }
  //cout << mincnt << endl;

  int ans = 1e9;
  REP(si,s.size()){
    if(si+t.size() > s.size()) break;//これで配列外参照しない
    int cnt = 0;
    REP(i,t.size()){
      if(s[si+i] != t[i]) cnt++;
    }
    ans = min(ans,cnt);
  }
  cout << ans << endl;

  return 0;
}

