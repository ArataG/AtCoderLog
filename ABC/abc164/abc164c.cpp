#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
int n;
cin >> n;
set<string> st;
REP(i, n){
  string s;
  cin >> s;
  st.insert(s);
}

cout << st.size() << endl;
return 0;
}
