#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 2000000000;
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
  int n, m;
  cin >> n >> m;
  vector<int> h(n);
  REP(i,n) cin >> h[i];
  vector<int> w(m);
  REP(i,m) cin >> w[i];

  // debug(w);
  
  sort(ALL(h));
  sort(ALL(w));
  

  vector<ll> diff1(n/2 + 1);
  vector<ll> diff2(n/2 + 1);

  ll sum = 0;

  //1
  int cc = 1;
  for(int i = 0; i < n-2; i += 2){
   int d = h[i+1] - h[i];
   sum += d;
   diff1[cc] = sum;
   cc++;
  }

  

  //2
  sum = 0;
  cc = 1;
  for(int i = 1; i < n-1; i += 2){
   int d = h[i+1] - h[i];
   sum += d;
   diff2[cc] = sum;
   cc++;
  }

  // debug(diff1);
  // debug(diff2);

  //自身の挿入箇所
  int ans = INF;
  REP(i,m){
    auto pos = lower_bound(ALL(h), w[i]) - h.begin();


    int befsum = INF;
    int aftsum = INF;
    //1 後ろと差分
   if( pos%2 == 0 ){
      ll pre = diff1[(pos)/2];
      ll mid = abs(h[pos] - w[i]);
      ll aft = diff2[n/2] - diff2[(pos)/2];
      aftsum = pre + mid + aft;
      debug(pos);
      debug(pre);
      debug(mid);
      debug(aft);
   }

    //2　前との差分
  if( pos%2 == 1 ){
    ll pre = diff1[(pos)/2];
    ll mid = abs(h[pos-1] - w[i]);
    ll aft = diff2[n/2] - diff2[(pos)/2];
    befsum = pre+mid+aft;
  }

  // debug(aftsum);
  // debug(befsum);

   ans = min({ans, befsum, aftsum});

  }

  cout << ans << endl;

  return 0;
}
