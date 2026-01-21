/*

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2

Example 2:

Input: nums = [3,1,3,4,2]
Output: 3

Example 3:

Input: nums = [3,3,3,3,3]
Output: 3

*/

#include <iostream> 
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fastPointer = nums[0];
        int slowPointer = nums[0];
        
        cout<<"slowPointer = "<<slowPointer<<",fastPointer =  "<<fastPointer<<endl;
        

        slowPointer = nums[slowPointer];
        fastPointer = nums[nums[fastPointer]];

        cout<<"slowPointer = "<<slowPointer<<",fastPointer =  "<<fastPointer<<endl;

        // if(fastPointer == slowPointer) {
        //     return nums[slowPointer];
        // }

        while(fastPointer != slowPointer) {

            slowPointer = nums[slowPointer];
            fastPointer = nums[nums[fastPointer]];
            cout<<"slowPointer = "<<slowPointer<<",fastPointer =  "<<fastPointer<<endl;
        }

        cout<<"***********WHILE LOOP ENDS***************\n";

        slowPointer = nums[0];

        while(slowPointer != fastPointer) {
            slowPointer = nums[slowPointer];
            fastPointer = nums[fastPointer];
            cout<<"slowPointer = "<<slowPointer<<",fastPointer =  "<<fastPointer<<endl;
        }

        cout<<"**************************"<<endl;
        cout<<"slowPointer = "<<slowPointer<<",fastPointer =  "<<fastPointer<<endl;

        return slowPointer;
        
    }
};


int main() {

    Solution sol;

    // vector<int> nums = {1,3,4,2,2};

    vector<int> nums = {2,5,9,6,9,3,8,9,7,1};
    

    cout<<sol.findDuplicate(nums)<<endl;

    return 0;
}