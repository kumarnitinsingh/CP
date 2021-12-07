// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/merge-intervals/

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

bool mycom(vector<int>v1,vector<int>v2){
        if(v1[0]==v2[0])return v1[1]<v2[1];
        return v1[0]<v2[0];
    }

   

   //no extra space required
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),mycom);
        int index=0;
        for(int i=0;i<intervals.size();i++){
             if(intervals[index][1]>=intervals[i][0]){
                 //merge
                 intervals[index][1]=max(intervals[index][1],intervals[i][1]);
                 intervals[index][0]=min(intervals[index][0],intervals[i][0]);
             }
            else {
                index++;
                intervals[index][0]=intervals[i][0];
                intervals[index][1]=intervals[i][1];
            }
        }
        vector<vector<int>>v(index+1);
        for(int i=0;i<=index;i++)v[i]=intervals[i];
        return v;
    }


//extra space is required;

 vector<vector<int>> merge(vector<vector<int>>& intervals) {
         
        if(intervals.size()<=1) return intervals;
        vector<vector<int>> v;
        
        sort(intervals.begin(),intervals.end());
      
        v.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(v.back()[1]>=intervals[i][0]){
                v.back()[1]=max(v.back()[1],intervals[i][1]);
                
                
            }
            
            else{
                v.push_back(intervals[i]);
                
            }
            
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