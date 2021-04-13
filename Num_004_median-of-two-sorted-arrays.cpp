#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if((m+n) & 0x01 == 1) {
            return findKth(nums1,nums2, (m+n+1)/2);
        } else {
            return (findKth(nums1,nums2, (m+n)/2+1) + findKth(nums1,nums2, (m+n)/2)) / 2.0;
        }
    }

    int findKth(vector<int> v1, vector<int>v2, int num) {
        if(v1.empty() && v2.empty()) return 0;
        if(v1.empty()) return v2.at(num-1);
        if(v2.empty()) return v1.at(num-1);
        if(1 == num) return std::min(v1[0], v2[0]);
        if(v1.size() > v2.size()) {
            v1.swap(v2);
        }

        if(v1.size() <= num/2) {
            int a = v1.back();
            int b = v2[num/2-1];
            if(a <= b) {
                return findKth(std::vector<int>(), v2, num - v1.size());
            } else {
                return findKth(v1, std::vector<int>(v2.begin()+num/2, v2.end()), num-num/2);
            }
        } else {
            int a = v1[num/2-1];
            int b = v2[num/2-1];
            if(a <= b) {
                return findKth(std::vector<int>(v1.begin()+num/2, v1.end()), v2, num-num/2);
            } else {
                return findKth(v1, std::vector<int>(v2.begin()+num/2, v2.end()), num-num/2);
            }
        }
    }
};

int main(){
    std::vector<int> aa{1,2}, bb{3,4};

    Solution sl;
    cout << sl.findMedianSortedArrays(aa, bb) << endl;

    return 0;
}