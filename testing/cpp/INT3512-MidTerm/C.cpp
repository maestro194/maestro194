/*
  Author: CNH_Tourist
  Status: Not submitted
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

int n, k;
int a[500005];
int pre[32][500005];

void Solve()
{
  cin >> n >> k;
  for(int i = 1; i <= n; i ++) 
    cin >> a[i];

  for(int i = 1; i <= n; i ++) {
    for(int j = 0; j < 30; j ++) {
      if(a[i] & (1 << j))
        pre[j][i] = pre[j][i - 1] + 1;
      else 
        pre[j][i] = pre[j][i - 1];
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; i ++) {
    int l = i, r = n, m;

    while (l <= r) {
      m = (l + r) >> 1;
      int sum = 0;

      for(int j = 0; j < 30; j ++)
        if(pre[j][m] - pre[j][i - 1] == m - i + 1)
          sum += (1 << j);
      
      // cout << " " << i << " " << m << " " << sum << endl;

      if(sum >= k)
        l = m + 1;
      else 
        r = m - 1;
    }
    // cout << i << " " << r << endl;

    ans = max(ans, r - i + 1);
  }
  cout << ans;

}

int32_t main()
{
  using namespace std::chrono;
  auto start = high_resolution_clock::now(); 
  FileInOut(); 

  int test = 1;
  // cin >> test;
  while(test--)
    Solve();

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  double t = duration.count() * 1.0 / 1000000;
  // cout << endl << "Runtime: " << t << endl;
}

