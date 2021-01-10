#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define DREP(i,n) for (int i = (n-1); i >=0; --i)
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
template<typename T1, typename T2> void view(pair<T1,T2> e) { cout << "("<< e.first << ", " << e.second <<")"  << endl;}
template<typename T1, typename T2> void view(const vector<pair<T1,T2>>& v) {for(const auto& e: v){view(e);}}
// end debug


int main(){
  //#define int long long
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  REP(i,n) cin >> a[i] >> b[i];
  const int NMAX = 400001;
  vector<bool> seen(NMAX);
  REP(i,NMAX) seen[i] = false;


  //同じ色のカードを省く
  REP(i,n){
    if(a[i] == b[i]) {
      if(seen[a[i]] == true) continue;
      seen[a[i]] = true;
    }
  }
  int cnt = 0;
  REP(i,NMAX) if(seen[i]) cnt++;
  //cout << cnt << endl;

  
  vector<pair<int,int>> re;
  //少なくとも一方が見たことある
  REP(i,n){
    if(seen[a[i]]) seen[b[i]] = true;
    else if (seen[b[i]])  seen[a[i]] = true;
    else re.emplace_back(a[i],b[i]);
  }

  cnt = 0;
  REP(i,NMAX) if(seen[i]) cnt++;
  cout << cnt << endl;

  return 0;
}