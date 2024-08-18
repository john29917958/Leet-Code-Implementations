#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    ListNode *l1Ptr;
    ListNode *l2Ptr;
    ListNode *sumListHeadPtr;
    ListNode *sumListCurrPtr;
    bool isHasCarry;
    int sum;

    void initMembers(ListNode *list1HeadPtr, ListNode *list2HeadPtr)
    {
        this->l1Ptr = list1HeadPtr;
        this->l2Ptr = list2HeadPtr;
        this->sumListHeadPtr = nullptr;
        this->sumListCurrPtr = nullptr;
        this->isHasCarry = false;
        this->sum = 0;
    }

    void addListValToSum(ListNode *listNodePtr)
    {
        if (listNodePtr != nullptr)
        {
            this->sum += listNodePtr->val;
        }
    }

    void increaseSumAndTurnOffCarryIfHasCarry()
    {
        if (this->isHasCarry)
        {
            this->sum += 1;
            this->isHasCarry = false;
        }
    }

    void setCarryIfSumLargerThan9()
    {
        if (this->sum > 9)
        {
            this->sum -= 10;
            this->isHasCarry = true;
        }
    }

    void addNewSumListNode()
    {
        ListNode *newNode = new ListNode(this->sum);
        if (this->sumListHeadPtr == nullptr)
        {
            this->sumListHeadPtr = newNode;
            this->sumListCurrPtr = newNode;
        }
        else
        {
            this->sumListCurrPtr->next = newNode;
            this->sumListCurrPtr = newNode;
        }
    }

    ListNode *getShiftedListNodePtr(ListNode *listNodePtr)
    {
        if (listNodePtr != nullptr)
        {
            return listNodePtr->next;
        }
        else
        {
            return nullptr;
        }
    }

    void addNewSumListNodeIfHasCarry()
    {
        if (this->isHasCarry)
        {
            ListNode *newNode = new ListNode(1);
            this->sumListCurrPtr->next = newNode;
            this->sumListCurrPtr = newNode;
        }
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        this->initMembers(l1, l2);
        do
        {
            this->sum = 0;
            this->addListValToSum(this->l1Ptr);
            this->addListValToSum(this->l2Ptr);
            this->increaseSumAndTurnOffCarryIfHasCarry();
            this->setCarryIfSumLargerThan9();
            this->addNewSumListNode();
            this->l1Ptr = this->getShiftedListNodePtr(this->l1Ptr);
            this->l2Ptr = this->getShiftedListNodePtr(this->l2Ptr);
        } while (this->l1Ptr != nullptr || this->l2Ptr != nullptr);
        this->addNewSumListNodeIfHasCarry();
        return sumListHeadPtr;
    }
};

void print_answer(ListNode *answerHeadPtr)
{
    ListNode *answerPtr = answerHeadPtr;
    std::cout << "Answer: [";
    if (answerPtr != nullptr)
    {
        std::cout << answerPtr->val;
        while (answerPtr->next != nullptr)
        {
            answerPtr = answerPtr->next;
            std::cout << ", " << answerPtr->val;
        }
    }
    std::cout << "]";
}

int main(int argc, char **argv)
{
    Solution s;
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode *answer = s.addTwoNumbers(l1, l2);
    print_answer(answer);
    std::cout << std::endl;

    l1 = new ListNode(0);
    l2 = new ListNode(0);
    answer = s.addTwoNumbers(l1, l2);
    print_answer(answer);
    std::cout << std::endl;

    l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
    answer = s.addTwoNumbers(l1, l2);
    print_answer(answer);
    std::cout << std::endl;

    return 0;
}