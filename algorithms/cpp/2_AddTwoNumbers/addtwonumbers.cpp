#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode *l3 = new ListNode(0);
        ListNode *pl3 = l3;
        while(l1 != NULL || l2 != NULL || carry != 0) {
            sum = 0;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (carry > 0) {
                sum += carry;
                carry = 0;
            }

            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            }

            pl3->next = new ListNode(sum);
            pl3 = pl3->next;
        }

        return l3->next;
    }
};

int main() {
    Solution s;
    ListNode *l1 = NULL;
    ListNode *l2 = NULL;

    s.addTwoNumbers(l1, l2);

    return 0;
}

