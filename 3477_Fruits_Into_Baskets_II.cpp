class SegmentTree {
    int n;
    vector<int> tree;

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, n - 1, 0);
    }

    void build(const vector<int>& arr, int l, int r, int idx) {
        if (l == r) {
            tree[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, l, mid, 2 * idx + 1);
        build(arr, mid + 1, r, 2 * idx + 2);
        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    int query(int l, int r, int val, int sl, int sr, int idx) {
        if (sl > sr || tree[idx] < val) return -1;
        if (sl == sr) return sl;

        int mid = (sl + sr) / 2;
        int left = query(l, r, val, sl, mid, 2 * idx + 1);
        if (left != -1) return left;
        return query(l, r, val, mid + 1, sr, 2 * idx + 2);
    }

    void update(int pos, int value, int sl, int sr, int idx) {
        if (sl == sr) {
            tree[idx] = value;
            return;
        }

        int mid = (sl + sr) / 2;
        if (pos <= mid) update(pos, value, sl, mid, 2 * idx + 1);
        else update(pos, value, mid + 1, sr, 2 * idx + 2);

        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    int findLeftmost(int val) {
        return query(0, n - 1, val, 0, n - 1, 0);
    }

    void markUsed(int index) {
        update(index, -1, 0, n - 1, 0);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentTree st(baskets);
        int unplaced = 0;

        for (int fruit : fruits) {
            int idx = st.findLeftmost(fruit);
            if (idx == -1) {
                unplaced++;
            } else {
                st.markUsed(idx);
            }
        }

        return unplaced;
    }
};