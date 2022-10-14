#include<iostream>
#include<string>
#include<vector>
using namespace std;

string noPrefix(vector<string> words) {
    vector<vector<int>> trie(1000000, vector<int> (26,0));
    vector<bool> isEnd(1000000);

    int N =0;
    for(string s : words) {
        int node = 0;
        for(char c : s) {
            if(trie[node][c - 'a'] == 0) {
                trie[node][c - 'a'] = ++N;
            }
            if(!isEnd[N]) {
                node = N;
            } else {
                return s;
            }
        }
        isEnd[node] = true;
    }
    return " ";
}


int main()
{
    vector<string> myWords {"apple","app","apples","cat","cats"};
    cout<<noPrefix(myWords)<<'\n';
//    cout<<"hi\n";
    return 0;
}
