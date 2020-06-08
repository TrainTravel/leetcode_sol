#include<iostream>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int len = nums.size();
        if(len == 0)
            return 0;

        int current_num = nums[0];
        // cout<< current_num << endl;
        unordered_map<int, int> init_map;
        if(current_num != 0)
            init_map = {{current_num, 1}, {-current_num, 1}};
        else
            init_map = {{0, 2}};
        if(len > 1){
            unordered_map<int, int> old_map = init_map;
            for(int i = 1; i < len; i++){
                int current_num = nums[i];

                // cout << "idx: " << i << endl;
                // cout << "current_num: " << current_num << endl;
                unordered_map<int, int> new_map;        
                for(auto &sum : old_map){
                    // cout << sum.first << ", " << sum.second << endl;
                    new_map[sum.first + current_num] += old_map[sum.first];
                    new_map[sum.first - current_num ] += old_map[sum.first];
                }
                old_map = new_map;
            }
            return old_map[S];
        }
            // return renewHashmap(init_map, nums, 1, len)[S];
        else
            return init_map[S];
    }
// private:
//     unordered_map<int, int> renewHashmap(unordered_map<int, int>& old_map, vector<int>& nums, int idx, int len){
//         for(int i = idx; i < len; i++){
//             int current_num = nums[i];

//             // cout << "idx: " << i << endl;
//             // cout << "current_num: " << current_num << endl;
//             unordered_map<int, int> new_map;        
//             for(auto &sum : old_map){
//                 // cout << sum.first << ", " << sum.second << endl;
//                 new_map[sum.first + current_num] += old_map[sum.first];
//                 new_map[sum.first - current_num ] += old_map[sum.first];
//             }
//             old_map = new_map;
//         }
//         return old_map;
//         // if(idx == len - 1)
//         //     return new_map;
//         // else
//         //     return renewHashmap(new_map, nums, idx++, len);
//     }
};