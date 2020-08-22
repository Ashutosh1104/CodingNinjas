#include <iostream>
#include<map>
using namespace std;
typedef long long ll;

ll calFactor(ll val ){
    for(ll i=2 ; i*i <= val ; i++){ // only run till root is reached 
         if( val % i==0){ // if the mod is zero i.e factor found
            return val / i; 
        }
    }
    return 1;
}

int main()
{    
    ll temp,temp2;
    cin>>temp>>temp2;

    ll first = max(temp,temp2);
    ll second = min(temp,temp2);
    map<ll,ll> m;
    ll c=0 , d=0 ;
    if( first == second ) cout<<0;
    else
    {
        while(first != 1)
        {
          c++;
          first=calFactor(first);
          m[first]=c;
        }
        while(!m.count(second)) // till the val that is already presnt is not repeated 
        {
         second=calFactor(second);
         d++;
        }
        cout<<m[second]+d;
    }
    return 0;
}