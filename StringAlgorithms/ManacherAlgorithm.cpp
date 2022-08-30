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

void printSubstring(string str, int left, int right){
    for (int i = left; i <= right; i++)
        cout << str[i];
}

// Implementation of Manacher's Algorithm
void longestPalSubstring(string s){
    /*
        If length of given string is n then its length after
        inserting n+1 "#", one "@", and one "$" will be
        (n) + (n+1) + (1) + (1) = 2n+3
    */
    int strLen = 2 * s.length() + 3;
    char* sChars = new char[strLen];

    /*
        Inserting special characters to ignore special cases
        at the beginning and end of the array
        "abc" -> @ # a # b # c # $
        "" -> @#$
        "a" -> @ # a # $
    */
    sChars[0] = '@';
    sChars[strLen - 1] = '$';
    int t = 1;

    for (char c : s){
        sChars[t++] = '#';
        sChars[t++] = c;
    }
    sChars[t] = '#';

    int maxLen = 0;
    int start = 0;
    int maxRight = 0;
    int center = 0;
    int* p = new int[strLen]; // i's radius, which doesn't include i

    for(int i = 1; i < strLen - 1; i++){
        if (i < maxRight){
            p[i] = min(maxRight - i, p[2 * center - i]);
        }

        // Expanding along the center
        while (sChars[i + p[i] + 1] == sChars[i - p[i] - 1]){
            p[i]++;
        }

        // Updating center and its bound
        if (i + p[i] > maxRight){
            center = i;
            maxRight = i + p[i];
        }

        // Updating ans
        if (p[i] > maxLen){
            start = (i - p[i] - 1) / 2;
            maxLen = p[i];
        }
    }

    // Printing the longest palindromic substring
    cout << "The Longest Palindromic Substring is: ";
    printSubstring(s, start, start + maxLen - 1);
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