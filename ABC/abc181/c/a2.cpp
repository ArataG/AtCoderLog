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
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  REP(i,n) cin >> x[i] >> y[i];

  REP(i,n)REP(j,i)REP(k,j){
    int dx1 = x[j] - x[i];
    int dy1 = y[j] - y[i];
    int dx2 = x[k] - x[i];
    int dy2 = y[k] - y[i];
    if(dx1 * dy2 == dx2 * dy1) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout <<"No" << endl;
  return 0;
}