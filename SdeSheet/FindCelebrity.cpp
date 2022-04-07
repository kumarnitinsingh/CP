// Created by Nitin kumar singh
// problem link -> https://www.lintcode.com/problem/645

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

// You are given a helper function bool knows(a, b) which tells you whether A knows B.
bool knows(int a, int b);

 int findCelebrity(int n) {
        if(n==1)return 0;
        // Write your code here
        int ans=-1;
        for(int i=0;i<n;i++){
            int f=0;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(!knows(j,i)){f=1;break;}
            }
            if(f==0){
                 ans=i;
                for(int x=0;x<n;x++){
                    if(i==x)continue;
                    if(knows(i,x)){
                        ans=-1;break;
                    }
                }
               break;}
        }
return ans;
    }


     int findCelebrity(int n) {
        int left = 0;
        int right = n - 1;
        while (left < right) {
            if(knows(left, right)) {
                left ++;
            } else {
                right --;
            }
        }
        for (int i = 0; i < n; i ++) {
            if (i==left || (knows(i, left) && !knows(left, i))) {
                continue;
            } else {
                return -1;
            }
        }
        return left;
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