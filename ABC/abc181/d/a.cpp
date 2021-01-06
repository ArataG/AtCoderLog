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
  if(n == 1){
    if(s[0] == '8') {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
    return 0;
  }

  if(n == 2){
    bool ok = false;
    int a = (int)(s[0] - '0');
    int b = (int)(s[1] - '0');
    if((10*a + b) % 8 == 0) ok = true;
    if((10*b + a) % 8 == 0) ok = true;
    if(ok) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
    return 0;
  }

 // n> 3
  vector<int> num(10);
  REP(i,n){
    int x = (int)(s[i] - '0');
    num[x]++;
  }

  int x8 = 8;
  REP(i,1000){
    x8 += 8;
    if(x8 < 100) continue;
    //cout<< i << " " << x8 << endl;
    int tmp = x8;
     if(x8 > 1000) break;
    vector<int> cnt(10);
    cnt[tmp/100]++;
    tmp%=100;
    cnt[tmp/10]++;
    tmp%=10;

    cnt[tmp]++;

    if(cnt[0] > 0) continue;

    bool flg = true;

    REP(j,cnt.size()){
      if(cnt[j] > num[j]) flg = false;
    }
    if(flg){
      cout << "Yes" << endl;
      return 0;
    }

  }

  cout << "No" << endl;

  return 0;
}
