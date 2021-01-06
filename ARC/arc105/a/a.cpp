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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll sum = a+b+c+d;
  bool ok = false;
  if(sum - a == a) ok = true;
  if(sum - b == b) ok = true;
  if(sum - c == c) ok = true;
  if(sum - d == d) ok = true;

  if(sum - (a+b) == a+b) ok = true;
  if(sum - (b+c) == b+c) ok = true;
  if(sum - (c+d) == c+d) ok = true;
  if(sum - (d+a) == d+a) ok = true;

  if(sum - (a+c) == a+c) ok = true;
  if(sum - (b+d) == b+d) ok = true;

  if(ok) cout << "Yes" << endl;
  else cout <<"No" << endl; 

  return 0;
}