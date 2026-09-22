class Solution {
public:
    int n, K;
    vector<int> prod;
    vector<vector<int>> cnt;

    void pull(int p) {
        int L = p * 2;
        int R = p * 2 + 1;

        prod[p] = (1LL * prod[L] * prod[R]) % K;

        fill(cnt[p].begin(), cnt[p].end(), 0);

        // Prefixes completely inside left
        for (int r = 0; r < K; r++) {
            cnt[p][r] += cnt[L][r];
        }

        // Prefixes which take all of left
        // and then a prefix of right
        for (int r = 0; r < K; r++) {
            int nr = (1LL * prod[L] * r) % K;
            cnt[p][nr] += cnt[R][r];
        }
    }

    void build(int p, int l, int r, vector<int>& nums) {
        if (l == r) {
            prod[p] = nums[l] % K;
            cnt[p][prod[p]] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(p * 2, l, mid, nums);
        build(p * 2 + 1, mid + 1, r, nums);

        pull(p);
    }

    void update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            fill(cnt[p].begin(), cnt[p].end(), 0);

            prod[p] = val % K;
            cnt[p][prod[p]] = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(p * 2, l, mid, idx, val);
        else
            update(p * 2 + 1, mid + 1, r, idx, val);

        pull(p);
    }

    pair<int, vector<int>> query(
        int p, int l, int r, int ql, int qr
    ) {
        if (ql <= l && r <= qr) {
            return {prod[p], cnt[p]};
        }

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(p * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(p * 2 + 1, mid + 1, r, ql, qr);

        auto left = query(p * 2, l, mid, ql, qr);
        auto right = query(p * 2 + 1, mid + 1, r, ql, qr);

        int newProd =
            (1LL * left.first * right.first) % K;

        vector<int> newCnt(K, 0);

        // Prefix ends in left
        for (int r = 0; r < K; r++) {
            newCnt[r] += left.second[r];
        }

        // Prefix contains all of left
        // and continues into right
        for (int r = 0; r < K; r++) {
            int nr = (1LL * left.first * r) % K;
            newCnt[nr] += right.second[r];
        }

        return {newProd, newCnt};
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        n = nums.size();
        K = k;

        prod.assign(4 * n, 0);
        cnt.assign(4 * n, vector<int>(K, 0));

        build(1, 0, n - 1, nums);

        vector<int> ans;

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(1, 0, n - 1, index, value);

            // Query nums[start ... n-1]
            auto res = query(
                1, 0, n - 1,
                start, n - 1
            );

            ans.push_back(res.second[x]);
        }

        return ans;
    }
};