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


int main(){
  //#define int long long
  int n;
  cin >> n;
  string t;
  cin >> t;

  if(t.size() < 3){
  ll ans = 0;
  if(t == "0") ans = 1e10;
  if(t == "1") ans = 1e10 * 2;
  if(t == "00") ans = 0;
  if(t == "11") ans = 1e10;
  if(t == "01") ans = 1e10-1;
  if(t == "10") ans = 1e10;
  cout << ans << endl;
  return 0;
}


  string s;
  while(1){
    s += "110";
    if(s.size() >= n + 3) break;
  }
  
  //cout << s << endl;
  
  ll st = -1;
  REP(j,3){
    bool ok = true;
    REP(i, t.size()){
      if(s[i+j] != t[i]) ok = false;
    }
    if(ok) st = j;
  }

  if(st == -1) {
    cout <<  0 << endl;
    return 0;
  }
  
  ll ans =  (3*1e10 - st - n)/3 + 1;
  cout << ans << endl;
  
  return 0;
}

/*
9999999999
10000000000
9999999993
1000000000000


*/