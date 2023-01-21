// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1194/

#include <bits/stdc++.h>

//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/trie_policy.hpp>

using namespace std;

//using namespace __gnu_pbds;
//typedef tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>Set;

//find_by_order(k) and order_of_key(k)



#define ll             long long int
#define ld             long double
#define mod            1000000007
#define inf            1e18
#define vecl            vector<long long>
#define vect           vector<vector<long long>>
#define vecb           vector<vector<bool>>
#define pb             push_back
#define all(n)         n.begin(),n.end()
#define loop(i,n)      for(int i=0;i<(n);++i)
#define loopa(i,a,n)    for(int i=a;i<=(n);++i)
#define loopr(i,a,n)   for(int i=a;i>=(n);--i)
#define sq(x)          x*x
#define cube(x)        x*x*x
#define endl           "\n"


void init_code() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output3.txt", "w", stdout);
#endif
}


ll n, m;
vector<pair<ll, ll>>monsters;
vector<vector<ll>>g;
map<pair<ll, ll>, pair<ll, ll>>par_mp;
pair<ll, ll>si, se;
vector<pair<ll, ll>>moves = {{ -1ll, 0ll}, {1ll, 0ll}, {0ll, 1ll}, {0ll, -1ll}};

//red zone

bool isValid(ll x, ll y, ll timer) {
  if (x<0 or y<0 or x >= n or y >= m)return false;
  if (g[x][y] <= timer)return false;

  return true;
}

bool isescape(ll x, ll y, ll timer) {
  if (!isValid(x, y, timer))return false;
  if (x == 0 or y == 0 or x == n - 1 or y == m - 1)return true;
  return false;
}

void  preprocess_lava_flow() {
  queue<pair<pair<ll, ll>, ll>>q;

  for (auto m : monsters) {
    q.push(make_pair(m, 0));
  }

  while (!q.empty()) {
    ll cx = q.front().first.first;
    ll cy = q.front().first.second;
    ll timer = q.front().second;
    timer++; q.pop();

    for (auto mv : moves) {
      ll tx = cx + mv.first;
      ll ty = cy + mv.second;

      if (isValid(tx, ty, timer)) {
        g[tx][ty] = timer;
        q.push({{tx, ty}, timer});
      }
    }
  }
}

bool bfs_escape() {
  queue<pair<pair<ll, ll>, ll>>q;
  q.push({si, 0});
  par_mp[si] = { -1, -1};
  while (!q.empty()) {
    ll cx = q.front().first.first;
    ll cy = q.front().first.second;
    ll timer = q.front().second;
    timer++; q.pop();

    for (auto mv : moves) {
      ll tx = cx + mv.first;
      ll ty = cy + mv.second;
      if (isescape(tx, ty, timer)) {
        par_mp[ {tx, ty}] = {cx, cy};
        se = {tx, ty};
        return true;
      }
      if (isValid(tx, ty, timer)) {
        par_mp[ {tx, ty}] = {cx, cy};
        g[tx][ty] = timer;
        q.push({{tx, ty}, timer});
      }
    }
  }

  return false;
}






int main(int argc, char const *argv[])
{
  //clock_t start=clock();
  init_code();

  //write your code here
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < n; ++i)
  {
    g[i].resize(m);
  }

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      g[i][j] = INT_MAX;
    }
  }

  for (ll i = 0; i < n; ++i)
  {
    for (ll j = 0; j < m; ++j)
    {
      char c; cin >> c;
      if (c == '#')
      {
        g[i][j] = 0;
      }
      else if (c == 'M')
      {
        g[i][j] = 0;

        monsters.push_back({i, j});
      }
      else if (c == 'A')
      {
        g[i][j] = 0;
        si = {i, j};
      }
      else
      {
        g[i][j] = INT_MAX;
      }
    }
  }
  if (si.first == 0 or si.second == 0 or si.first == n - 1 or si.second == m - 1)
  {
    cout << "YES" << endl;
    cout << 0;
    return 0;
  }
  preprocess_lava_flow();

  if (!bfs_escape())
  {
    cout << "NO";
    return 0;
  }
  cout << "YES" << endl;
  pair<ll, ll> tmp = se;
  pair<ll, ll> tmp1 = par_mp[se];
  pair<ll, ll> ed = { -1, -1};
  vector<char> ans;
  while (tmp1 != ed)
  {

    if ((tmp.second - tmp1.second) == 1 and (tmp.first - tmp1.first) == 0)
    {
      ans.push_back('R');
    }
    if ((tmp.second - tmp1.second) == -1 and (tmp.first - tmp1.first) == 0)
    {
      ans.push_back('L');
    }
    if ((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == 1)
    {
      ans.push_back('D');
    }
    if ((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == -1)
    {
      ans.push_back('U');
    }
    tmp = par_mp[tmp];
    tmp1 = par_mp[tmp];
  }
  reverse(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (auto c : ans)
  {
    cout << c;
  }




  /*
   #ifndef  ONLINE_JUDGE
    clock_t end=clock();
   cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
   #endif
   */
  return 0;
}