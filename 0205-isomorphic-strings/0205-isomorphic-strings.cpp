
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (n != m) return false;

        unordered_map<char, char> mp1, mp2;

        for (int i = 0; i < n; i++) {
            char a = s[i];
            char b = t[i];

            if (mp1.count(a) && mp1[a] != b)
                return false;

            if (mp2.count(b) && mp2[b] != a)
                return false;

            mp1[a] = b;
            mp2[b] = a;
        }

        return true;
    }
};
