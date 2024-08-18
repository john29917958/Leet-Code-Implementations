#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

bool isPalindrome(int x)
{
    char x_str[99];
    sprintf(x_str, "%d", x);
    int length = strlen(x_str);
    int left_idx_ptr = 0;
    int right_idx_ptr = length - 1;
    int mid_idx = length / 2;
    bool is_left_right_same = true;

    do
    {
        if (x_str[left_idx_ptr] == x_str[right_idx_ptr])
        {
            ++left_idx_ptr;
            --right_idx_ptr;
        }
        else
        {
            is_left_right_same = false;
        }
    } while (is_left_right_same && left_idx_ptr <= mid_idx && right_idx_ptr >= mid_idx);

    return is_left_right_same;
}

void print_result(int input, bool is_palindrome)
{
    printf("Is %d a palindrome?: %s\n", input, is_palindrome ? "true" : "false");
}

int main(int argc, char **argv)
{
    int input = 121;
    bool is_palindrome = isPalindrome(input);
    print_result(input, is_palindrome);
    input = -121;
    is_palindrome = isPalindrome(input);
    print_result(input, is_palindrome);
    input = 10;
    is_palindrome = isPalindrome(input);
    print_result(input, is_palindrome);
    return 0;
}