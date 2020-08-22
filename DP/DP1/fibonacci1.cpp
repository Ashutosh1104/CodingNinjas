#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int fib(int n){
    vector<int> v(n,0);
    v[0]=1;
    v[1]=1;
    for( int i = 2 ; i < n ; i++ ){
        v[i] = v[i-1]+v[i-2];
    }    
    return v[n-1];
}
// dp like recursion
int fib2Helper(int* ans , int n){
    if( n <= 1 ) return n;
    // check if ans to call already exixts 
    if( ans[n] ){
        return ans[n];
    }
    // if ans doesnt exists do cal 
    int a = fib2Helper(ans , n-1);
    int b = fib2Helper(ans , n-2);
    //save the calculated val for future use    
    ans[n]= a+b;
    //return it 
    return ans[n];
}
int fib2(int n){
	int *ans = new int[n];
    for( int i =0 ; i < n ; i++ ){
        ans[i]=0;
    }
    int a = fib2Helper(ans , n-1);
    int b = fib2Helper(ans , n-2);
    return a+b;
}
int main()
{
	int n;
    cin>>n;
    cout<<fib2(n);
}