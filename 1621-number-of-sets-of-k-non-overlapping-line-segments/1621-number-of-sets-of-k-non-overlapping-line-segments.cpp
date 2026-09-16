class Solution {
public:
    static const long long MOD = 1000000007;

    long long power(long long a, long long b) {
        long long result = 1;

        while (b > 0) {
            if (b & 1)
                result = result * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return result;
    }

    int numberOfSets(int n, int k) {

        // Answer = C(n + k - 1, 2k)
        int N = n + k - 1;
        int R = 2 * k;

        if (R > N)
            return 0;

        long long ans = 1;

        for (int i = 1; i <= R; i++) {
            ans = ans * (N - i + 1) % MOD;

            // Divide by i using modular inverse
            ans = ans * power(i, MOD - 2) % MOD;
        }

        return ans;
    }
};