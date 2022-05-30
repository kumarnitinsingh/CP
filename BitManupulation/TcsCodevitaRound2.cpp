// Created by Nitin kumar singh
// problem link -> https://cses.fi/problemset/task/1073/

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



int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
        

        int n;
        cin>>n;
        vector<string>v(n);
        loop(i,n)cin>>v[i];
        string k;
       // cin>>k;
        vector<int>temp;
         getline(cin,k);

        while(true){
         (getline(cin,k));
          if(k.size()==0)break;
         stringstream ss(k);
        
        string token;
        while(getline(ss,token,',')){

             temp.push_back(stoi(token));
        }


}
    

        set<pair<int,int>>prior;
        int len=temp.size();
        if(n%2==0){
            int o=len;
            for(int i=0;i<len/2;i++){
                prior.insert({o,temp[i]});
                o--;
            }
            o=1;
            for(int i=len/2;i<len;i++){
                prior.insert({o,temp[i]});
                o++;
            }

        }
        else{
             int o=len;
            for(int i=0;i<len/2 ;i++){
                prior.insert({o,temp[i]});
                o--;
            }

             o=1;
            for(int i=len/2;i<len;i++){
                prior.insert({o,temp[i]});
                o++;
            }

        }

         temp.clear();

         vector<int>spaces(n);
         for(int i=0;i<n;i++){
            string s=v[i];

            int cn=0;
            for(long unsigned int i=0;i<s.size();i++){
                if(s[i]=='_')cn++;
            }
            spaces[i]=cn;
         }

       //  for(int i=0;i<n;i++)cout<<spaces[i]<<endl;

          // prior.clear();

            


           vector<vector<int>>fans(n);

         for(auto e:prior){

         //   cout<<e.first<<" "<<e.second<<endl;

            int group_size=e.second;
            int p=e.first;

            int row=-1;
            for(int i=0;i<n;i++){
                if(spaces[i]>=group_size){
                    row=i;
                    break;
                }
            }
                if(row==-1)continue;

                int u=0;

            for(long unsigned int i=0;i<v[row].size();i++){
                 if(v[row][i]=='_' and u<group_size){
                      fans[row].push_back(p);
                    u++;
                 }
                 
            }
             spaces[row]-=group_size;

         }

         prior.clear();       
            spaces.clear();

         for(int i=0;i<n;i++){
           unsigned ll j=0;
                for(unsigned ll k=0;k<v[i].size();k++){
                  if(v[i][k]=='_' and j<fans[i].size())cout<<(fans[i][j++]);
                  else cout<<(v[i][k]);

            }
            cout<<endl;
         }

      






   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}