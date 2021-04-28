#include<iostream>
#include<vector>
using namespace std;

// https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof


class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.empty()) return -1;
        if(numbers.front() < numbers.back()) return numbers.front();
        return dfs(numbers, 0, numbers.size()-1);
    }

    int dfs(vector<int>& numbers, int left, int right) {
        if(left == right) return numbers[left];
        int ans = -1;
        while(left < right) {
            int mid = (left+right)/2;

            if(numbers.front() < numbers[mid] || numbers[mid] > numbers.back()) {
                left = mid+1;
            } else if(numbers[mid] < numbers.back() || numbers[mid] < numbers.front()){
                right = mid;
            } else {
                ans =  std::min(dfs(numbers, left, mid), dfs(numbers, mid+1, right));
                break;
            }
        }

        return ans != -1 ? ans: std::min(numbers[left], numbers[right]);
    }

    int minArray2(vector<int>& numbers) {
        int low = 0;
        int high = numbers.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (numbers[pivot] < numbers[high]) {
                high = pivot;
            }
            else if (numbers[pivot] > numbers[high]) {
                low = pivot + 1;
            }
            else {
                high -= 1;
            }
        }
        return numbers[low];
    }
};