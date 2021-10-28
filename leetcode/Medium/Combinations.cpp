class Solution {
public:
    vector<vector<int> > combine(int n, int k)
    {
        vector<vector<int> > ans;
        vector<int> tmp;
        calc(n, ans, tmp, k, 0);
        return ans;
    }

    void calc(int n, vector<vector<int> >& ans, vector<int>& tmp, int k, int cur)
    {
        if (tmp.size() == k) {
            ans.push_back(tmp);
        }

        for (int i = cur + 1; i <= n; i++) {
            if (tmp.size() < k) {
                tmp.push_back(i);
                calc(n, ans, tmp, k, i);
                tmp.pop_back();
            }
        }
    }
};