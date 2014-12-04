#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (!isalnum(s[i])) {
                ++i;
                continue;
            }
            if (!isalnum(s[j])) {
                --j;
                continue;
            }

            if (tolower(s[i]) != tolower(s[j]))
                return false;
            else {
                ++i;
                --j;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    string str = "A man, a plan, a canal: Panama";
    bool isPalin = s.isPalindrome(str);
    cout << "isPalin:" << isPalin << endl;

    return 0;
}
