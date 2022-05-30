// Created by Nitin kumar singh
// problem link -> https://www.interviewbit.com/problems/regular-expression-match/

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



int Solution::isMatch(const string a, const string b) {
 int n=a.length(),m=b.length();
    vector<vector<bool>> v(n+1,vector<bool>(m+1));
    for(int i=0;i<=n;i++){
        v[i][0]=false;
    }
    v[0][0]=true;
    for(int i=1;i<=m;i++){
        v[0][i]=true;
        for(int j=1;j<=i;j++){
            if(b[j-1]!='*'){
                v[0][i]=false;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1] || b[j-1]=='?'){
                v[i][j]=v[i-1][j-1];
            }
            else if(b[j-1]=='*'){
                v[i][j]=v[i-1][j] || v[i][j-1];
            }
            else{
                v[i][j]=false;
            }
        }
    }
    return v[n][m];
}








int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();
    
     //write your code here





   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}