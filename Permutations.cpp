class Solution {
public:
    void generate(vector<vector<int>>& res, vector<int>& vec, int pos) {
        if (pos == (vec.size() - 1))
        {
            res.push_back(vec);
            return;
        }

        for (int i = pos; i < vec.size(); i++)
        {
            swap(vec[pos], vec[i]);
            generate(res, vec, pos + 1);
            swap(vec[pos], vec[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        generate(result, nums, 0);
        return result;
    }
};