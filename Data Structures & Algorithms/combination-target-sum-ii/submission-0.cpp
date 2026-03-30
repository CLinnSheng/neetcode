class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int size = candidates.size();
        if (size == 0) return { { } };

        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> ans;
        std::vector<int> subset;
        
        std::function<void(int, int)> dfs_backtracking = [&](int index, int curr_sum) {
            if (curr_sum == target) {
                ans.emplace_back(subset);
                return;
            }

            if (curr_sum > target)
                return;

            for (int i = index; i < size; i++) {
                if (i == index || candidates[i] != candidates[i - 1]) {
                //dfs
                subset.emplace_back(candidates[i]);
                curr_sum += candidates[i];
                dfs_backtracking(i + 1, curr_sum);

                //backtracking
                subset.pop_back();
                curr_sum -= candidates[i];
            }
            }
        };
        dfs_backtracking(0, 0);
        return std::move(ans);
    }
};
