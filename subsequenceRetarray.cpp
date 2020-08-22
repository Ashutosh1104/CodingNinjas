#include <iostream>
using namespace std;

int subs(string in, string out[]) {
	if (in.empty()) {
		out[0] = "";
		return 1;
	}
    int c=subs(in.substr(1),out);
    for(int i=0;i<c;i++){
        out[i+c]=in[0]+out[i];
    }
    return 2*c;
}

int main() {
	string input;
	cin >> input;
	string* output = new string[1000];
	int count = subs(input, output);
	for (int i = 0; i < count; i++) {
		cout << output[i] << endl;
	}
}

