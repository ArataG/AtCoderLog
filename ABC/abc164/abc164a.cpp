#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int sheep, wolf;
  cin >> sheep >> wolf;

  if(sheep > wolf) cout << "safe" << endl;
  else cout << "unsafe" << endl;

  return 0;
}
