#include "headers\Graph.h"
#include<algorithm>

void load_lines(vector <string> &lines) {
    string line;
    ifstream myfile("C:\\Users\\Ashutosh Singh\\source\\repos\\Massitant\\Massitant\\src\\Resources\\example.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            lines.push_back(line);
        }
        myfile.close();
        return;
    }
    else cout << "Unable to open file";
}

void hashes(map<pairstr, int> &result) {
    ifstream myfile("C:\\Users\\Ashutosh Singh\\source\\repos\\Massitant\\Massitant\\src\\Resources\\stations.txt");
    if (myfile.is_open())
    {
        string full;
        while (getline(myfile, full))
        {
            string word = "";
            int j = 0;
            pairstr x;
            int val=0;
            for (int i = 0; i < full.length(); i++) {
                if (full[i] == ' ' && full[i + 2] == 'n'){
                    if(j==0) x.first=word;
                    if (j == 1) {
                        x.second = word;
                        int a = max((int)full[full.length() - 1]-48,0);
                        int b = max((int)full[full.length() - 2]-48,0);
                        val = b * 10 + a;
                        break;
                    }
                    j++;
                    i = i + 3;
                    word = "";
                }
                else {
                    word=word+full[i];
                }
            }
            result[x]=val;
        }
        myfile.close();
        return;
    }
    else cout << "Unable to open file";
}

