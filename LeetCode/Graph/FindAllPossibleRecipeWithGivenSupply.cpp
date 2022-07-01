// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/

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
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
           int n=recipes.size();
          map<string,vector<string>>graph;
            map<string,int>indegree;
           for(int i=0;i<n;i++){
               for(auto g:ingredients[i]){
                    graph[g].push_back(recipes[i]);
                     indegree[recipes[i]]++;
               }
           }
        queue<string>q;
        vector<string>ans;
        for(auto e:supplies){
            if(indegree[e]==0)q.push(e);
        }
        
        
        while(q.size()){
            string u=q.front();
            q.pop();
            for(auto nbr:graph[u]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    ans.push_back(nbr);
                    q.push(nbr);
                }
            }
      
        }
        
        return ans;
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