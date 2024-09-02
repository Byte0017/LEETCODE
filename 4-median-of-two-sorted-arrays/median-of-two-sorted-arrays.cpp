// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m=nums1.size();
//         int n=nums2.size();
//         if(m==0 && n==0) return 0.0;
//         if(m==0){
//             if(n&1) return nums2[n/2]/1.0;
//             else return (nums2[(n-1)/2]+nums2[n/2])/2.0;
//         }
//         if(n==0){
//             if(m&1) return nums1[m/2]/1.0;
//             else return (nums1[(m-1)/2]+nums1[m/2])/2.0;
//         }

//        //apply binary search
//        int i1=0 , i2=0;
//        int j1=m-1 , j2=n-1;
//        int mid1=(i1+j1)/2;
//        int mid2=(i2+j2)/2;

//        int extra=-1; //this one is for in even conditioin

//        while(i1<=j1 && i2<=j2){
//             int a=nums1[mid1];
//             int b=nums2[mid2];

//             if(a==b){
//                 //then stop B.S
//                 //find extra
//                 // if(mid1+1<m && mid2+1<n) extra = nums1[mid1+1]>=nums2[mid2+1] ? nums2[mid2+1] : nums1[mid1+1];
//                 // else if(mid1+1<m) extra=nums1[mid1+1];
//                 // else extra=nums2[mid2+1];
//                 break;
//             }
//             else{
//                 if(a>b){
                    
//                 }
//             }
//        }


//     }
// };
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

