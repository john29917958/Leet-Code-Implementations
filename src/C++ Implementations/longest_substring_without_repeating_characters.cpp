#include <string>
#include <iostream>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int maxLength = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int noRepeatingCharStrLength = 0;
            std::string noRepeatingCharStr = "";
            int index = i;
            bool isRepeatingCharFound = false;
            while (index < s.length() && !isRepeatingCharFound)
            {
                char character = s[index];
                if (noRepeatingCharStr.find(character) == std::string::npos)
                {
                    noRepeatingCharStr += character;
                    ++noRepeatingCharStrLength;
                }
                else
                {
                    isRepeatingCharFound = true;
                }
                ++index;
            }
            if (noRepeatingCharStrLength > maxLength)
            {
                maxLength = noRepeatingCharStrLength;
            }
        }
        return maxLength;
    }
};

int main(int argc, char **argv)
{
    Solution solution;
    std::string input = "abcabcbb";
    int length = solution.lengthOfLongestSubstring(input);
    std::cout << "Answer length of \"" << input << "\" is " << length << std::endl;
    input = "bbbbb";
    length = solution.lengthOfLongestSubstring(input);
    std::cout << "Answer length of \"" << input << "\" is " << length << std::endl;
    input = "pwwkew";
    length = solution.lengthOfLongestSubstring(input);
    std::cout << "Answer length of \"" << input << "\" is " << length << std::endl;
    input = " ";
    length = solution.lengthOfLongestSubstring(input);
    std::cout << "Answer length of \"" << input << "\" is " << length << std::endl;
    input = "dvdf";
    length = solution.lengthOfLongestSubstring(input);
    std::cout << "Answer length of \"" << input << "\" is " << length << std::endl;
    return 0;
}