#include "stdio.h"
#include "string.h"

int lengthOfLongestSubstring(char *s)
{
    int max_length = 0;
    char no_repeating_char_str[99999] = "";
    int index = 0;
    while (s[index] != '\0')
    {
        char curr_char = s[index];
        if (strchr(no_repeating_char_str, curr_char) == NULL)
        {
            strcat(no_repeating_char_str, &curr_char);
        }
        else
        {
            int curr_no_repeating_char_str_len = strlen(no_repeating_char_str);
            if (curr_no_repeating_char_str_len > max_length)
            {
                max_length = curr_no_repeating_char_str_len;
            }
            no_repeating_char_str[0] = '\0';
        }
        ++index;
    }
    return max_length;
}

int main(int argc, char **argv)
{
    int length = lengthOfLongestSubstring("abcabcbb");
    length = lengthOfLongestSubstring("bbbbb");
    length = lengthOfLongestSubstring("pwwkew");
    return 0;
}