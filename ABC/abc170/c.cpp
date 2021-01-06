#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int x, n;
  cin >> x >> n;



  vector<int> p(n);
  vector<int> a;
  REP(i,n) cin >> p[i];

  for(int i = 0;i <= 101; ++i){
    a.push_back(i);
    REP(j,n){
      if( i == p[j]) a.pop_back();
    }
  }

  auto Iter1 = lower_bound(ALL(a), x);
  // cout << *Iter1  << endl;
  // cout << Iter1 - a.begin() << endl;
  int l = a[Iter1 - a.begin()];
  int r = a[Iter1 - a.begin()-1];

  if(abs(l-x) < abs(r-x)) cout << l << endl;
  else cout << r << endl;


  //
  // for(int i = 0;i < a.size() ; ++i){
  //   cout << a[i] << endl;
  // }


  return 0;
}
