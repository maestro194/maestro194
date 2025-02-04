/*
  Author: CNH_Tourist as history - ICPC Northern Provincial Regional 2023
  Status: Accepted
*/
#include <bits/stdc++.h>
#pragma GCC optimization ("unrolled-loops")
using namespace std;

#define filename "test"
#define endl '\n'
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ll long long
#define all(x) (x).begin(),(x).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define CBIT __builtin_popcount
#define gcd __gcd

void FileInOut()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  ifstream *fi = new ifstream (filename".inp");
  ofstream *fo = new ofstream (filename".out");
  if(*fi)
  {
    cin.rdbuf( fi->rdbuf() );
    cout.rdbuf( fo->rdbuf() );
  }

}
// unusual mod : 1000003999
// atan2(y, x): tinh goc tao boi oX va diem co toa do (x, y)

int a, b, c, d;

void Solve()
{
  cin >> a >> b >> c >> d;

  vector<int> uoc;
  for(int i = 1; i * i <= c; i ++) {
    if(c % i == 0) {
      uoc.push_back(i);
      uoc.push_back(c / i);
    }
  }
  sort(all(uoc));

  for(auto x : uoc) {
    if(x % a == 0 && x % b != 0 && d % x != 0) {
      cout << x;
      return;
    }
  }
  cout << -1;
}

int32_t main()
{
  FileInOut();

  int test = 1;
  // cin >> test;
  while(test--)
    Solve();
}