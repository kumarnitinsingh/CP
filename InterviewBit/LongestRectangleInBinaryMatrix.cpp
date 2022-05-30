// Created by Nitin kumar singh
// problem link ->  https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

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








vector<int> prevsmaller(vector<int>&v){
    stack<int>st;
    int n=v.size();
    vector<int>ans(n);

    for(int i=0;i<n;i++){
         
         while(!st.empty() and v[st.top()]>=v[i])st.pop();

         if(st.empty())ans[i]=(0);
         else ans[i]=(st.top()+1);

         st.push(i);
    }
    return ans;
}

vector<int>nextsmaller(vector<int>&v){
   

    stack<int>st;
    int n=v.size();
     vector<int>ans(n);

    for(int i=n-1;i>=0;i--){
         
         while(!st.empty() and v[st.top()]>=v[i])st.pop();

         if(st.empty())ans[i]=(n-1);
         else ans[i]=(st.top()-1);

         st.push(i);
    }
    return ans;
}


int solve(vector<int>& csum,int n){
    vector<int>left=prevsmaller(csum);
    vector<int>right=nextsmaller(csum);

    int ans=0;

    for(int i=0;i<n;i++){
        int temp=csum[i]*(right[i]-left[i]+1);
        ans=max(ans,temp);
    }

    return ans;
    
}


int largestArea(vector<int>&A){
    int ans=INT_MIN;
    vector<int>left=prevsmaller(A);
    vector<int>right=nextsmaller(A);
    int n=A.size();
    for(int i=0;i<n;i++){
        int t=((right[i]-left[i])+1)*A[i];
        ans=max(ans,t);
        
    }
    return ans;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int ans=0;
    int n=A.size();

     ans=max(ans,largestArea(A[0]));

     for(int i=1;i<n;i++){
         
          for(int j=0;j<A[0].size();j++){
              if(A[i][j]){
                  A[i][j]+=A[i-1][j];
              }
              
          }
          ans=max(ans,largestArea(A[i]));
     }
    return ans;
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