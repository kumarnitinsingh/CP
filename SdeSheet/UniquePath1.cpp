// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/unique-paths/

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
#define vec            vector<long long>
#define vect           vector<vector<long long>>
#define vecb           vector<vector<bool>
#define pb             push_back
#define all(n)         n.begin(),n.end()
#define loop(i,n)      for(int i=0;i<(n);++i)
#define loopa(i,a,n)    for(int i=a;i<=(n);++i)
#define loopr(i,a,n)   for(int i=a;i>=(n);--i)
#define sq(x)          x*x
#define cube(x)        x*x*x



void init_code(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}


// Time O(n*m);
 int uniquePaths(int m, int n) {
       int grid[m][n];
         for(int i=0;i<m;i++)grid[i][0]=1;
         for(int i=0;i<n;i++)grid[0][i]=1;
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                grid[i][j]=grid[i][j-1]+grid[i-1][j];
            }
        }
        
        return grid[m-1][n-1];
        
    }

  // totalUniquePaths=((m+n-2)! / (m-1)!(n-1)!)  

       int uniquePaths1(int m, int n) {
        int N = n+m-2; // total steps = n-1 + m-1
        int r = min(n,m) - 1; // will iterate on the minimum for efficiency = (total) C (min(right, down))
        
        double res = 1;
        
        // compute nCr
        for(int i=1; i<=r; ++i, N--){
            
            res = res * (N) / i;
        }
        
        return (int)res;
    }


int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}