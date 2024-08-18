#include "stdio.h"
#include "string.h"

int lengthOfLongestSubstring(char *s)
{
    int max_length = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        int index = i;
        int is_has_meet_duplicate_char = 0;
        char no_repeating_char_str[999] = "";
        int no_repeating_char_str_len = 0;
        while (s[index] != '\0' && is_has_meet_duplicate_char == 0)
        {
            char curr_char = s[index];
            if (strchr(no_repeating_char_str, curr_char) == NULL)
            {
                strncat(no_repeating_char_str, &curr_char, 1);
                ++no_repeating_char_str_len;
            }
            else
            {
                is_has_meet_duplicate_char = 1;
            }
            ++index;
        }
        if (no_repeating_char_str_len > max_length)
        {
            max_length = no_repeating_char_str_len;
        }
    }
    return max_length;
}

int main(int argc, char **argv)
{
    int length = lengthOfLongestSubstring("abcabcbb");
    printf("Answer length of \"abcabcbb\" is %d\n", length);
    length = lengthOfLongestSubstring("bbbbb");
    printf("Answer length of \"bbbbb\" is %d\n", length);
    length = lengthOfLongestSubstring("pwwkew");
    printf("Answer length of \"pwwkew\" is %d\n", length);
    length = lengthOfLongestSubstring(" ");
    printf("Answer length of \" \" is %d\n", length);
    length = lengthOfLongestSubstring("dvdf");
    printf("Answer length of \"dvdf\" is %d\n", length);
    return 0;
}