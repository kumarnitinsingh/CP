// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/4sum/

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

//T O(N^3)
 vector<vector< int>> fourSum1(vector<int>& nums, int target) {
        
        vector<vector< int>>ans,temp;
          set<vector< int>>s;
        int n=nums.size();
       sort(nums.begin(),nums.end());
        
        
        for(int i=0;i<n-1;i++){
           
            
            for(int j=i+1;j<n-1;j++){
            
            int left=j+1;
            int right=n-1;
          
            while(left <n-1 and right>=0 and left<right){
                if(nums[left]+nums[right]==target-nums[i]-nums[j]){
                    s.insert({nums[i],nums[j],nums[left],nums[right]});
                    left++;
                    right--;
                }
                else if(nums[left]+nums[right] > target-nums[i]-nums[j])right--;
                else left++;
            }
        }
        }
       for(auto p:s){
           ans.push_back(p);
       }
     return ans;
    }


    //T O(N^3logN) ans space(N)
vector<vector< int>> fourSum2(vector<int>& nums, int target) {
        
        vector<vector< int>>ans;
          set<vector< int>>s;
        int n=nums.size();
       sort(nums.begin(),nums.end());
        vector<long long int>num(n);
        for(int i=0;i<n;i++)num[i]=nums[i];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                unordered_map< int, int>mp;
                for(int k=j+1;k<n;k++){
                      long int o=nums[i]*1LL+nums[j]*1LL+nums[k]*1LL;
                    int p=target-o;
                    if(binary_search(num.begin()+k+1,num.end(),target-o)){
                        s.insert({nums[i],nums[j],nums[k],p});
                    }
                                                            
                }
            }
        }
     
      
    
        
        for(auto p:s){
            ans.push_back(p);
        }
      return ans;
  }



// T O(N^3) NO extra Space

     vector<vector< int>> fourSum3(vector<int>& nums, int target) {
        
        vector<vector< int>>ans,temp;
          set<vector< int>>s;
        int n=nums.size();
       sort(nums.begin(),nums.end());
        if(n<=3)return {};
        
        for(int i=0;i<n;i++){
            
            
            for(int j=i+1;j<n;j++){
             
            int left=j+1;
            int right=n-1;
            int twosum=target - nums[i]-nums[j];
            while( left<right){
                if((nums[left]+nums[right]) > twosum)right--;
                else if((nums[left]+nums[right]) < twosum)left++;
                else{
                    
                        vector<int >temp;
                    temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                         temp.push_back(nums[left]);
                         temp.push_back(nums[right]);
                    ans.push_back(temp);
                   
                    while(left<right and nums[left]==temp[2]) left++;
                    while(left<right  and nums[right]==temp[3])right--;
                    
                }
                 
              
            }
                while(j<n-1 and nums[j]==nums[j+1])j++;
        }
            while(i<n-1 and nums[i]==nums[i+1])i++;
        }
     
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