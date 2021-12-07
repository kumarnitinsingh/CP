// Created by Nitin kumar singh
// problem link ->https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

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

  long int *findTwoElement(int *arr, long int n) {
        // code here
        
         long int b=0;
         long int a=0;
        for(int i=0;i<n;i++){
            if(arr[abs(arr[i])-1]>0){
                arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
            }
            else b=abs(arr[i]);
        }
        
        for(int i=0;i<n;i++){
            if((arr[i])>0)a=i+1;
        }
        
        long int* p=new long int[2];
        p[0]=b;
        p[1]=a;
        return p;
    }


    //another approach
//     Let x be the missing and y be the repeating element.
// Let N is the size of array.
// Get the sum of all numbers using formula S = N(N+1)/2
// Get the sum of square of all numbers using formula Sum_Sq = N(N+1)(2N+1)/6
// Iterate through a loop from i=1….N
// S -= A[i]
// Sum_Sq -= (A[i]*A[i])
// It will give two equations 
    
// x-y = S   eqn(1) 
// x^2 – y^2 = Sum_sq 
// x+ y = (Sum_sq/S)  eqn(2) 

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