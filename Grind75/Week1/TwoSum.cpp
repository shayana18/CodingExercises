// problem: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice. 
// You can return the answer in any order.

// intuition: we can use a nested for loop here. We essentially want to hold one number in the array at a time
// then iterate through the same array using a second for loop, this for-loop needs an internal condition that skips a number if it is the 
// same number as the one we are holding. In the case the current number is not the held number we add and then check if it equals the target.
// if it equals the target we return the indices if not we increment the top level for loop



#include <vector>
#include <map>

using namespace std;


// Attempt 1: 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> returnVector; 
        for(int i = 0; i < nums.size(); i++){
            for (int y = 0; y < nums.size(); y++){
                if (i != y){
                    if (nums[i] + nums[y] == target){
                        returnVector.push_back(i);
                        returnVector.push_back(y);
                        return returnVector;
                    }
                }
            }
        }
        return returnVector;
    }
};

// Problems: the above approach works however it is inefficent as it checks each and every pair possible in the array which includes duplicate pairs.
// Iterating this way interates across each and every element one at a time which is time inefficent



// intution: we can take advantage of the contains function in of a hashmap to element the need of the nested for-loop.
// What we can do is that we can take our current index and subtract it from our target, then we check if the diference exists
// in the hashmap, if not then add this current index number into the hashmap then increment our for-loop. 
// here to make the process easier the key will be made the number in the array and the value will be the index

// Attempt 2 (After learning more c++ / seeing reading about other approaches)

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> arrayMap; 
        vector<int> returnVector; 
        for(int i = 0; i < nums.size(); i++){
            if (arrayMap.find(target - nums[i]) != arrayMap.end()){
                returnVector.push_back(i);
                returnVector.push_back(arrayMap.at(target - nums[i]));
                return returnVector;
            }
            else{
                arrayMap.insert(make_pair(nums[i], i));
            }
        }
        return returnVector; 
    }
};




