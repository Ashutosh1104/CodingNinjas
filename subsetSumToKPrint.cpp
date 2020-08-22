#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void subset(int input[], int isize, int output[],int osize, int sum){
    if(isize==0){
        if(sum==0){
            for(int i=0;i<osize;i++) cout<<output[i]<<" ";
            cout<<endl;
            return;
        }
        else return;
    }
    subset(input+1,isize-1,output,osize,sum);
    output[osize]=input[0];
    subset(input+1,isize-1,output,osize+1,sum-input[0]);
}
void printSubsetSumToK(int input[], int size, int k) {
    int output[1000];
    return subset(input,size,output,0,k);
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}