// Author : Aniruddha Krishna Jha
// Date : 16/08/2021

/*******************************************************************************
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive
(i.e. nums[left] + nums[left + 1] + ... + nums[right]).
*******************************************************************************/
class NumArray {
/* 
 * Solution
 * =========
 * The sum of all the elements starting from position 0 to position i is stored in
 * sums[i]. This way we can reconstruct the sum from position i to position j by
 * subtracting sums[i - 1] from sums[j], leaving us with the sum of the desired elements.
 *
 * We can add a dummy sum at then beginning to simplify the code
 * 
 */
private:
    int size;
    vector <long long> sums;
public:
    NumArray(vector<int> &nums): size(nums.size()), sums(size+1, 0) {
        for(int i=0; i<size; i++) {
            sums[i+1] = sums[i] + nums[i];
        } 
    }
    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */