#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class BinaryToDecimalConverter {
public:
    int getDecimalValue(ListNode* head) {
        int num = 0;
        while (head != nullptr) {
            num = (num << 1) | head->val;
            head = head->next;
        }
        return num;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    BinaryToDecimalConverter converter;

    int result = converter.getDecimalValue(head);
    cout << "Decimal Value of Linked List: " << result << endl;

    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
