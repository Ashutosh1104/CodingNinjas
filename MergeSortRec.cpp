#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void merge(int input[],int s, int m,int e){
    int i=s , j=m+1 , k=0;
    int temp[e-s];
    while(i<=m && j<=e){
    	if(input[i]<=input[j]) temp[k++]=input[i++];
   		else temp[k++]=input[j++];
    }
    while(i<=m) temp[k++]=input[i++];
    while(j<=e) temp[k++]=input[j++];
    for(int i=s;i<=e;i++){
        input[i]=temp[i-s];
    }
}
void msort(int input[],int s,int e){
    if(s<e){
    	int mid=(s+e)/2;
    	msort(input,s,mid);
    	msort(input,mid+1,e);
    	merge(input,s,mid,e);
    }
}

void mergeSort(int input[], int size){
	msort(input,0,size-1);        
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}