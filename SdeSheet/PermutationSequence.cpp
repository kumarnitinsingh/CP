// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/permutation-sequence/

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

string getPermutation(int n, int k) {
         vector<int>v(n);
        for(int i=0;i<n;i++)v[i]=i+1; 
        while(--k and next_permutation(v.begin(),v.end()) );
          string s="";
        for(int i=0;i<n;i++)s+=char('0'+v[i]);
        return s;
    }

    string getPermutation2(int n, int k) {
       vector<int>factorial;
        k--;
        string s="1";
        factorial.push_back(1);
        for(int i=1;i<n;i++){
            int temp=factorial.back()*i;
            factorial.push_back(temp);
            s.append(to_string(i+1));
        }
        
        for(int i=1;i<=n;i++){
            int loc=k/factorial[n-i];
             k=k%factorial[n-i];
             s.push_back(s[loc]);
            s.erase(loc,1);
        }
        return s;
    }

string getPermutation3(int n, int k) {
       int factorial=1;
        k--;
        vector<int>number;
        
        for(int i=1;i<n;i++){
             factorial=factorial*i;
             number.push_back(i);
        }
        number.push_back(n);
        string s="";
        while(true){
            
            int loc=k/factorial;
           
             s=s+(to_string(number[k/factorial]));
             number.erase(number.begin()+  k/factorial); 
             
            if(number.size()==0){break;}
             k=k%factorial;
            factorial=factorial/number.size();
        }
        return s;
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