// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/russian-doll-envelopes/

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


bool mycom(vector<int>&v1,vector<int>&v2){
    if(v1[0]==v2[0])return v1[1]>v2[1];
     return v1[0]<v2[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& card) {
         sort(card.begin(),card.end(),mycom);
        int n=card.size();
      vector<int>ans;
        ans.push_back(card[0][1]);
        for(int i=1;i<n;i++){
            if(ans.back()<card[i][1]){
                ans.push_back(card[i][1]);
            }
            else{
                
                auto it=lower_bound(ans.begin(),ans.end(),card[i][1])-ans.begin();
                ans[it]=card[i][1];
            }
         }
        return ans.size();
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