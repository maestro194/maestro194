/*
  Author: CNH_Tourist as history - ICPC Northern Provincial Regional 2023
  Status: Accepted
  Problem: https://oj.vnoi.info/problem/icpc23_mb_d
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

int n, m, k;
int mod = 123456789;

void Solve()
{
  cin >> n >> m >> k;
  if (n > m)
    swap(n, m);
  
  vector<int> goodMask;
  for(int i = 0; i < (1 << n); i ++) {
    if(i & (i >> 1)) continue;
    if(i & (i << 1)) continue;
    goodMask.push_back(i);
  }

  // for(int i = 0; i < goodMask.size(); i ++)
  //   cout << goodMask[i] << " ";
  // cout << endl;

  vector<vector<int>> edge(goodMask.size());
  for(int i = 0; i < goodMask.size(); i ++) {
    int mask = goodMask[i];

    for(int j = 0; j < goodMask.size(); j ++) {
      int mask2 = goodMask[j];
      if(mask & (mask2 << 1) || (mask & mask2) || mask & (mask2 >> 1))
        continue;
      
      edge[i].push_back(j);
    }
  }

  int f[m + 1][k + 1][goodMask.size()];
  memset(f, 0, sizeof(f));
  f[0][0][0] = 1;
  for(int row = 0; row < m; row ++) {
    for(int cnt = 0; cnt <= k; cnt ++) {
      for(int i = 0; i < goodMask.size(); i ++) {
        if(f[row][cnt][i] == 0)
          continue;
        
        for(auto j: edge[i]) {
          int mask = goodMask[j];
          int newCnt = cnt + __builtin_popcount(mask);
          if(newCnt > k)
            continue;

          f[row + 1][newCnt][j] = (f[row + 1][newCnt][j] + f[row][cnt][i]) % mod;
        }
      }
    }
  }

  // for(int i = 0; i < m; i ++) {
  //   for(int j = 0; j <= k; j ++) {
  //     for(int l = 0; l < goodMask.size(); l ++)
  //       cout << f[i][j][l] << " ";
  //     cout << endl;
  //   }
  //   cout << endl;
  // }

  int ans = 0;
  for(int i = 0; i < goodMask.size(); i ++)
    ans = (ans + f[m][k][i]) % mod;

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