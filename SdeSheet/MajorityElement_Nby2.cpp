// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/majority-element/

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
// Intuition Behind Working :
// When the elements are the same as the candidate element, votes are incremented when some other element is found not equal to the candidate element. We decreased the count. This actually means that we are decreasing the priority of winning ability of the selected candidate, since we know that if the candidate is a majority it occurs more than N/2 times and the remaining elements are less than N/2. We keep decreasing the votes since we found some different element than the candidate element. When votes become 0, this actually means that there are the same number of different elements, which should not be the case for the element to be the majority element. So the candidate element cannot be the majority, so we choose the present element as the candidate and continue the same till all the elements get finished. The final candidate would be our majority element. We check using the 2nd traversal to see whether its count is greater than N/2. If it is true, we consider it as the majority element.

// Steps to implement the algorithm :
// Step 1 – Find a candidate with the majority –

// Initialize a variable say i ,votes = 0, candidate =-1 
// Traverse through the array using for loop
// If votes = 0, choose the candidate = arr[i] , make votes=1.
// else if the current element is the same as the candidate increment votes
// else decrement votes.
// Step 2 – Check if the candidate has more than N/2 votes –

// Initialize a variable count =0 and increment count if it is the same as the candidate.
// If the count is >N/2, return the candidate.
// else return -1.

//moore voting algorithm space O(1) and time O(N)
   int majorityElement(vector<int>& nums) {
      int i=0;int candidate=-1;int vote=0;
    int n=nums.size();
        for(int i=0;i<n;i++){
        if(vote==0){
            candidate=nums[i];
            vote++;
        }
        else if(nums[i]==candidate)vote++;
            else vote--;
    }
      return candidate;
    }


    // space O(n) and timr O(n);
    int majorityElement2(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans;
         for(auto p:mp){
             if(p.second>n/2){ans=p.first;break;}
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