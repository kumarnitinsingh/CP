// Created by Nitin kumar singh
// problem link ->

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

 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int maxidx=0;
        int ma=INT_MIN;
        vector<int>ans;
        int n=nums.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<k;i++){
            if(nums[i]>=ma){
                ma=nums[i];
                maxidx=i;
            }
            pq.push({nums[i],i});
        }
        ans.push_back(ma);
        int i=1;int j=k;
        while(i<n and j<n){
              pq.push({nums[j],j});
            if(maxidx<i ){
                while(!pq.empty() and pq.top().second<=maxidx){
                    pq.pop();
                }
                maxidx=pq.top().second;
            }
             if(nums[j]>=nums[maxidx]){
                 maxidx=j;
             }
            ans.push_back(nums[maxidx]);
            
              i++;j++;
        }
        return ans;
    }


   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        deque<int>dq;
        int i=0;
        for( i=0;i<k;i++){
            
            while(!dq.empty() and nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(;i<n;i++){
            ans.push_back(nums[dq.front()]);
            while(!dq.empty() and dq.front()<=i-k)dq.pop_front();
            
              while(!dq.empty() and nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        return ans;
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