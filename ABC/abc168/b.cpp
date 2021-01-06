#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int k;
  string s;
  cin >> k;
  cin >> s;

  if(s.size() <= k) cout << s << endl;
  else{
    REP(i,k) cout << s[i];
    cout << "..." << endl;
  }

  return 0;

}
