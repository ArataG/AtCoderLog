#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  double a, b, h, m;
  cin >> a >> b >> h >> m;
  double ans;
  double pi = 3.141592653589793238;
  double angle;
  double angle_h, angle_m;

  angle_m =  m/60;
  angle_h =  (h/12 + m/720);


  // cout << angle_h << endl;
  // cout << angle_m << endl;


  angle = abs(angle_m-angle_h) * 360;
  // cout << angle << endl;
  // cout << cos(90/180*pi) << endl;

  double tmp = a*a + b*b - 2*a*b * cos(angle / 180 * pi);

  ans = sqrt(tmp);
  printf("%.12lf\n", ans);


  return 0;

}
