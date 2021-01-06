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

/*
  愚直解: 順番に集める
*/

class Card{
  public:
    int num;
    int x;
    int y;
    void show();
};

void Card::show(){
  cout << "card: "<< num << " (x,y)= " << x << " "<< y << endl;
}



int main(){
  //input
  int n = 100;
  vector<Card> card(n);
  REP(i,n){
    int x, y; cin >> x >> y;
    card[i] = {i, x, y};
  }
  
  //入力チェック
  //REP(i,n) card[i].show();

  string ans;

  int px, py;
  px = 0; py = 0;

  REP(i,n){
   int nx = card[i].x;
   int ny = card[i].y;
   //x(U or D)
   if(nx-px > 0) REP(j, nx-px) ans += 'D';
   else REP(j, px-nx) ans += 'U';
   //y(R or L)
   if(ny-py > 0) REP(j, ny-py) ans += 'R';
   else REP(j, py-ny) ans += 'L';
   
   //カードをひろう
   ans += 'I';
   px = nx;
   py = ny;
  }

  cout << ans << endl;

  return 0;
}