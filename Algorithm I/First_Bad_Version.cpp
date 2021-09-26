// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n)
    {
        int bad = 0;
        int l = 1, r = n;
        while (l <= r) {
            int mid = (1LL * l + r) / 2;
            if (isBadVersion(mid)) {
                bad = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return bad;
    }
};