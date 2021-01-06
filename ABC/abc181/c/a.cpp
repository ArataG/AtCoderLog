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


/* next combination */
int next_combination(int sub) {
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}

int main(){
  int n;
  cin >> n;

  vector<int> x(n);
  vector<int> y(n);

  REP(i,n) cin >> x[i] >> y[i];

  int k = 3;

  bool ok = false;

  int bit = (1<<k)-1;  // bit = {0, 1, 2}
  for (;bit < (1<<n); bit = next_combination(bit)) {
      /* ここに処理を書く */
      /* きちんとできていることを確認してみる */
      // bit の表す集合を求める
      //vector<int> S;
      vector<int> TX;
      vector<int> TY;

      for (int i = 0; i < n; ++i) {
          if (bit & (1<<i)) { // i が bit に入るかどうか
              //S.push_back(i);
             // cout << "i" << i << endl;
              TX.push_back(x[i]);
              TY.push_back(y[i]);
          }
      }

      //for (int i = 0; i < (int)S.size(); ++i) {
      debug(TX);
      debug(TY);

      // bit の表す集合の出力
      //x
      // if(TX[0] == TX[1] && TX[1] == TX[2]) ok = true;
      // if(TY[0] == TY[1] && TY[1] == TY[2]) ok = true;
      // if(ok){
      //   cout << "Yes" << endl;
      //   return 0;
      // }
      //d
      int dx1 = TX[1] - TX[0];
      int dy1 = TY[1] - TY[0];
      int dx2 = TX[2] - TX[0];
      int dy2 = TY[2] - TY[0];



      if((ll)dx1 * dy2 == (ll) dx2 * dy1) {
        // if(dx1 == 0 && dy1 == 0) continue;
        // if(dx1 == 0 && dy2 == 0) continue;
        // if(dx2 == 0 && dy1 == 0) continue;
        // if(dx2 == 0 && dy2 == 0) continue;
        ok = true;
      }
    

      if(ok){
        cout << "Yes" << endl;
        return 0;
      }
      //}
    }

  if(ok){
        cout << "Yes" << endl;
        return 0;
    }
      

  cout << "No" << endl;
  return 0;
}