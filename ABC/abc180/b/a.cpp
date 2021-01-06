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
    vector<ll> x(n);
    REP(i,n) cin >> x[i];

    ll ans1 = 0;
    REP(i,n){
      ans1 += abs(x[i]);
    }

    cout << ans1 << endl;
    
    ll ans2 = 0;
    REP(i,n){
      ans2 += x[i]*x[i];
    }
    double ans22 = sqrt(ans2);

    cout << fixed << setprecision(10) << ans22 << endl;
    //fixed: 小数点部の桁数を性格に指定したい場合の書式フラグ
    //setprecision 浮動小数点型の桁数を指定できるマニュピレーター：
    //fixedがないと小数部の桁数が不定になってしまうので注意．

    int ans3 = 0;
    REP(i,n){
      if(ans3 < abs(x[i])) ans3 = abs(x[i]);
    }

    cout << ans3 << endl;



    return 0;
  }

  /*
  ｛

  ｝
  複数の答え求める時は，スコープで切ると変数を気にしなくてすむので便利．


  */