// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/

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

class dsu{
    vector<int> parent;
    vector<int> rank;
    
    public:
    
    dsu(int n){
        parent.resize(n);
        iota(begin(parent), end(parent), 0);
        rank.resize(n, 1);
    }
    
    int findParent(int i){
        if(parent[i] != i){
            return findParent(parent[i]);
        }
        return i;
    }
    
    void Union(int x, int y){
        if(rank[x] < rank[y]){
            parent[y] = x;
        }
        else if(rank[x] > rank[y]){
            parent[x] = y;
        }
        else{
            parent[y] = x;
            rank[x]++;
        }
    }
    
};
class Solution {
public:
    int findCost(vector<vector<int>> edges, int n, vector<int> include, vector<int> exclude){     
        dsu parentCost(n);
        int count = 0;
        int i = 0;
        int parentMinCost = 0;
        
        if(include.size() != 0){
            int x = parentCost.findParent(include[0]);
            int y = parentCost.findParent(include[1]);
            parentMinCost += include[2];
            parentCost.Union(x, y);
            count++;
        }
        
        while(count != n - 1 and i < edges.size()){
            if(exclude.size() != 0 and edges[i] == exclude){
                i++;
                continue;
            }
            int x = parentCost.findParent(edges[i][0]);
            int y = parentCost.findParent(edges[i][1]);
            if(x != y){
                parentCost.Union(x, y);
                parentMinCost += edges[i][2];
                count++;
            }
            i++;
        }
        if(count == n - 1)
            return parentMinCost;
        
        return INT_MAX;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        map<vector<int>, int> mp;
        for(int i = 0; i < edges.size(); i++){
            mp[edges[i]] = i;
        }
        
        sort(edges.begin(), edges.end(), [&](vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        });
        vector<int> temp;
        
        int finalAns= findCost(edges, n, temp, temp);
        
        vector<int> ans1, ans2;;
        
        for(int i = 0; i < edges.size() ; i++){
            int cost1 = findCost(edges, n, temp, edges[i]);
            if(cost1 > finalAns){
                ans1.push_back(mp[edges[i]]);
            }
            else
            {
                int cost2 = findCost(edges, n, edges[i] , temp);
                if(cost2 == finalAns){
                    ans2.push_back(mp[edges[i]]);
                }
            }
        }
        
        
        return {ans1, ans2};
    }
};



int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();






   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}