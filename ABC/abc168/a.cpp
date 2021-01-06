#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;

  if(n%10 == 3) cout << "bon" << endl;
  else if (n%10 == 0 || n%10 == 1 || n%10 == 6 ||n%10 == 8) cout << "pon" << endl;
  else cout << "hon" << endl;

  return 0;
}
