#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int n = s.length();
        for(int i = 0; i < n; i += 2) {
            if(s[i] == 'a') s[i] = 'b';
            else s[i] = 'a';
        }
        for(int i = 1; i < n; i += 2) {
            if(s[i] == 'z') s[i] = 'y';
            else s[i] = 'z';
        }
        cout << s << '\n';
    }
}