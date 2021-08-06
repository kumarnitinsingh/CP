// Created by Nitin kumar singh
#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/trie_policy.hpp>


//using namespace_-gnu_pbds;
using namespace std;

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


bool canweplace(vector<vector<int>>&grid,int i,int j,int n){
    for(int k=0;k<n;k++){
        if(grid[i][k]==1 || grid[k][j]==1)return false;
    }
    int p=i-1;int q=j-1;
    while(p>=0 and q>=0){if(grid[p][q]==1)return false;
    p--;
    q--;
    }
    int r=i-1;int s=j+1;
    while(r>=0 and s<n){if(grid[r][s]==1)return false;
      r--;
      s++;
    }
    
    return true;
}
int c=0;

void Solve(vector<vector<int>>&grid,int i,int n){
    if(i==n){
          c=c+1;
        return ;}
    
    for(int j=0;j<n;j++){
     if(canweplace(grid,i,j,n)){
        grid[i][j]=1; 
        Solve(grid,i+1,n);
         grid[i][j]=0;        
     }

 }

}

vector<vector<int>> nQueen(int n){
//Write your code below. Do not modify this function or parameters. You can use helper function if needed.   
   vector<vector<int>>v(n,vector<int>(n,0));
   c=0;
    Solve(v,0,n);
  
    return {{c}};

}

//optimized using bitset
bitset<30>col,d1,d2;
 void Nqueen(int n,int i,int& ans){
    if(i==n){
        ans++;return;
    }
    for(int j=0;j<n;j++){
        if(!col[j] and !d1[i-j+n-1] and !d2[i+j]){
            col[j]=d1[i-j+n-1]=d2[i+j]=1;
            Nqueen(n,i+1,ans);
            col[j]=d1[i-j+n-1]=d2[i+j]=0;
        }
    }
    return;
 }

 //best and most optimized using bitmasking approach
 void solve(int rowmask,int ld1,int rd,int done ,int &ans){
  if(rowmask==done){ans++;return;}
  int safe=done & (~(rowmask|ld1|rd));
  while(safe){
    int p=safe & (-safe);
    safe=safe-p;
    solve(rowmask|p,(ld1|p)<<1,(rd|p)>>1,done,ans);
  }

 }

int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here
    int t;
    cin>>t;
    while(t--){
    int n;cin>>n;

     vector<vector<int>>ans=nQueen(n);
     cout<<ans[0][0]<<endl;}

    // cout<<c;
   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}