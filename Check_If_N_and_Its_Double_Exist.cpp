using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        //my thought 
        /*bool result = false;
        float compare = 0;
        float standard = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            float standard = arr[i];

            if (standard == 0)
                standard = arr[i + 1];

            float divideByTwo = standard / 2.f;
            for (int y = 0; y < arr.size(); y++)
            {
                compare = arr[y];
                if (divideByTwo == compare)
                    return true;
            }
        }
        return result;*/
        //using set algorithm
        //set<int> s;
        /*for (int i = 0; i < arr.size(); i++)
        {
            if (s.find(arr[i] * 2) != s.end()) //!=s.end()를 하는 이유는 find를 했을때 찾고자하는 element를 못찾으면 end()를 리턴하게 되는게 이를 방지하고자
                                               //따라서 무조건 원소를 찾는경우다 라고 이해하면 된다.
                return true;

            if (arr[i] % 2 == 0 && s.find(arr[i] * 2) != s.end())
                return true;

            s.insert(arr[i]);
        }*/

        //using map algorithm
        //unordered_map<int, int> mp;
        //for (int i = 0; i < arr.size(); i++)
        //{
        //    //if (mp.find(arr[i] * 2) != mp.end())
        //    //    return true;
        //    //if (arr[i] % 2 == 0 && mp.find(arr[i] / 2) != mp.end())
        //    //    return true;
        //    //mp[arr[i]]++;
        //}
        //return false;
    }
};


int main() {
    std::vector<int> test3 = { -2,0,10,-19,4,6,-8};
    std::vector<int> test2 = { 3, 1, 7, 11 };
    std::vector<int> test = { -20,8,-6,-14,0,-19,14,4 };
    std::vector<int> test4 = { 10, 2, 5, 3 };

    Solution sol;

    std::cout<<sol.checkIfExist(test4)<<std::endl;
    std::cout<<sol.checkIfExist(test2)<<std::endl;
    std::cout<<sol.checkIfExist(test3)<<std::endl;
    std::cout<<sol.checkIfExist(test)<<std::endl;

}
