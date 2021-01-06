#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



//forループ回すだけ

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  int cnt = 0;

  REP(i,n){
    bool ok = true;
    if((i+1)%2 == 0) ok = false;
    if(a[i] % 2 == 0) ok = false;

    if(ok) ++cnt;

  }

  cout << cnt << endl;
  return 0;
}
