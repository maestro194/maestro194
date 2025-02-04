/*
  Author: CNH_Tourist as history - ICPC Northern Provincial Regional 2023
  Status: Accepted
  Problem: https://oj.vnoi.info/problem/icpc23_mb_c
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

int n, m;
int num[10];
map<vector<int>, int> cache[111];
int mod = 1000000007;

int dp(int i, vector<int>& dist, vector<bool>& used) {
  if (i == n) 
    return 1;
  if (cache[i].count(dist))
    return cache[i][dist];

  int res = 0;
  for(int num = 0; num < 8; num ++) {
    if(!used[num])
      continue;

    if(dist[num] == num) {
      vector<int> new_dist(dist.size());
      for(int i = 0; i < 8; i ++)
        new_dist[i] = min(i, dist[i] + 1);
      new_dist[num] = 0;

      res = (res + dp(i + 1, new_dist, used)) % mod;
    }
  }

  return cache[i][dist] = res;
}

void Solve()
{
  cin >> n >> m;
  for(int i = 0; i < m; i ++)
    cin >> num[i];

  vector<int> dist(8);
  vector<bool> used(8);
  iota(dist.begin(), dist.end(), 0);
  for(int i = 0; i < m; i ++)
    dist[num[i] - 1] = num[i] - 1,
    used[num[i] - 1] = true;

  cout << dp(0, dist, used);
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
  cout << endl << "Runtime: " << t << "s" << endl;
}