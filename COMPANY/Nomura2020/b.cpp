#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  string t;
  cin >> t;
  REP(i,t.size()){
    if(t[i] == '?') t[i] = 'D';
  }
  cout << t << endl;
  return 0;



}
