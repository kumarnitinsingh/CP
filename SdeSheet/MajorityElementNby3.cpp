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


//Moore voting algorithm space O(1) and time O(N)
 vector<int> majorityElement(vector<int>& nums) {
       int num1=0,num2=0,count1=0,count2=0;
        int n=nums.size();
        vector<int>ans;
        for(int num:nums){
            if(num==num1){count1++;}
            else if(num==num2){count2++;}
            else if(count1==0){num1=num;count1++;}
            else if(count2==0){num2=num;count2++;}
            else {count1--;count2--;}
        }
        
        count1=0,count2=0;
        for(int i=0;i<nums.size();i++){
            if(num1==nums[i])count1++;
            else if(num2==nums[i])count2++;
                
        }
        
        if(count1>n/3)ans.push_back(num1);
        if(count2>n/3)ans.push_back(num2);
        return ans;
    }



// space O(N) and Time O(n);
     vector<int> majorityElement(vector<int>& nums) {
         unordered_map<int,int>mp;
        vector<int>v;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
         for(auto p:mp){
             if(p.second>n/3){v.push_back(p.first);}
         }
        return v;
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