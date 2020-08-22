#include <iostream>
#include <vector>

using namespace std;

#define ll long long int
#define vi vector<int>

void logic(int i, vi &v1, int best, int s, int &total)
{
	if (i == best)
	{
		if (s == 0)
			total++;
		return;
	}

	logic(i + 1, v1, best, s + v1[i], total);
	logic(i + 1, v1, best, s, total);
}


int main()
{
	int n;
	cin >> n;
	vi v(n);
	for(auto &i:v) cin>>i;
	int q = 0;
	for(int i=0;i<n;i++){
		if (v[i] > q) q = v[i];
	}
	int count = 0;
	while (q)
	{
		count++;
		q = q >> 1;
	}
	vi v1(n, 0);
	for(int i=0;i<n;i++){
		while (v[i])
		{
			if (v[i] & 1) v1[i]++;
			v[i] = v[i] >> 1;
		}
	}
	int j = 0;
    for(int i=0;i<n;i++){
		v1[j] = count - 2 * v1[i];
		if (v1[j] == 0)	continue;
		else j++;
	}
	int finalOut = 0;
	logic(0, v1, j, 0, finalOut);
	finalOut -= 1;
	finalOut = finalOut * (1 + n - j) + (1 << (n - j)) - 1;
	vi buffer(count, 0);
	int i = 0;
	while (finalOut > 0)
	{
		buffer[i] = finalOut & 1;
		finalOut = finalOut >> 1;
		i++;
	}
	for (int j = count - 1; j >= 0; j--) cout << buffer[j];
	return 0;
}