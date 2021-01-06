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
#define REP(i,n) for (int i = 0; i <(n); ++i)
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << " :";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }


#define SEG_LEN (1 << 18) //10^5 より大きい２進数, index = 1から利用する．
int seg[SEG_LEN * 2];

void add(int ind, int x){
  ind += SEG_LEN;
  seg[ind] += x;
  while(true){
    ind /= 2;
    if(ind == 0) break;
    seg[ind] = seg[ ind * 2 ]+seg[ ind * 2 + 1 ];
  }

}

int sum(int l, int r){
  l += SEG_LEN;
  r += SEG_LEN;
  long long ans = 0;
  while(l < r){
    if(l%2 == 1){
      ans += seg[l];
      l++;
    }
    l /= 2;

    if(r%2 == 1){
      ans += seg[r - 1];
      r--;
    }
    r /= 2;
  }
  return ans;
}

int main(){
  int n, q;
  cin >> n >> q;
  //add
  // REP(i,n){
  //   int a;
  //   cin >> a;
  //   add(i,a);
  // }

  REP(i,n){
    int a;
    cin >> a;
    int ind = i + SEG_LEN;
    seg[ind] = a;
  }

  

  REP(i,q){
    int l, r;
    cin >> l >> r;
    cout << sum(l,r+1) << endl;
  }

  
  
  return 0;
}