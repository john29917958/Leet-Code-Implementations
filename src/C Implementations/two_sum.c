#include "stdlib.h"
#include "stdio.h"

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int isAnswerFound = 0;
    int i = 0;
    int *answer = 0;
    *returnSize = 0;
    do
    {
        int j = i + 1;
        do
        {
            if (nums[i] + nums[j] == target)
            {
                answer = (int *)malloc(2 * sizeof(int));
                answer[0] = i;
                answer[1] = j;
                *returnSize = 2;
                isAnswerFound = 1;
            }
            j++;
        } while (isAnswerFound == 0 && j < numsSize);
        i++;
    } while (isAnswerFound == 0 && i < numsSize - 1);
    return answer;
}

void print_answer(int *answer_arr, int size)
{
    printf("Answer is: [");
    if (size > 0)
    {
        printf("%d", answer_arr[0]);
        if (size == 2)
        {
            printf(", %d", answer_arr[1]);
        }
    }
    printf("]");
}

int main(int argc, char **argv)
{
    int inputSize = 4;
    int target = 9;
    int *input = (int *)malloc(inputSize * sizeof(int));
    input[0] = 2;
    input[1] = 7;
    input[2] = 11;
    input[3] = 15;
    int *returnSize = (int *)malloc(sizeof(int));
    *returnSize = 0;
    int *answer = twoSum(input, inputSize, target, returnSize);
    if (answer == 0)
    {
        printf("No number can be added up to target %d.\n", target);
    }
    else
    {
        print_answer(answer, *returnSize);
        printf("\n");
    }

    return 0;
}