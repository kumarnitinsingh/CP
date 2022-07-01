// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/maximum-total-importance-of-roads/

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


class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>graph[n];
        
        for(auto e:roads){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)indegree[i]=graph[i].size();
        
         vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++)v[i]={indegree[i],i};
        
        sort(v.begin(),v.end());
         
        vector<int>val(n);
        int i=1;
        for(auto e:v){
            val[e.second]=i++;
        }
        
        long long sum=0;
        for(auto e:roads){
            int u=e[0];
            int v=e[1];
            sum=sum+val[u]+val[v];
        }
        return sum;
    }
};







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