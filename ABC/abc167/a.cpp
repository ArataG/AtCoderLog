#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  if(a >= k){
    cout << k << endl;
    return 0;
  }
  else if (a < k && a+b >= k){
    cout << a << endl;


  }
  else{
    cout << a - (k - a -b) << endl;
    return 0;
  }


  return 0;
}
