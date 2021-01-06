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


ll seg[1 << 20];

void set_value(ll pos, ll val){
  pos += 1 << 19; //20?
  seg[pos] = val;
  while((pos /= 2) > 0 ){
    seg[pos] = max(seg[pos * 2], seg[pos * 2 + 1]);//自分の左右の子供のminをとって更新
  }
}

//クエリの右橋，左端，今いる場所の区間の左右端，今いる場所 デフォルト引数設定しとくとよい
ll get_max(ll ql, ll qr, ll sl = 0, ll sr = 1 << 19, ll pos = 1){
  //全くかぶっていないとき
  if(qr <= sl || sr <= ql) return 0;  //意味のない数字を返す　maxのときは，0を返す
  //完全にかぶっているとき（セグメントがクエリに）
  if(ql <= sl && sr <= qr) return seg[pos];
  //
  ll sm = (sl + sr) / 2;
  ll lmax = get_max(ql,qr,sl,sm,pos * 2); //左右の子に託す
  ll rmax = get_max(ql,qr,sm,sr,pos * 2 + 1); //左右の子に託す
  return max(lmax, rmax);
}


int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  REP(i,n+1){
    set_value(i,0);
  }

  REP(i,n){
    int add = get_max(max(a[i]-k,0), min(a[i]+k+1,n+1));
    set_value(a[i], add+1);
  }



  int ans = get_max(0,n+1);
  cout << ans << endl;
  return 0;
}