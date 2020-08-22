#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    ll int n,m,k,*a,*b;
    cin>>n>>m>>k;
    a=new ll int[n];
    b==new ll int[m];
    
    for(ll int i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
     
    ll int aptr=0,bptr=0,count=0;
     while(bptr < m && aptr < n){
        while( b[bptr] < a[aptr]-5 ) bptr++;
        while( a[aptr]+5 < b[bptr] ) aptr++; 
        if( b[bptr] >= a[aptr]-5 && b[bptr] < a[aptr]+5 ){
            cout<<b[bptr]<<" "<<a[aptr]<<endl;
            count++;
        }  
        aptr++;
        bptr++;
    }
    cin.tie(NULL);
}