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
  int h, w, m;
  cin >> h >> w >> m;
  vector<pair<int,int>> bom(m);
  map<int,int> tate;
  map<int,int> yoko;
  map<int, map<int,bool>> mp; //二重のmap > pair型のデータ構造の探索に使える

  REP(i,m){
    int t, y;
    cin >> t >> y;
    bom[i] = make_pair(t,y);
    tate[t]++;
    yoko[y]++;
    mp[t][y] = true;
  }

  int tatemax = 0;
  int yokomax = 0;
  for(auto x: tate){
    if(tatemax < x.second){
      tatemax = max(tatemax, x.second);
    }
  }
  for(auto x: yoko){
    if(yokomax < x.second){
      yokomax = max(yokomax, x.second);
    }
  }

  int ans = tatemax + yokomax;


  //その点がにボムがあったら-1
  vector<int> tatekouho;
  vector<int> yokokouho;
  for(auto x: tate){
    if(x.second == tatemax){
      tatekouho.push_back(x.first);
    }
  }
  for(auto x: yoko){
    if(x.second == yokomax){
      yokokouho.push_back(x.first);
    }
  }
  sort(ALL(tatekouho));
  sort(ALL(yokokouho));
  // // for(auto x: tatekouho) cout << x << endl;
  // // cout <<"yoko" <<endl;
  // // for(auto x: yokokouho) cout << x << endl;

  // int bar[h+1][w+1] = {};
  // REP(i,m){
  //   bar[bom[i].first][bom[i].second] = 1;
  // }

  // // REP(i,h+1){
  // //   REP(j,w+1){
  // //     cout << bar[i][j];
  // //   }
  // //   cout << endl;
  // // }

  // //M回捜索
  // bool ok = true;
  // REP(i,tatekouho.size()){
  //   REP(j,yokokouho.size()){
  //     //cout << tatekouho[i] << " " << yokokouho[j] << endl;
  //     if(bar[tatekouho[i]][yokokouho[j]] != 1) {
  //       ok = false;
  //       break;
  //     }
  //   }
  // }
  //M回捜索
  bool ok = true;
  REP(i,tatekouho.size()){
    REP(j,yokokouho.size()){
      //cout << tatekouho[i] << " " << yokokouho[j] << endl;
      if(mp[tatekouho[i]][yokokouho[j]]) continue;
      ok = false;
      break;
    }
  }

  if(!ok) cout << ans << endl;
  else cout << ans-1 << endl;

  return 0;
}