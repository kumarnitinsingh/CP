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

vector<char> FindFirstNonRepeatingCharacter(string s){
    vector<char>ans;
    unordered_map<char,int>hash;
    queue<char>q;
    
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(hash.count(ch)==0){hash[ch]++;q.push(ch);
            while(hash[q.front()]!=1){q.pop();}
            if(!q.empty()) ans.push_back(q.front());
            else ans.push_back(0);

           }
        else{
            hash[ch]++;
            if(hash[ch]!=1 and ch==q.front()) q.pop();
            if(!q.empty() and hash[q.front()]==1)ans.push_back(q.front());
            else ans.push_back('0');
            
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here
      string s;
      cin>>s;
      vector<char> ans=FindFirstNonRepeatingCharacter(s);
      loop(i,ans.size())cout<<ans[i];




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}

/*
First Non-Repeating Character
Given a stream of characters (lowercase alphabets), find the first non-repeating character from stream. You need to tell the first non-repeating character in O(1) time at each index. If for a current index there is no such character return '0' for that particular index.

Input Format:

A String S of length N passed as a parameter to the given function.

Output Format:

Return a vector of characters of length N where V[i] character represents first non-repeating character from S[0] to S[i].

Constraints:

1<=N<=100

Expected time complexity:

O(N) where N is the total number of input characters in one testcase. (Use the property of queue)



Sample Testcase :

Input:

aabcbcd

Output:

a 0 b b c 0 d

Explanation:

At index 0, 'a' is the only character we have and hence non repeating.

At index 1, we have 2 characters till now and they are same, hence no non-repeating character.

At index 2, 'b' is the only non repeating character till now.

At index 3, 'b' and 'c' are non repeating characters, but 'b' is the FIRST non repeating character till now.

At index 4, 'c' is the only non repeating character till now.

At index 5, there is no non repeating character till now.

At index 6, 'd' is the only and first non repeating character.

*a/