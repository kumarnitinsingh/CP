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


bool flag=false;
void print(char a[][10])
{
//cout<<endl;
for(int i=0; i<10; i++)
{
for(int j=0; j<10; j++)
cout<<a[i][j];
cout<<endl;
}
}

bool noempty(char a[][10])
{
for(int i=0; i<10; i++)
for(int j=0; j<10; j++)
if(a[i][j]=='-')
return false;

return true;
}

void fill(char a[][10], string w[], int n, int used, int taken[10])
{
if(flag == true)
return;
if(used==n && noempty(a))
{
flag = true;
print(a);
}
for(int i=0; i<10; i++)
for(int j=0; j<10; j++)
{
if(a[i][j] == '-')
{
int h_depth=1;
int v_depth=1;
while(j+h_depth<10 && a[i][j+h_depth]!='+')
h_depth++;
while(i+v_depth<10 && a[i+v_depth][j]!='+')
v_depth++;
if(h_depth>1 && (j==0||(j>0 && a[i][j-1] == '+')))

{
for(int k=0; k<n; k++)
if(w[k].length()==h_depth && !taken[k])

{

taken[k] = 1;
for(int h=0; h<h_depth; h++)
{
if(a[i][j+h]>='A' && a[i][j+h

]<='Z' && a[i][j+h]!=w[k][h])
{
taken[k]=0;
while(h>=0)
a[i][j+h--] = '-';
break;
}
a[i][j+h] = w[k][h];
}
//cout<<"\nUsed h1"<<w[k]<<i<<j;
//print(a);
fill(a, w, n, used+1, taken);
for(int h=0; h<h_depth; h++)
a[i][j+h] = '-';
taken[k] = 0;
}

}
else if(v_depth>1 && (i==0 || (i>0 && a[i-1][

j] == '+')))

{
for(int k=0; k<n; k++)
if(w[k].length()==v_depth && !taken[k

])

{

taken[k] = 1;
for(int v=0; v<v_depth; v++)
{
if(a[i+v][j]>='A' && a[i+v][j

]<='Z' && a[i+v][j]!=w[k][v])
{
taken[k]=0;
while(v>=0)
a[i+v--][j] = '-';
break;
}
a[i+v][j] = w[k][v];
}
//cout<<"\nUsed v1"<<w[k]<<i<<j;;
//print(a);
fill(a, w, n, used+1, taken);
for(int v=0; v<v_depth; v++)
a[i+v][j] = '-';
taken[k] = 0;
}

}
else if(v_depth>1 && (i==0||(i>0 && a[i-1][j]

!= '+')))

{
for(int k=0; k<n; k++)
if(w[k].length()==v_depth+1 && (w[k][

0] == a[i-1][j]) && !taken[k])
{

taken[k] = 1;
for(int v=0; v<v_depth; v++)
{
if(a[i+v][j]>='A' && a[i+v][j

]<='Z' && a[i+v][j]!=w[k][v+1])
{
taken[k]=0;
while(v>0)
a[i+v--][j] = '-';
break;
}
a[i+v][j] = w[k][v+1];
}
//cout<<"\nUsed v2"<<w[k]<<i<<j;
//print(a);
fill(a, w, n, used+1, taken);
for(int v=0; v<v_depth; v++)
a[i+v][j] = '-';
taken[k] = 0;
}

}

else if(h_depth>1 && (j==0 || (j>0 && a[i][j-
1] != '+')))

{
for(int k=0; k<n; k++)
if(w[k].length()==h_depth+1 && (w[k][

0] == a[i][j-1]) && !taken[k])

{
taken[k] = 1;
for(int h=0; h<h_depth; h++)
{
if(a[i][j+h]>='A' && a[i][j+h

]<='Z' && a[i][j+h]!=w[k][h+1])
{
taken[k]=0;
while(h>0)
a[i][j+h--] = '-';

break;
}
a[i][j+h] = w[k][h+1];
}
//cout<<"\nUsed h2"<<w[k]<<i<<j;
//print(a);
fill(a, w, n, used+1, taken);
for(int h=0; h<h_depth; h++)
a[i][j+h] = '-';
taken[k] = 0;
}

}
}
}

}




int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here
      char mat[10][10];
for(int i=0; i<10; i++)
for(int j=0; j<10; j++)
cin>>mat[i][j];

string s;
cin>>s;
string word[10];
int taken[10] = {0,};
int counter = 0;
int p=0;
flag = false;
for(int i=0; i<(s.length()); i++)
if(s[i]==';')
{
counter++;
p=0;
}
else
word[counter] += s[i];

fill(mat, word, counter+1, 0, taken);
return 0;




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}