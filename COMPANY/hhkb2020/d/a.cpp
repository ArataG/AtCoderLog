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

void solve(){
  int n, a, b;
  cin >> n >> a >> b;
  if(a > b) swap(a,b); //常にbが大

  int ans = 0;

  if(n < a+b){
    cout << 0 << endl;
    return;
  }

  else if(2*a + b < n){

  }
  else{
    ans += (n-a-b)*(n-a-b);


  }
  return;
}

int main(){
  int t;
  cin >> t;
  REP(i,t) solve();
  return 0;
}

//((n-b-a+1)*(n-a+1))*2 - (n-b-a+1)*(n-b-a+1)