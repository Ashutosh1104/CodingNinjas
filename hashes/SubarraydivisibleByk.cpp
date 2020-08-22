#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for( int i = 0 ; i < n ; i++) cin>>a[i];
        unordered_map<int,int> m;
    	int sum = 0;
    	int maxlen = 0;
    	m[0]=1;
    	for( int i = 0 ; i < n ; i++){
        	sum = sum + a[i];
        	int temp = ((sum%k)+k)%k;
            if( temp == 0 ) maxlen = i+1;  // only issue was this line was lst and elseif 
        	else if( m.count(temp) ){
            	maxlen = max( maxlen , i-m[temp] );
        	}
        	else m[ temp ] = i;
    	}
    	cout<<maxlen<<endl;
    }
}