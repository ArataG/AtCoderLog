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

void solve(){
  char s, t;
  cin >> s >> t;
  if(s == 'Y') t+='A' - 'a';
  cout << t << endl;
  return;
}

int main(){
  string s, t;
  cin >> s >> t;
  if(s == "N"){
    cout << t << endl;
    return 0;
  }

  if(t == "a"){
    cout << "A" << endl;
  }
  else if (t=="b"){
    cout << "B" << endl;
  }
  else cout << "C" << endl;

  return 0;

}

/*
アスキーコードについての知識があると解くのが容易に鳴る．
'A' : 65
'B' : 66

小文字から大文字にしたい
x-'a'+'A'
*/
