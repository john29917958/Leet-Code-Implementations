#include "stdlib.h"
#include "stdio.h"

struct ListNode
{
    int val;
    struct ListNode *next;
};

int get_sum_added_with_list_node_val(struct ListNode *list_node_ptr, int sum)
{
    int result_sum = sum;
    if (list_node_ptr != 0)
    {
        result_sum += list_node_ptr->val;
    }
    return result_sum;
}

int *get_sum_and_carry_after_carry_added_to_num(int is_has_carry, int sum)
{
    int result_sum = sum;
    int result_is_has_carry = is_has_carry;
    if (is_has_carry == 1)
    {
        ++result_sum;
        result_is_has_carry = 0;
    }
    int *result = (int *)malloc(2 * sizeof(int));
    result[0] = result_sum;
    result[1] = result_is_has_carry;
    return result;
}

int *get_sum_and_carry_after_calculated_carry(int is_has_carry, int sum)
{
    int result_is_has_carry = is_has_carry;
    int result_sum = sum;
    if (result_sum > 9)
    {
        result_sum -= 10;
        result_is_has_carry = 1;
    }
    int *result = (int *)malloc(2 * sizeof(int));
    result[0] = result_sum;
    result[1] = result_is_has_carry;
    return result;
}

struct ListNode **get_new_list_nodes(int sum, struct ListNode *sum_list_head_ptr, struct ListNode *sum_list_curr_ptr)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->val = sum;
    new_node->next = 0;
    struct ListNode *new_sum_list_head_ptr = sum_list_head_ptr;
    struct ListNode *new_sum_list_curr_ptr = sum_list_curr_ptr;
    if (new_sum_list_head_ptr == 0)
    {
        new_sum_list_head_ptr = new_node;
        new_sum_list_curr_ptr = new_node;
    }
    else
    {
        new_sum_list_curr_ptr->next = new_node;
        new_sum_list_curr_ptr = new_node;
    }
    struct ListNode **new_list_nodes = (struct ListNode **)malloc(sizeof(struct ListNode) * 2);
    new_list_nodes[0] = new_sum_list_head_ptr;
    new_list_nodes[1] = new_sum_list_curr_ptr;
    return new_list_nodes;
}

struct ListNode *get_shifted_list_node_pointer(struct ListNode *list_node_ptr)
{
    if (list_node_ptr != 0)
    {
        return list_node_ptr->next;
    }
    else
    {
        return 0;
    }
}

struct ListNode *add_list_node_if_has_carry(int is_has_carry, struct ListNode *list_node_ptr)
{
    if (is_has_carry == 1)
    {
        struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = 1;
        new_node->next = 0;
        list_node_ptr->next = new_node;
        return new_node;
    }
    else
    {
        return list_node_ptr;
    }
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *l1_ptr = l1;
    struct ListNode *l2_ptr = l2;
    struct ListNode *sum_list_head_ptr = 0;
    struct ListNode *sum_list_curr_ptr = 0;
    int is_has_carry = 0;
    do
    {
        int sum = 0;
        sum = get_sum_added_with_list_node_val(l1_ptr, sum);
        sum = get_sum_added_with_list_node_val(l2_ptr, sum);
        int *carry_processed_sum_and_carry = get_sum_and_carry_after_carry_added_to_num(is_has_carry, sum);
        sum = carry_processed_sum_and_carry[0];
        is_has_carry = carry_processed_sum_and_carry[1];
        int *carry_and_sum_after_calculated_carry = get_sum_and_carry_after_calculated_carry(is_has_carry, sum);
        sum = carry_and_sum_after_calculated_carry[0];
        is_has_carry = carry_and_sum_after_calculated_carry[1];
        struct ListNode **new_list_nodes = get_new_list_nodes(sum, sum_list_head_ptr, sum_list_curr_ptr);
        sum_list_head_ptr = new_list_nodes[0];
        sum_list_curr_ptr = new_list_nodes[1];
        l1_ptr = get_shifted_list_node_pointer(l1_ptr);
        l2_ptr = get_shifted_list_node_pointer(l2_ptr);
    } while (l1_ptr != 0 || l2_ptr != 0);
    sum_list_curr_ptr = add_list_node_if_has_carry(is_has_carry, sum_list_curr_ptr);
    return sum_list_head_ptr;
}

void print_answer(struct ListNode *answer_head_ptr)
{
    printf("[");
    struct ListNode *answer_ptr = answer_head_ptr;
    if (answer_ptr != 0)
    {
        printf("%d", answer_ptr->val);
        answer_ptr = answer_ptr->next;

        while (answer_ptr != 0)
        {
            printf(", %d", answer_ptr->val);
            answer_ptr = answer_ptr->next;
        }
    }
    printf("]");
}

int main(int argc, char **argv)
{
    struct ListNode *l1_head = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1_head->val = 2;
    struct ListNode *l1_2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1_2->val = 4;
    l1_head->next = l1_2;
    struct ListNode *l1_3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1_3->val = 3;
    l1_2->next = l1_3;

    struct ListNode *l2_head = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2_head->val = 5;
    struct ListNode *l2_2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2_2->val = 6;
    l2_head->next = l2_2;
    struct ListNode *l2_3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2_3->val = 4;
    l2_2->next = l2_3;

    struct ListNode *answer_head_ptr = addTwoNumbers(l1_head, l2_head);
    print_answer(answer_head_ptr);

    return 0;
}
