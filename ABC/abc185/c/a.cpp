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

/*
  パスカルの三角形を利用した実装
  int128とかつかっても良い.
*/
vector<vector<ll>> comb(int n, int r) {
  vector<vector<ll>> v(n + 1,vector<ll>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  debug(v);
  return v;
}

int main(){
  int n;
  cin >> n;
  --n;
  int r = 11;
  vector<vector<ll>> a = comb(n,r);
  r = min(r, n-r);  //r > n/2 のときのオーバーフローを防ぎやすいと思う
  cout << a[n][r] << endl;
  return 0;
}


/*
  n-1箇所の場所から, 切れ込みを入れる11箇所をえらぶ方法を求めよ.
  12 <= n <= 200
  comb(n-1, 11);

  パスカルの三角形と二項定理
  http://www.xn--u9jtgqbzf1fn77phnzag74e.jp/pascul-nature.html#:~:text=%E4%BA%8C%E9%A0%85%E5%AE%9A%E7%90%86%E3%81%AF(a,3%2C3%2C1%E3%81%A7%E3%81%99%E3%80%82


*/