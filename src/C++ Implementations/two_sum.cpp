#include <map>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::map<int, int> numsAppearancesMap;
        for (int i = 0; i < nums.size(); i++)
        {
            int number = nums[i];
            numsAppearancesMap[number] = i;
        }

        bool isNumsFound = false;
        int index = 0;
        std::vector<int> answer;
        do
        {
            int complement = target - nums[index];
            std::map<int, int>::iterator it = numsAppearancesMap.find(complement);
            if (it->second != index && it != numsAppearancesMap.end())
            {
                int index2 = it->second;
                answer.push_back(index);
                answer.push_back(index2);
                isNumsFound = true;
            }
            index++;
        } while (!isNumsFound && index < nums.size());
        return answer;
    }
};

void print_answer(std::vector<int> &answer)
{
    printf("Answer: [");
    if (answer.size() > 0)
    {
        printf("%d", answer[0]);
        for (std::vector<int>::iterator it = answer.begin() + 1; it != answer.end(); it++)
        {
            printf(", %d", *it);
        }
    }
    printf("]");
}

int main(int argc, char **argv)
{
    Solution s;
    std::vector<int> input;
    input.push_back(2);
    input.push_back(7);
    input.push_back(11);
    input.push_back(15);
    int target = 9;
    std::vector<int> answer = s.twoSum(input, target);
    print_answer(answer);
    printf("\n");

    input.clear();
    input.push_back(3);
    input.push_back(2);
    input.push_back(4);
    target = 6;
    answer = s.twoSum(input, target);
    print_answer(answer);
    printf("\n");

    input.clear();
    input.push_back(3);
    input.push_back(3);
    target = 6;
    answer = s.twoSum(input, target);
    print_answer(answer);
    printf("\n");

    return 0;
}