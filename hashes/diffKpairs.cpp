#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int diff ( int a , int k ){
    return abs(k-a);
}
void printPairs(int *input, int n, int k) {
    map<int,int> m;
    for( int i = 0 ; i < n ; i++ ){
        int ahead = input[i] + k , behind = input[i] - k;
        if( m[ ahead ] ){
            int smaller = min( ahead , input[i] );
            int greater = max( ahead , input[i] );
            int a = m[ahead];
            while( a-- ) cout<< smaller <<" " << greater << endl;
        }
        if( m[ behind ]  && k != 0 ){
            int smaller = min( behind , input[i] );
            int greater = max( behind , input[i] );
            int a = m[behind];
            while( a-- ) cout<< smaller <<" " << greater << endl;
        }
        m[ input[i] ]++;
    }
}
int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	printPairs(input, n, k);
}
