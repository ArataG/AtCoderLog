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
  工夫: カードを先によせ集める 
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

  const int HMAX = 20;
  const int WMAX = 20;


  string ans;

  /*
    カードの回収
  */
  stack<int> hands;

  REP(i,HMAX){
    if(i%2 == 0)REP(j,WMAX){
      REP(k,n){
        if(card[k].x == i && card[k].y == j) {
          hands.push(card[k].num);
          ans += 'I';
        }
      }
      if(j!=19) ans += 'R';
    }
    else DREP(j,WMAX){
      REP(k,n){
        if(card[k].x == i && card[k].y == j) {
          hands.push(card[k].num);
          ans += 'I';
        }
      }
      if(j!=0) ans += 'L';
    }
    if(i != 19) ans += 'D';
  }
  
  /*
    山札を置く start = (19, 0)
  */
  for(int i = 19; i >= 10; i--){

    if(i%2)REP(j,10){
      ans += 'O'; //置く
      int n = hands.top(); hands.pop();
      card[n].x = i;
      card[n].y = j;
      if(j == 9) continue;
      ans += 'R'; 
    }
    else DREP(j, 10){
      ans += 'O'; //置く
      int n = hands.top(); hands.pop();
      card[n].x = i;
      card[n].y = j;
      if(j == 0) continue; 
      ans += 'L';
    }
    if(i == 10) continue;
    ans += 'U';
  }
  
  /*
    カードを順番に回収
  */
  int px, py;
  px = 10; py = 0;

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

/*

  改善できるところ
  - カードの回収で, 遠回りをしている. (最短経路が計算できる?)
  - カードを回収しなくてもいい座標(10-19,0-10) でも回収している
*/