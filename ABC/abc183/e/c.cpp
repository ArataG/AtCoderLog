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
  
  int H,W;
  cin >> H >> W;

  vector<string> s(H);

  REP(h,H) cin >> s[h];

 //REP(h,H) cout << s[h] << endl;
 ll a[H][W];
 ll dp[H][W];
 REP(h,H)REP(w,W) a[h][w] = 0, dp[h][w] = 0;

 dp[0][0] = 1;
 //init dp
int sum = 1; 
REP2(w,1,W){
  if(s[0][w] == '#') break;
   dp[0][w] = sum;
   sum += dp[0][w]; 
}

sum = 1;
REP2(h, 1, H){
   if(s[h][0] == '#') break;
  dp[h][0] = sum;
  sum += dp[h][0];
}

// REP(h,H){
//     REP(w,W){
//       cout << dp[h][w] << " ";
//     } 
//     cout << endl;
//   }

//dp

 REP2(h,1,H){
   REP2(w,1,W){
     if(s[h][w] == '#'){
       continue;
     } 
    if(h == 1 && w == 1){
     dp[h][w] += dp[h][w-1];
     dp[h][w] += dp[h-1][w];
     dp[h][w] += dp[h-1][w-1];
    }
    else if (h > 1 && w > 1) {
     if(s[h][w-1] != '#') dp[h][w] += dp[h][w-1]+dp[h][w-2];
     if(s[h-1][w] != '#') dp[h][w] += dp[h-1][w]+dp[h-2][w];
     if(s[h-1][w-1] != '#') dp[h][w] += dp[h-1][w-1]+dp[h-2][w-2];
    }
    else if(h == 1 && w != 1){
     if(s[h][w-1] != '#') dp[h][w] += dp[h][w-1] + dp[h][w-2];
     dp[h][w] += dp[h-1][w];
     dp[h][w] += dp[h-1][w-1]; 
    }
    else if(h != 1 && w == 1){
     dp[h][w] += dp[h][w-1];
     if(s[h-1][w] != '#') dp[h][w] += dp[h-1][w] + dp[h-2][w];
     dp[h][w] += dp[h-1][w-1];  
    }

   }
 }

cout << " h" << endl;
 REP(h,H){
    REP(w,W){
      cout << dp[h][w] << " ";
    } 
    cout << endl;
  }

cout << dp[H-1][W-1] << endl;

  return 0;
}