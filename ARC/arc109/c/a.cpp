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



char win(char x, char y){
  if(x == 'S'){
    if(y == 'R') return 'R';
    else return 'S';
  }
  if(x == 'R'){
    if(y == 'P') return 'P';
    else return 'R';
  }
  if(x == 'P'){
    if(y == 'S') return 'S';
    else return 'P';
  }
}

string hand = "";

char f(int l, int r){
  if(r-l == 1) return win(hand[l], hand[r]);
  int m = (l+r)/2;
  return(win(f(l,m),f(m+1,r)));
}




int main(){
  //#define int long long
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  while(hand.size() > 128){
    hand += s;
  }

  char ans;
  cout << hand << endl;
  if(k > 14) ans = last;
  if(k > 7) ans = f(0,127);
  else ans = f(0, pow(2,k));

  int p = 4;
  int l = 0;
  int r = pow(2,k) - 1;
  cout << r << endl;

  char ans;
  ans = f(l,r);

  cout << ans << endl;

  cout << win('P', 'R') << endl;


  return 0;
}

