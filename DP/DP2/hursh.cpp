#include <iostream>
#include <map>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define mod 1000000007 
     
int main(){  
    FAST
    int n;
    cin >> n ;
    vector <int> v(n);
    for(int i = 0 ; i< n ;i++) cin >> v[i];

    sort(v.begin(),v.end());
    int maximum = v.back();
    int gap =  0;
    while(maximum > 0){
        gap++;
        maximum >>=1;
    } 
    vector< pair <int,int> > count01;
    for(int i = 0 ; i< n ;i++){
        int oneCount =__builtin_popcount(v[i]);
        count01.push_back({oneCount,gap-oneCount});
    }   
    int premans =  0;
    for(int i = 1 ; i < (int)pow(2,n) ;i++ ){
        int oneCount = 0, zeroCount = 0;
        for(int j = 0 ; j< n ;j++)
            if(i&(1<<j)){ 
                oneCount += count01[j].first;
                zeroCount += count01[j].second;
            }
        premans += oneCount == zeroCount;
    }
    int temp = premans;
    string output;
    while(temp){
        output.push_back('0'+temp%2);
        temp >>=1;
    }
    int count = output.size();
    while(count < gap)
        output += '0',count++;
    for( int i = output.size()-1 ; i >=0 ; i-- ){
        cout<<output[i];
    }
    return 0;
}   