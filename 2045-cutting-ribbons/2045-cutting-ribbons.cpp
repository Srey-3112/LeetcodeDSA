class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int left = 1, right = *max_element(ribbons.begin(), ribbons.end());
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int count = 0;

            for (int r : ribbons) {
                count += r / mid;
            }

            if (count >= k) {
                result = mid;       // mid is valid, try longer
                left = mid + 1;
            } else {
                right = mid - 1;    // mid too long, try shorter
            }
        }

        return result;
    }
};
