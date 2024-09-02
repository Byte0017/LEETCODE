class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // Ensure nums1 is the smaller array
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        if (m == 0 && n == 0) return 0.0;
        if (m == 0) {
            // Handle case where nums1 is empty
            if (n & 1) return nums2[n / 2] / 1.0;
            else return (nums2[(n - 1) / 2] + nums2[n / 2]) / 2.0;
        }
        if (n == 0) {
            // Handle case where nums2 is empty
            if (m & 1) return nums1[m / 2] / 1.0;
            else return (nums1[(m - 1) / 2] + nums1[m / 2]) / 2.0;
        }

        // Binary search in nums1
        int low = 0, high = m;
        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Correct partition found
                if ((m + n) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    return max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                // Move towards the left in nums1
                high = partition1 - 1;
            } else {
                // Move towards the right in nums1
                low = partition1 + 1;
            }
        }

        // If we reach here, input arrays were not sorted properly (per problem constraint)
        return 0.0;
    }
};

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { //brute force way
//         // Get the sizes of both input arrays.
//         int n = nums1.size();
//         int m = nums2.size();
//         double answer = 0.0;

//         // Merge the arrays into a single sorted array.
//         // interate elemetns into vector
//         vector<int> merged_arr;
//         for (int i = 0; i < n; i++) {
//             merged_arr.push_back(nums1[i]);
//         }
//         for (int i = 0; i < m; i++) {
//             merged_arr.push_back(nums2[i]);
//         }

//         // Sort the merged_arr array from beggging to end (all elements).
//         sort(merged_arr.begin(), merged_arr.end());

//         // Calculate the total number of elements in the merged_arr array.
//         int total = merged_arr.size();

//         if (total % 2 == 1) {// checks if odd with modular
//             answer = merged_arr[total / 2];
//         } else {
//             // If the total number of elements is even total %2 = 0, calculate the average of the two middle elements as the median.
//           answer =   (merged_arr[total / 2 - 1] +  merged_arr[total / 2])/2.0;
//         }
//         std::cout << "Mereged array: " << merged_arr.size() << " and median is " << answer; 
//         return answer;
//     }
            

// };
 