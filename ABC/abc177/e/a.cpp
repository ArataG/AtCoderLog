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

int isprime[1000100];

void Eratos(int n){
  int i;
  ++n;
  //int isprime[n];
  for(i = 0; i < n; i++){
    isprime[i] = 1;
  }

  isprime[0] = isprime[1] = 0;

  for(i = 2; i*i <= n; ++i){
    if(isprime[i]){
      int j = i + i;
      while(j <= n){
        isprime[j] = 0; //iの倍数を除去
        j = j + i;
      }
    }
  }
  // for(i = 0; i <= n; i++){
  //   if(isprime[i]) cout << i << endl;
  // }

}

int main(){
  int n;
  cin >> n;
  const int nmax = 1000010;
  Eratos(nmax);
  vector<int> a(n);
  vector<int> c(nmax);
  sort(ALL(a));
  REP(i,n) {
    cin >> a[i];
    c[a[i]]++;
  }

  bool ok = false;
  REP2(i,2,nmax){
    if(!isprime[i]) continue;
    //cout << i;
    int cnt = 0;
    for(int j = i; j < nmax; j += i){
      cnt += c[j];
    }
    if(cnt > 1){
      ok = true;
      break;
    }
  }

  if(!ok){
    cout << "pairwise coprime" << endl;
    return 0;
  }

  int gcdst = a[0];
  REP2(i,1, n){
    gcdst = __gcd(gcdst,a[i]);
  }
  if(gcdst == 1) cout << "setwise coprime" << endl;
  else cout << "not coprime" << endl;

  return 0;
}

/*
　pairWiseかの判定

  素因数をすべて調べる
  初めに，1-nmaxの配列を用意する．
  次に入力された数字を１にする
  すべての素因数で，配列の和を取る

  2以上ならNG


//0とｘのGCDはxになる　>> 初期値は０にするとよい

*/