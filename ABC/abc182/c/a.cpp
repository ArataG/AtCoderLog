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
  string s;
  cin >> s;

  int n = s.size();
  //

  ll sum = 0;

  bool ok = false;
  REP(i,n){
    int x = (int)(s[i] - '0');
    if(x%3 == 0 ){
      ok = true;
    } 
    sum += x;
  }

  //cout << sum << endl;
  debug(sum);

  if(sum%3 == 0){
    cout << 0 << endl;
    return 0;
  }

  // if(!ok){
  //   cout << -1 << endl;
  //   return 0;
  // }
  
  //
  ll n1 = 0;
  ll n2 = 0;
  ll n3 = 0;
  int ans = 3;

  REP(i,n){
    int x = (int)(s[i] - '0');
    if(x%3 == 1) n1++;
    if(x%3 == 2) n2++;
    if(x%3 == 0) n3++;
  }
  //cout << "h " << endl;
  bool flg = false;
  if(n3 > 0) flg = true;
  if(n2 >= 3 || n1 >= 3) flg = true;
  if(n1 > 0 && n2 > 0 ) flg = true;
  if(!flg){
    cout << -1 << endl;
    return 0;
  }

  if(sum%3 == 1){
    if(n1 >= 1) ans = min(ans, 1);
    if(n2 >= 2) ans =  min(ans, 2);
  }
  else{
    if(n1 >= 2) ans = min(ans, 2);
    if(n2 >= 1) ans = min(ans, 1);
  }


  cout << ans << endl;
  return 0;
}