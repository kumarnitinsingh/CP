// Created by Nitin kumar singh
// problem link ->https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

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

 
    bool valid(vector<int>& boom,int m,int k,int days){
        int cn=0;
        
        for(int i=0;i<boom.size();){
             
              int j=i;
              int pos=0;
               int f=0;
               for( ;j<boom.size() and j<i+k;j++ ){
                   if(boom[j]<=days)pos++;
                   else{ f=1; break;}
               }
                
                 if(f==1)i=j+1;
                  else if(i==j)i=j+1;
                   else i=j;
                    
            
                if(pos==k)cn++;
                
            if(cn>=m)return true;
             
        }
        if(cn>=m)return true;
        return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s=0;
       
         int e=*max_element(bloomDay.begin(),bloomDay.end())+10;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(valid(bloomDay,m,k,mid)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }



int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
      
      int n,m,k;
      cin>>n>>m>>k;
      vector<int>v(n);
      loop(i,n)cin>>v[i];

      cout<<minDays(v,m,k)<<endl;








   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}


