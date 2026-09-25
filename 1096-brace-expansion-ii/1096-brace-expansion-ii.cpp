class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }

private:
    set<string> parse(string& s, int& i) {
        set<string> result;
        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {
                i++; // skip '{'

                set<string> inside = parse(s, i);

                i++; // skip '}'

                current = multiply(current, inside);
            }
            else if (s[i] == ',') {
                // Union current expression into result
                result.insert(current.begin(), current.end());

                current = {""};
                i++;
            }
            else {
                // Single character
                set<string> letter = {string(1, s[i])};

                current = multiply(current, letter);

                i++;
            }
        }

        // Add the last part
        result.insert(current.begin(), current.end());

        return result;
    }

    set<string> multiply(set<string>& a, set<string>& b) {
        set<string> result;

        for (const string& x : a) {
            for (const string& y : b) {
                result.insert(x + y);
            }
        }

        return result;
    }
};