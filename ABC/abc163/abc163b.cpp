#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i <(n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> data(m);
  rep(i, m) cin >> data.at(i);

  int sum = 0;

  rep(i,m){
    sum += data.at(i);
  }

  if(n-sum >= 0){
    cout << n - sum << endl;
  }
  else{
    cout << -1 << endl;
  }
}
