/*
Medium

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container
Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
Example 2:

Input: height = [1,1]
Output: 1
Example 3:

Input: height = [4,3,2,1,4]
Output: 16
https://leetcode.com/problems/container-with-most-water/
*/

////////////////////////////////////////////////////////////////
//O(n^2)
////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxArea(vector<int>& height) {
        long long int maxi = 0;
        for(int i =0; i<height.size(); i++){
            for(int j = i +1; j<height.size(); j++){
                int temp;
                temp = min(height[i], height[j]) * abs(i - j);
                if(temp> maxi){
                    maxi= temp;
                }
            }
        }
    return maxi;
    }
};



////////////////////////////////////
////O(n)
////////////////////////////////////
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = 0;
        int i = 0;
        int j = height.size()-1;
        //cout<<j;
        while(i<j){
            int l, w;
            int temp = 0;
            l = min(height[i], height[j]);
            w = j-i;
            temp = l * w;
            maxi = max(maxi, temp);
            if(height[i]<=height[j]){
                i++;                
            }else{
                j--;
            }
        }
    return maxi;
    }
};

////////////////////////////////////
////O(n)
////////////////////////////////////

class Solution {
public:
    int maxArea(vector<int>& height) {
        int amountOfWater = INT_MIN;
        int i =0; 
        int j = height.size()-1;
        
        while(i<j){
            int waterBox = min(height[i], height[j]) * (j - i);
            amountOfWater = max(amountOfWater, waterBox);
            height[i]< height[j] ? i++ : j--;
        }
        return amountOfWater;
        
    }
};

