#include<iostream>
using namespace std;
#include<map>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){  
    map< int , int > m;
	for(int i = 0; i < n; i++){
        if( !m[ arr[i] ]){
            m[ arr[i] ] = i+1 ;
        }
    }
    map < int , int > all;
    bool flag =true;
    int temp;
    for( auto x : m ){
        if( x.first && m.count(x.first+1)>0 ){
            if( flag ) {
                temp = x.first;
                all[x.first]++;
                flag = !flag;
            }
            all[temp]++;
        }
        else{
            flag = true;
        }
    }
    int len = INT_MIN , start = INT_MAX;
    m[start]=INT_MAX;
    for( auto x : all ){
        if( m[x.first] < m[start] && x.second == len ){
            start = x.first ;
            len = x.second ;
        }
        if( x.second > len ){
            start = x.first ;
            len = x.second ;
        }
    }
    if( len == INT_MIN ) return {arr[0]};
    vector<int> v;
    for(int i = 0; i < len; i++){
        v.push_back(start+i);
    }
    return v;
}

int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);
  
  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
	cout << *it <<endl;
  }

  delete arr;
}