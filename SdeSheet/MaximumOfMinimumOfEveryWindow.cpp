// Created by Nitin kumar singh
// problem link -> https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1#

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

 vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        vector<int>v;
        for(int i=0;i<n;i++){
            int ans=INT_MIN;
            
            for(int j=0;j<n-i;j++){
                
                int left=j;
                int right=j+i;
                int k=INT_MAX;
                while(left<=right){
                    k=min(k,arr[left]);
                    left++;
                    
                  
                }
                 if(k!=INT_MAX)ans=max(k,ans);
                
            }
            v.push_back(ans);
        }
        return v;
    }



//optimized approach
vector<int>prevsmaller(int arr[],int n){
    vector<int>ans(n);
    stack<pair<int,int>>st;
    for(int i=0;i<n;i++){
        while(!st.empty() and st.top().first>=arr[i]){
            st.pop();
        }
        if(st.empty()){ans[i]=-1;}
        else ans[i]=st.top().second;
        st.push({arr[i],i});
    }
    return ans;
}

vector<int>nextsmaller(int arr[],int n){
    vector<int>ans(n);
    stack<pair<int,int>>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() and st.top().first>=arr[i]){
            st.pop();
        }
        if(st.empty()){ans[i]=n;}
        else ans[i]=st.top().second;
        st.push({arr[i],i});
    }
    return ans;
}

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
       vector<int>left=prevsmaller(arr,n);
       vector<int>right=nextsmaller(arr,n);
        vector<int>ans(n+1,0),v(n);
        for(int i=0;i<n;i++){
            int len=right[i]-left[i]-1;
            ans[len]=max(ans[len],arr[i]);
        }
        for(int i=n-1;i>=1;i--){
            ans[i]=max(ans[i],ans[i+1]);
        }
        
        for(int i=0;i<n;i++){
            v[i]=ans[i+1];
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