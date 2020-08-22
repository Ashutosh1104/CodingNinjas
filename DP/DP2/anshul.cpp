#include<bits/stdc++.h>

typedef long long ll;

ll highest_factor(ll number)
{
    for(ll i=2;i*i<=number;i++){
         if(number%i==0){
            return number/i;
        }
    }
    return 1;
}

int main(){   
    ll l,k;
	ll i=0,j=0;
	std::map<ll,ll> mymap;
    std::cin>>l>>k;
    if(l<k){
        int t=l;
		l=k;
		k=t;
    }
    if(l==k) {std::cout<<0;
	return 0;
	};
        while(l!=1){
          l=highest_factor(l);
		  i++;
          mymap[l]=i;
        }
        while(!mymap.count(k)){
         k=highest_factor(k);
         j++;
        }
        std::cout<<mymap[k]+j;
    return 0;
}