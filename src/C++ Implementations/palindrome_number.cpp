#include <iostream>
#include <string>
#include <algorithm>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        std::string x_str = std::to_string(x);
        std::string x_str_reversed = x_str;
        std::reverse(x_str_reversed.begin(), x_str_reversed.end());
        return x_str == x_str_reversed;
    }
};

int main(int argc, char **argv)
{
    Solution solution;
    int input = 121;
    bool is_palindrome = solution.isPalindrome(input);
    std::cout << "Is " << input << " a palindrome?: " << (is_palindrome ? "true" : "false") << std::endl;
    input = -121;
    is_palindrome = solution.isPalindrome(input);
    std::cout << "Is " << input << " a palindrome?: " << (is_palindrome ? "true" : "false") << std::endl;
    input = 10;
    is_palindrome = solution.isPalindrome(input);
    std::cout << "Is " << input << " a palindrome?: " << (is_palindrome ? "true" : "false") << std::endl;
    return 0;
}