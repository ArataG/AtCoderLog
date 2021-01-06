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


ll f(ll x) {
  if(x == 0) return 0;
  return x * (x+1) / 2;
}

 ll binary(ll n) {
  ll cnt = 0;
  ll left = 1;
  ll right = 1e9+7;
  ll key = n+1;
  ll mid = 0;
  ll tmp = 0;
  while(right > left){
    mid = left + (right - left)/2;
    if(f(mid) == key) return mid;
    else if(f(mid) > key ) right = mid;
    else left = mid+1;
    if(left == right) break;
    tmp = right;
  }
  cout << mid << endl;
  cout << right << endl;
  cout << left << endl;
  return mid;
 }

int main(){
  //#define int long long
  ll n;
  cin >> n;

  if(n==1){
    cout << 1 << endl;
    return 0;
  }
  if(n==2){
    cout << 1 << endl;
    return 0;
  }
  //if(n==3){
  //   cout << 2 << endl;
  //   return 0;
  // }
  // if(n == 4){
  //   cout << 3 << endl;
  //   return 0;
  // }
  

  //cout <<"bb" <<  binary(n) << endl;

  ll ans = n - binary(n)  + 1;
  cout << ans << endl;
  return 0;
}
