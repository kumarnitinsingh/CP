// Created by Nitin kumar singh
// problem link ->

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


vector<vector<ll>>multiply(vector<vector<ll>>&mat1,vector<vector<ll>>& mat2,ll sz){
    vector<vector<ll>>mat3(sz,vector<ll>(sz,0));

    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
           
            for(int k=0;k<sz;k++){
                mat3[i][j]= (mat3[i][j]+(mat1[i][k]*mat2[k][j])%mod)%mod;
            }
        }
    }
    return mat3;
}

vector<vector<ll>> matrixExpoentiation(vector<vector<ll>>&mat,ll n,ll sz){
    if(n==0 or n==1)return mat;

    if(n%2==0){

        vector<vector<ll>> temp=matrixExpoentiation(mat,n/2,sz);
        return multiply(temp,temp,sz);
    }
    else {
         vector<vector<ll>> temp=matrixExpoentiation(mat,n-1,sz);
        return multiply(mat,temp,sz);
}
}



int main(int argc, char const *argv[])
{
     //clock_t start=clock();
     init_code();






   /*
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
    */
   return 0;
}