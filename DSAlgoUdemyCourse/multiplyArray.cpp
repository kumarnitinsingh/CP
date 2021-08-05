// Created by Nitin kumar singh
#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/trie_policy.hpp>


//using namespace_-gnu_pbds;
using namespace std;

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

vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,0);
    
    //update the output array and return
    //complete the code
    int zero=0;
    int x=1;;
    for(int i=0;i<n;i++){
        if(arr[i]==0)zero++;
        if(zero>=2)return output;
        if(arr[i]!=0){
            x=x*arr[i];
        }
    }
    if(zero==1){
        for(int i=0;i<n;i++){
            if(arr[i]!=0)output[i]=0;
            else output[i]=x;
        }
    }
    else{
        for(int i=0;i<n;i++){
            output[i]=x/arr[i];
        }
    }
    
    return output;
}
int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here

    int n;
    cin>>n;
    vector<int>a(n);
   
    for(int i=0;i<n;i++)cin>>a[i];
   
    vector<int>arr=productArray(a);

     for(int i=0;i<n;i++){
     	cout<<arr[i]<<" ";
     }




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}