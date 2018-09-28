#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isScrambleHelper(string s1, string s2) {
        if (s1.empty() && s2.empty()) return true;

        for (int i=0; i<s1.length(); i++) {
            if (s1[i] != s2[s1.length()-1-i]) return false;
        }
        return true;
    }
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) { return false; }
        if (s1.empty() && s2.empty()) { return false; }
        if (s1 == s2) return true;
        if (isScrambleHelper(s1, s2)) return true;

        int len = s1.length();

        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < len) {

            while (ptr1 < len && s1[ptr1] == s2[ptr2]) {ptr1++; ptr2++;}

            s1 = s1.substr(ptr1);
            ptr1 = 0;
            s2 = s2.substr(ptr2);
            ptr2 = 0;

            while (ptr1 < len && s1[ptr1] != s2[ptr2]) { ptr1++; }
            if (ptr1 >= len) return false;
            if (isScramble(s1.substr(0, ptr1), s2.substr(ptr2+len-ptr1, ptr1)) &&
                isScramble(s1.substr(ptr1, len - ptr1), s2.substr(ptr2, len - ptr1)))
                return true;
            if (!isScrambleHelper(s1.substr(ptr2, ptr1-ptr2+1), s2.substr(ptr2, ptr1-ptr2+1))) {
                ptr1++;
            } else {
                ptr1++;
                ptr2 = ptr1;
            }

        }

        return ptr1 == ptr2;
    }

    /*bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) { return false; }
        if (s1.empty() && s2.empty()) { return true; }
        if (s1 == s2) return true;
        if (isScrambleHelper(s1, s2)) return true;

        int len = s1.length();

        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < len) {
            while (ptr1 < len && ptr2 < len && s1[ptr1] == s2[ptr2]) { ptr1++; ptr2++; }
            if (ptr1 >= len || ptr2 >= len) return false;
            while (ptr1 < len && ptr2 < len && s1[ptr1] != s2[ptr2]) { ptr1++; }
            if (isScramble(s1.substr(0, ptr1), s2.substr(ptr2+len-ptr1, ptr1)) &&
                isScramble(s1.substr(ptr1, len - ptr1), s2.substr(ptr2, len - ptr1)))
                return true;
            if (!isScrambleHelper(s1.substr(ptr2, ptr1-ptr2+1), s2.substr(ptr2, ptr1-ptr2+1))) {
                ptr1++;
            } else {
                ptr1++;
                ptr2 = ptr1;
            }

        }

        return ptr1 == ptr2;
    }*/
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    cout << Solution().isScramble("abcd", "acdb");
}

/*int main() {
    string line;
    while (getline(cin, line)) {
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);

        bool ret = Solution().isScramble(s1, s2);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}*/