// Created by Nitin kumar singh
// problem link ->https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#

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

  int median(vector<vector<int>> &matrix, int r, int c){
        // code here      
        int mi=INT_MAX;
        int ma=INT_MIN;
        for(int i=0;i<r;i++){
            mi=min(matrix[i][0],mi);
            ma=max(matrix[i][c-1],ma);
        }
        
        int low=mi;int high=ma;
        int target=(r*c+1)/2;
        while(low<=high){
            int mid=low+(high-low)/2;
            int place=0;
            
            for(int i=0;i<r;i++){
                place+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            if(place<target)low=mid+1;
            else high=mid-1;
        }
        return low;
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