#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n, m;
  ll k;
  cin >> n >> m >> k;
  vector<int> a(n,0);
  vector<int> b(m,0);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= m; ++i) cin >> b[i];
  //vector<int> sumA;
  vector<ll> sumB;
  ll sum = 0;
  REP(i,m){
    sum += b[i];
    sumB.push_back(sum);
    if(sum > k) break;
  }

  int MX = 0;
  REP(i,a.size()+1){
    k -= a[i];
    if(k < 0) break;
    if(k == 0){
      MX = max(MX, i);
      break;
    }
    //int ai = 0;
    int bi = 0;
    bi = upper_bound(ALL(sumB),k) -sumB.begin()-1;
    // if(i == a.size()) ++ai;
    if(bi == sumB.size()-1) ++bi;
    MX = max(MX, i+bi);
    //cout << i << " " << bi << " "<< MX << endl;
  }
  cout << MX << endl;
  return 0;
}
