/*
  Author: CNH_Tourist as history - ICPC Northern Provincial Regional 2023
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

int type;
int n, G;
int a[505][505];
int f[505][505];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

  queue<pii> nq[250025];

// dsu
pii p[505][505];
int h[505][505];
bool ok[505][505];

pii par(pii u) {
  int x = u.first, y = u.second;
  return u == p[x][y] ? u : p[x][y] = par(p[x][y]);
}

void join(int x, int y, int u, int v) {
  p[u][v] = par({u, v});
  p[x][y] = par({x, y});

  if(p[u][v] == p[x][y])
    return;

  // cout << x << "," << y << " (" << p[x][y].first << ", " << p[x][y].second << ") == ";
  // cout << u << "," << v << " (" << p[u][v].first << ", " << p[u][v].second << ")" << endl;
  
  int e = p[x][y].first;
  int k = p[x][y].second;
  int t = p[u][v].first;
  int j = p[u][v].second;

  if(h[e][k] <= h[t][j]) {
    p[e][k] = p[t][j];
    h[t][j] += h[e][k];
  } else {
    p[t][j] = p[e][k];
    h[e][k] += h[t][j];
  }
}

int solve1() {
  for(int i = 1; i <= n; i ++)
    for(int j = 1; j <= n; j ++)
      a[i][j] = 1;
  memset(f, 255, sizeof(f));
  priority_queue<int> q;
  f[1][1] = (a[1][1] < G ? 1 : 0);
  q.push(f[1][1]);
  nq[f[1][1]].push({1, 1});
  
  while(!q.empty()) {
    int id = q.top();
    q.pop();
    if(nq[id].empty())
      continue;
    pii cur = nq[id].front();
    nq[id].pop();

    if(cur == make_pair(n, n))
      continue;
    if(id != f[cur.first][cur.second])
      continue;

    for(int i = 0; i < 4; i ++) {
      int x = cur.first + dx[i];
      int y = cur.second + dy[i];

      if(x > n || x < 1 || y > n || y < 1)
        continue;
        
      if(f[x][y] == -1 || f[x][y] > id + (a[x][y] < G)) {
        f[x][y] = id + (a[x][y] < G);
        q.push(f[x][y]);
        nq[f[x][y]].push({x, y});
      }
    }  
  }
  return f[n][n];
}

int solve2() {
  vector<pair<int, pii> > v;
  for(int i = 1; i <= n; i ++)
    for(int j = 1; j <= n; j ++)
      cin >> a[i][j];

  for(int i = 1; i <= n; i ++) 
    for(int j = 1; j <= n; j ++) {
      cin >> a[i][j];
      v.push_back({a[i][j], {i, j}});
      p[i][j] = {i, j};
      ok[i][j] = false;
    }
  sort(all(v), greater<pair<int,pii> >());

  for(int i = 0; i < n * n; i ++) {
    int ans = v[i].first;


    // for(int j = 0; j < n * n; j ++)
    //   if(v[j].first == ans)
    //     cout << v[j].first << " " << v[j].second.first << " " << v[j].second.second << endl;


    while(i < n * n && v[i].first == ans) {
      ok[v[i].second.first][v[i].second.second] = true;
      h[v[i].second.first][v[i].second.second] = 1;

      for(int j = 0; j < 4; j ++) {
        int x = v[i].second.first + dx[j];
        int y = v[i].second.second + dy[j];

        if(x > n || x < 1 || y > n || y < 1)
          continue;

        if(ok[x][y])
          join(v[i].second.first, v[i].second.second, x, y);

      }
      i ++;
    }
    i --;

    p[1][1] = par({1, 1});
    p[n][n] = par({n, n});
    // cout << "Current: " << ans << endl;
    // for(int j = 1; j <= n; j ++) {
    //   for(int k = 1; k <= n; k ++)
    //     cout << "(" << p[j][k].first << ", " << p[j][k].second << ") ";
    //   cout << endl; 
    // } 
    // cout << endl;

    if(p[1][1] == p[n][n])
      return ans;
  }
  return 0;
}

void Solve()
{
  using namespace std::chrono;
  auto start = high_resolution_clock::now();  

  cin >> type;
  if(type == 1) {
    cin >> n >> G;
    cout << solve1();
  } else {
    cin >> n;
    cout << solve2();
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  double t = duration.count() * 1.0 / 1000000;
  cout << endl << "Runtime: " << t << endl;
}

int32_t main()
{
  FileInOut();

  int test = 1;
  // cin >> test;
  while(test--)
    Solve();
}