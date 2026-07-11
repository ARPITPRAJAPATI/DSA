Merge_Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

solution:

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {}; // edge case 

        sort(intervals.begin(),intervals.end()); // sort the intervals
        vector<vector<int>> ans; // make a vector for result
        ans.push_back(intervals[0]); // put first element of intervals into ans // so we can compare 

        for(int i = 1; i<intervals.size();i++){ // move till last interval 
            if(intervals[i][0]<=ans.back()[1]){ // if [1,3],[2,6]  => if ans back [1]>=recent interval
                 ans.back()[1] = max(ans.back()[1],intervals[i][1]); // add a interval having min [0] and max [1] btw compare ones
            }
            else {
                ans.push_back(intervals[i]); // else push the thing into result
            }
        }
        return ans; // return ans
    }
};