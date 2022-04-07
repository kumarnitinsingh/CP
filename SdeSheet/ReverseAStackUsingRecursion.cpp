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

void insert_at_bottom(char x)
{
 
    if(st.size() == 0)
    st.push(x);
 
    else
    {
         
        // All items are held in Function Call
        // Stack until we reach end of the stack
        // When the stack becomes empty, the
        // st.size() becomes 0, the above if
        // part is executed and the item is
        // inserted at the bottom
             
        char a = st.top();
        st.pop();
        insert_at_bottom(x);
 
        // push allthe items held in
        // Function Call Stack
        // once the item is inserted
        // at the bottom
        st.push(a);
    }
}
 
// Below is the function that
// reverses the given stack using
// insert_at_bottom()
void reverse()
{
    if(st.size()>0)
    {
         
        // Hold all items in Function
        // Call Stack until we
        // reach end of the stack
        char x = st.top();
        st.pop();
        reverse();
         
        // Insert all the items held
        // in Function Call Stack
        // one by one from the bottom
        // to top. Every item is
        // inserted at the bottom
        insert_at_bottom(x);
    }
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