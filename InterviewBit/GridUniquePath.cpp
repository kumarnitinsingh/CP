// Created by Nitin kumar singh
// problem link -> https://www.interviewbit.com/problems/unique-paths-in-a-grid/

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



int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {

    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j]==0)A[i][j]=1;
            else A[i][j]=0;
        }
    }
    int i=0;
    for( ;i<A[0].size();i++){
        if(A[0][i]==1)continue;
        else break;
    }
    for(;i<A[0].size();i++)A[0][i]=0;
    i=0;
    for(;i<A.size();i++){
        if(A[i][0]==1)continue;
        else break;
    }

    for(;i<A.size();i++)A[i][0]=0;

    for(int i=1;i<A.size();i++){
        for(int j=1;j<A[0].size();j++){
                if(A[i][j]==0)continue;
                A[i][j]=0;
            if(A[i-1][j]!=0)A[i][j]+=A[i-1][j];
            if(A[i][j-1]!=0)A[i][j]+=A[i][j-1];
        }
    }

    return A[A.size()-1][A[0].size()-1];
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
}i