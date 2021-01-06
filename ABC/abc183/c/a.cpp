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
  int n, k;
  cin >> n >> k;

  int t[n][n];
  REP(i,n) REP(j,n) cin >> t[i][j];
  
  // REP(i,n) REP(j,n) cout <<  t[i][j] << " ";
  int ans = 0;
    vector<int> one_case;
    for (int i = 1; i < n; i++) { // one_case = {0,1,2,3,...n-1} とする
        one_case.emplace_back(i);
    }

    do {
        int pre = 0;
        int now = 0;
        int sum = 0;
        for (auto x : one_case) {
            //cout << x << " ";
            now = x;
            sum += t[pre][now];
            pre = now;
        }
        sum += t[pre][0];
        //cout << sum << endl;
        if(sum == k) ans++;
    } while (next_permutation(one_case.begin(), one_case.end()));
    // 順列の最後になるまで one_case を並び替えながらループ

    cout << ans << endl;


  
  return 0;
}