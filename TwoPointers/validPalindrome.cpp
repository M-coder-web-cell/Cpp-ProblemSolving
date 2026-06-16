#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    string word = s;
    int start = 0;
    int end = s.size() - 1;
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while(start < end){
        while(start < end && letters.find(word[start]) == string::npos) start++;
        while(start < end && letters.find(word[end]) == string::npos) end--;

        if(tolower(word[start]) != tolower(word[end])) return false;
        start++;
        end--;
    }
    return true;
}


int main(){
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s) << endl;
    return 0;
}