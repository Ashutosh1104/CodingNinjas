#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int subsetSumToK(int input[], int n, int output[][50], int k) {
    if(n==0){
        if(k==0){
            output[0][0]=0;
            return 1;
        }
        else return 0;
    }
    int a[10000][50],b[10000][50];
    int s1=subsetSumToK(input+1,n-1,a,k-input[0]);
    //CHANGE A to add input[0] to result
    for(int i=0;i<s1;i++){
        a[i][0]=a[i][0]+1;
        for(int j=a[i][0];j>=2;j--){
            a[i][j]=a[i][j-1];
        }
        a[i][1]=input[0];
    }
    int s2=subsetSumToK(input+1,n-1,b,k);
    for(int i=0;i<s1+s2;i++){
        if(i<s1){
        	for(int j=0;j<=a[i][0];j++){
            	output[i][j]=a[i][j];
        	}
        }
        else{
        	for(int j=0;j<=b[i-s1][0];j++){
            	output[i][j]=b[i-s1][j];
        	}
        }
    }
    return s1+s2;
}
int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}