// Created by Nitin kumar singh
// problem link -> https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1#

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

int dp[201][201][2];
int solve(string s,int i,int j,bool istrue){
    if(i>j)return 0;
    if(i==j){
        if(istrue)return s[i]=='T';
        else return s[i]=='F';
    }
    int x=istrue;
    if(dp[i][j][x]!=-1)return dp[i][j][x];
    int temp=0;
    for(int k=i+1;k<=j-1;k+=2){
        int leftT=solve(s,i,k-1,true);
        int leftF=solve(s,i,k-1,false);
        int rightT=solve(s,k+1,j,true);
        int rightF=solve(s,k+1,j,false);
        
        if(s[k]=='&'){
            
            if(istrue)temp+=leftT*rightT;
            
            else temp+=leftF*rightF+rightF*leftT+leftF*rightT;
        }
        else if(s[k]=='^'){
            if(istrue)temp+=leftT*rightF+rightT*leftF;
            else temp+=leftT*rightT+rightF*leftF;
        }
        else{
           if(istrue) temp+=leftT*rightF+leftF*rightT+rightT*leftT;
           else temp+=leftF*rightF;
        }
    }
    return dp[i][j][istrue]=temp%1003;
}


    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof dp);
        int op1=solve(S,0,N-1,true);
       //nt op2=solve(S,0,N-1,false);
        return (op1)%1003;
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