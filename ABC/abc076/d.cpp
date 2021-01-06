#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);


double length(int t, int v, int pre_v, int next_v){
  double ans = 0;
  if(v <= next_v){
    ans += pre_v*t;

    v -= pre_v;

    if(v > t) ans = (double)(v)*/2 + (t-v)*v;
    else      ans = (double)t*t/2;
    return ans;
  }
   // if(v > next_v)
  else{
    

  }

  //maxv = v;

  //maxv = t/2;

}



int main(){
  int n;
  cin >> n;
  vector<int> t(n);
  vector<int> v(n);
  REP(i,n) cin >> t[i];
  REP(i,n) cin >> v[i];

  vector<int> dist(n);

  if(n == 1){
    double ans = 0;
    //台形
    if( v[0] + v[0] <  t[0]) ans = v[0]*v[0]/2 + (t[0] - v[0] - v[0])*v[0] + v[0]*v[0]/2;
    //ビッタリ
    if( v[0] + v[0] == t[0]) ans = v[0]*t[0]/2;
    //maxに到達しない
    if( v[0] + v[0]  > t[0]) {
      double x = (double)t[0]/2;
      ans = (double) x * t[0]/2;
    }

    cout << fixed << setprecision(6) <<  ans << endl;
    return 0;
  }

  //first
  dist[0] = v[0]*v[0]/2 + v[0]*(t[0]  - v[0]);
  //last
  //dist[n]

  //mid
  double sum = 0;

  REP2(i,1,n-1){
    sum += length(t[i], v[i], v[i-1], v[i+1]);
  }

  cout << sum << endl;



  return 0;
}
