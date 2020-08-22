#include<iostream>
#include<map>
using namespace std;
	
int highestFrequency(int *input, int n){
    map<int,int> m ;
    int highest , max = 0 ;
	for( int i = 0 ; i < n ; i++){
        m[ input[i] ]++;
        if( m[ input[i] ] > max ){
            max = m[ input[i] ];
            highest = input[i];
        }
    }
    return highest;
    
}


int main()
{
    int n;
    int input[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    int maxKey= highestFrequency(input, n);
    cout<<maxKey;
    return 0;
}


