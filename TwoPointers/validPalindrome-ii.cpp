#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int st, int e) {
    string word = s;
    int start = st;
    int end = e;
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
bool validPalindrome(string s) {
    string word = s;
    int start = 0;
    int end = s.size() - 1;
    int k = 1;
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    while(start < end){
        while(start < end && letters.find(word[start]) == string::npos) start++;
        while(start < end && letters.find(word[end]) == string::npos) end--;

        if(tolower(word[start]) != tolower(word[end])){
            return (isPalindrome(word, start+1, end) || isPalindrome(word, start, end-1));
        }
        start++;
        end--;
    }
    return true;
}