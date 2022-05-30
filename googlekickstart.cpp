// Created by Nitin kumar singh
// problem link -> https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b0c6#problem

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
#define mod            1000000007ll
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
    freopen("output3.txt","w",stdout);
    #endif
}


//     ll x;
//     ll y;
//     ll gc;

// void ExtendedEuclideanAlgorithm(ll a,ll b){

// if(b==0){
//     x=1;
//     y=0;
//     gc=a;return;
// }
//  ExtendedEuclideanAlgorithm( b,a%b);
// ll cx=y;
// ll cy=x-(a/b)*y;
// x=cx;
// y=cy;

// }

// ll InverseModulo(ll a,ll m){
//     x=0,y=0,gc=0;
// ExtendedEuclideanAlgorithm(a,m);
// return x;
// }

vector<ll>factorial;


ll gcdExtended(ll a, ll b, ll* x, ll* y)
{
     
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
     
    // To store results of recursive call
    ll x1, y1;
    ll gc = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gc;
}

ll modInverse(int a, int m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    
   
         
        // m is added to handle negative x
        ll res = (x % m + m) % m;
     
     return res;
}

bool ispalindrome(string s){
    int i=0,j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}

map<pair<string,int>,ll>mp;

ll  solve(string s,int i){
    
    if(i==1)return 1;
    if(mp.find({s,i})!=mp.end())return mp[{s,i}];
     ll ways=0;
    for(int k=0;k<i;k++){
        string temp1=s.substr(0,k);
        string temp2=s.substr(k+1,i-k-1);


         string str=temp1+temp2;
         if(ispalindrome(str))ways+=factorial[i-1];
       //  cout<<str<<endl;
         ways+=solve(str,i-1);
         

    }
    return mp[{s,i}]=ways;
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     

     ll i=1;
     factorial.push_back(i);
     factorial.push_back(i);
     for(int i=2;i<=401;i++){
        ll temp=(factorial.back()%mod*i%mod)%mod;
        factorial.push_back(temp);
     }
       
       int T;
       cin>>T;
       int w=1;
       while(T--){
          cout<<"case #"<<w<<": "; 
            w++;
            //cn=0;
            mp.clear();

            ll n;
            cin>>n;
            string s;
            cin>>s;

            
            ll p=solve(s,n);
            ll q=factorial[n];
            ll a=__gcd(p,q);
            p=p/a;
            q=q/a;

          //expr=(e*q-p)%mod==0;
            // cout<<p<<endl;
            // cout<<q<<endl;

          ll d=modInverse(q,mod);

           ll ans=(p%mod * d%mod)%mod;
           cout<<ans<<endl;





        
        

}

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}