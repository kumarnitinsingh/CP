// Created by Nitin kumar singh
// problem link -> https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

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

 int findPlatform(int arr[], int dep[], int n)
    {
    	
    	
    	int t[2400]={0},i,j;
       for(i=0;i<n;i++)
       for(j=arr[i];j<=dep[i];j++)
    	t[j]++;
        return *max_element(t,t+2400);
    }

		
    
  int findPlatform(int arr[], int dep[], int n)
    {
    	
        

		sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int i=0, j=1;
    	int platform = 1;
    	
    	while(i<n && j<n){
    	    if( arr[j] > dep[i])
    	        i++;
    	    else
    	        platform++;
    	       
    	    j++;
    	}
    	return platform;
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