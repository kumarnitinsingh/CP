// Created by Nitin kumar singh
// problem link ->  https://cses.fi/problemset/task/1624/

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


void init_code(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output3.txt","w",stdout);
    #endif
}


int cn=0;
string s;

void solve(int n,int i,int j,vector<vector<int>> &visited,string osf,vector<int>&temp){
if(osf.size()>1 and binary_search(temp.begin(),temp.end(),osf.size()-1) and osf[osf.size()-1]!=s[osf.size()-1])return;
if(osf.size()>s.size())return;   
        if(i==n-1 and j==0){
            int f=1;

            for(int i:temp){
             
            if(i<osf.size() and s[i] != osf[i]){
                f=0;
                break;
            }
        }
        if(f and osf.size()==s.size())cn++;
            return;
        }

        if(i<0 or j<0 or j>=n or i>=n)return;

        if(visited[i][j])return;

        visited[i][j]=1;
        solve(n,i,j-1,visited,osf+"L",temp);
        solve(n,i-1,j,visited,osf+"U",temp);
        solve(n,i,j+1,visited,osf+"R",temp);
        solve(n,i+1,j,visited,osf+"D",temp);
        visited[i][j]=0;
        return;


}
int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code 
     

     cin>>s;
     vector<int>temp;

        for(int i=0;i<s.size();i++){
            if(s[i]!='?')temp.push_back(i);
        }
     const int n=6;

     vector<vector<int>>visited(n,vector<int>(n,0));
     string osf="";
     solve(n,0,0,visited,osf,temp);
     

        

     cout<<cn<<endl;

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
        
}