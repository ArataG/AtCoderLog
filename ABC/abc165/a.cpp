#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int k, a, b;
  cin >> k;
  cin >> a >> b;
  int ans = 0;


  for(int i = a; i <= b ; ++i){
    if(i%k == 0){
      ans = 1;
    }
  }

  if(ans) cout << "OK" << endl;
  else cout << "NG" << endl;

}
