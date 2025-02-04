/*
  Author: CNH_Tourist as history - ICPC Southern Provincial Regional 2023
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

int n;
int a[50005];
int l[50005], r[50005];

void Solve()
{
  cin >> n;
  for(int i = 1; i <= n; i ++)
    cin >> a[i];
  int ans = 0;

  l[1] = 1;
  for(int i = 2; i <= n; i ++) {
    if(a[i] > a[i - 1])
      l[i] = l[i - 1] + 1;
    else
      l[i] = min(l[i - 1] + 1, a[i]);
  }

  r[n] = 1;
  for(int i = n - 1; i >= 1; i --) {
    if(a[i] > a[i + 1])
      r[i] = r[i + 1] + 1;
    else  
      r[i] = min(r[i + 1] + 1, a[i]);
  }

  for(int i = 1; i <= n; i ++) {
    ans = max(ans, min(l[i], r[i]));
    // cout << i << " " << l[i] << " " << r[i] << endl;
  }

  cout << ans;
}

int32_t main()
{
  FileInOut();

  int test = 1;
  // cin >> test;
  while(test--)
    Solve();
}