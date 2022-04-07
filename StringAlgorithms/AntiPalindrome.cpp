// Created by Nitin kumar singh
// problem link -> https://www.codechef.com/START24C/problems/ANTI_PAL

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

bool antiPalindrom(string s){
    int i=0;int j=s.size()-1;
    while(i<j){
        if(s[i]==s[j])return false;
        i++;j--;
    }
     return true;
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
        ll t;
        cin>>t;
        while(t--){
            ll n;
            cin>>n;
            string s;cin>>s;
            if(n%2==1){
                cout<<"NO"<<endl;continue;
            }
          
             map<char,ll>mp;
             for(int i=0;i<n;i++){
                mp[s[i]]++;
               
             }

             

             priority_queue<pair<int,char>>pq;
             for(auto p:mp){
                pq.push({p.second,p.first});
             }

             string str="";
             int f=0;
             while(!pq.empty() ){
                pair<int,char>p1=pq.top();pq.pop();
                 if(p1.first>n/2){
                    cout<<"NO"<<endl;
                    f=1;
                    break;
                 }
                 else {
                    while(p1.first--){
                        str+=p1.second;
                    }
                 }
             }

            if(f==1)continue;

             int i=0;int j=n/2-1;
             int l=1;
             while(i<j){
                swap(str[i],str[j]);
                i++;j--;
             }
             cout<<"YES"<<endl;
             cout<<str<<endl;

        }




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}