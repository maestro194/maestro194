/*
  Author: CNH_Tourist as history - ICPC Northern Provincial Regional 2023
  Status: Not submitted
  ref: https://stackoverflow.com/questions/73802535/insert-elements-from-one-array-to-another-such-that-inversions-are-minimised
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

long long countInv(vector<int>& v, int tmp[], int l, int r, int mid) {
  long long cnt = 0;

  int i, j, k;
  i = l;
  j = mid;
  k = l;

  while((i <= mid - 1) && (j <= r)) {
    if(v[i] <= v[j])
      tmp[k ++] = v[i ++];
    else {
      tmp[k ++] = v[j ++];
      cnt += mid - i;
    }
  }

  while(i <= mid - 1)
    tmp[k ++] = v[i ++];
  while(j <= r)
    tmp[k ++] = v[j ++];
  for(i = l; i <= r; i ++)
    v[i] = tmp[i];

  // cout << "CountInv " << l << " " << r << ": " << cnt << endl;
  // for(i = l; i <= r; i ++)
  //   cout << v[i] << " ";
  // cout << endl;

  return cnt;
}

long long merge(vector<int>& v, int tmp[], int l, int r) {
  long long cnt = 0;
  if(v.size() <= 1)
    return 0;
  if(l < r) {
    int mid = (l + r) / 2;
    cnt += merge(v, tmp, l, mid);
    cnt += merge(v, tmp, mid + 1, r);
    cnt += countInv(v, tmp, l, r, mid + 1);
  }
  return cnt;
}

long long countInv1V(vector<int>& v) {
  int tmp[v.size()];
  return merge(v, tmp, 0, v.size() - 1);
}

void F(vector<int>& a, vector<int>& b, int la, int ra, int lb, int rb, vector<int>& mid) {
  if(lb >= rb)
    return;
  int mb = (lb + rb) / 2;
  int numb = b[mb];

  vector<int> tmp(ra - la + 1);
  for(auto id = a.begin() + la; id < a.begin() + ra; id ++)
    tmp.push_back(*id);

  long long cnt = 0;
  for(int i = la; i < ra; i ++)
    if(a[i] < numb)
      cnt ++;
  
  long long mn = cnt;
  int idx = la;

  for(int i = la; i < ra; i ++) {
    if(a[i] < numb)
      cnt --;
    else 
      cnt ++;

    if(cnt < mn) {
      mn = cnt;
      idx = i + 1;
    }
  }

  mid[mb] = idx;
  F(a, b, la, idx, lb, mb, mid);
  F(a, b, idx, ra, mb + 1, rb, mid);
  return;
}

void finalV(vector<int>& a, vector<int>& b, vector<int>& mid, vector<int>& fin) {
  int idxa = 0;
  int idxb = 0;
  for(int i = 0; i < a.size() + b.size(); i ++) {
    if(idxb < b.size() && i == mid[idxb] + idxb) {
      fin[i] = b[idxb];
      idxb ++;
    }
    else {
      fin[i] = a[idxa];
      idxa ++;
    }
  }
}

void Solve()
{
  cin >> n >> m;
  vector<int> a(n), b(m);
  for(int i = 0; i < n; i ++)
    cin >> a[i];
  for(int i = 0; i < m; i ++)
    cin >> b[i];
  sort(all(b));
  vector<int> mid(m);
  F(a, b, 0, n, 0, m, mid);
  vector<int> ans(n + m);
  finalV(a, b, mid, ans);

  // cout << "ans: ";
  // for(int i = 0; i < ans.size(); i ++) 
  //   cout << ans[i] << " ";
  // cout << endl;

  cout << countInv1V(ans) << endl;
}

int32_t main()
{
  FileInOut();
  using namespace std::chrono;
  auto start = high_resolution_clock::now();  

  int test = 1;
  cin >> test;
  while(test--)
    Solve();

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  double t = duration.count() * 1.0 / 1000000;
  cout << endl << "Runtime: " << t << endl;
}