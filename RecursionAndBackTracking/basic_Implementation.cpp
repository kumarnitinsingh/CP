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
int ans2=0;

void merge(vector<int>&v,int l,int mid,int h){
      vector<int>ans(h-l+1);
      int i=l;
      int j=mid+1;
      int k=0;
     for( ;i<mid+1 and j<=h;){
          if(v[i]<=v[j]){ans[k++]=v[i++];}
          else {ans[k++]=v[j++];ans2+=mid-i+1;}
     }
     for(;i<mid+1;)ans[k++]=v[i++];
     for(;j<=h;)ans[k++]=v[j++];
           k=0;
      for(int o=l;o<=h;o++)v[o]=ans[k++];     
}

void MergeSort(vector<int>&v,int l,int h){
     if(l<h){
          int mid=(l+h)/2;
          MergeSort(v,l,mid);
          MergeSort(v,mid+1,h);
          merge(v,l,mid,h);
     }
   
}
int quickSelect(vector<int>&v,int s,int e){
     int x=v[e];
      int i=s-1;
      for(int j=s;j<e;j++){
          if(v[j]<x){
               i++;
               swap(v[i],v[j]);
          }
      }
      swap(v[i+1],v[e]);
    
        return i+1;
}
void QuickSort(vector<int>&v,int s,int e){
     //if(s>=e)return;
          if(s<e){
     int pivot=quickSelect(v,s,e);
     QuickSort(v,s,pivot-1);
     QuickSort(v,pivot+1,e);
}
}

string stringToInteger(string s,int i,string ans,int n){
     if(i==n)return ans;
      
      if(s[i]=='p' and s[i+1]=='i'){
        ans+="3.14"+stringToInteger(s,i+2,ans,n);


      }
      else{ans+=s[i]+stringToInteger(s,i+1,ans,n);}

     return ans;
}

     

     
 void towerOfHanoi(int n,char beg,char aux,char end){
      if(n==0)return;
       towerOfHanoi(n-1,beg,end,aux);
       cout<<beg<<"to"<<end<<endl;
       towerOfHanoi(n-1,aux,beg,end);
 }
 void Permutaion(string s,int n,int i){
     if(i==n){
          cout<<s<<endl;
          return;}

      for(int j=i;j<n;j++){
               swap(s[i],s[j]);
               Permutaion(s,n,i+1);
               swap(s[i],s[j]);
      }
 }
 void BalancedBraketing(int n,int open,int close,string osf,int i){
         if(i==2*n){
          cout<<osf<<endl;
            return;
         }
         if(open<n){
           BalancedBraketing(n,open+1,close,osf+"(",i+1);
         }
         if(close<open){
           BalancedBraketing(n,open,close+1,osf+")",i+1);
         }
 }
 int knapsack(int price[],int wt[],int n,int w){
     if(n==0 || w<=0)return 0;
     int x=INT_MIN,y=INT_MIN;
     if(wt[n-1]<=w){
        x=price[n-1]+ knapsack(price,wt,n,w-wt[n-1]);
     }
      y= knapsack(price,wt,n-1,w);
      return max(x,y);
   }

   void pattern(char inp[],char out[],int i,int j,int n){
     if(inp[i]=='\0'){
          out[j]='\0';
          cout<<out<<endl;
          return;
     }
     if(inp[i]=='0'){
         return  pattern(inp,out,i+1,j,n);
     }
      out[j]=char(inp[i]+64-48);
      pattern(inp,out,i+1,j+1,n);

       int x=0;

        if(i+1<n){
          x+=(int(inp[i]-'0'))*10;
          x+=int(inp[i+1]-'0');
        }
        if(x>0 and x<=26){
          out[j]=char(64+x);
          pattern(inp,out,i+2,j+1,n);
        }

   }

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
    // write your code here
     //write your code here
     char inp[]={'1','2','0','0','\0'};
     char out[50];
      
     pattern(inp,out,0,0,4);

    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
     
     
   return 0;
};