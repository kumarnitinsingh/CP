// Created by Nitin kumar singh
// problem link ->https://leetcode.com/problems/largest-rectangle-in-histogram/

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

  //O(N*N) Approach

  int largestRectangleArea(vector<int>& heights) {
     int ans=heights[0];
        int n=heights.size();
        for(int i=0;i<n;i++){
            int h=heights[i];
            int cn1=0;
            int cn2=0;
        
            for(int j=i;j>=0;j--){
                if(heights[j]<h)break;
                else cn1++;
                
            }
            for(int j=i+1;j<n;j++){
                if(heights[j]<h)break;
                else cn2++;
            }
            int t=h*(cn1+cn2);
           // cout<<t<<endl;
            
            ans=max(ans,t);
        }
        return ans;
    }




//optimized approach

vector<int> prevSmaller(vector<int> &A) {
    stack<int>st;
    int n=A.size();
    vector<int>ans(n);

    for(int i=0;i<n;i++){
        int next=A[i];
       
        while(!st.empty() and A[st.top()]>=next){
           
            st.pop();
        }
        if(st.empty()){ans[i]=0;st.push(i);continue;}
       else ans[i]=st.top()+1;
        st.push(i);
    }
     
return ans;
}

vector<int> rightSmaller(vector<int> &A) {
    stack<int>st;
    int n=A.size();
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        int no=A[i];
        while(!st.empty() and A[st.top()]>=no){
            st.pop();
        }
        if(st.empty()){ans[i]=n-1;}
        else ans[i]=st.top()-1;
        st.push(i);
    }
    return ans;
}

    int largestRectangleArea(vector<int>& heights) {
        vector<int>nsmall,psmall;
        nsmall=rightSmaller(heights);
        psmall=prevSmaller(heights);
       int ans=INT_MIN;
        int n=heights.size();
        for(int i=0;i<n;i++){
             int t=heights[i]*(nsmall[i]-psmall[i]+1);
            
            ans=max(ans,t);
        }
        return ans;
    }



//most Optimized solution with single pass
     int largestRectangleArea(vector<int>& heights) {
       
       int ans=INT_MIN;
        int n=heights.size();
        stack<int>st;
        for(int i=0;i<=n;i++){
          
            while(!st.empty() and (i==n or heights[st.top()]>=heights[i])){
                int el=heights[st.top()];
                st.pop();
                int width=0;
                if(st.empty())width=i;
                else width=i-st.top()-1;
                ans=max(ans,el*width);
            }
                  st.push(i);
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

