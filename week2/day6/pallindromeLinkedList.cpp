#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int data) {
        val = data;
        next = NULL;
    }
};

ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr != NULL) {
        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* secondHalf = reverse(slow->next);

    ListNode* first = head;
    ListNode* second = secondHalf;

    while (second != NULL) {
        if (first->val != second->val) {
            return false;
        }

        first = first->next;
        second = second->next;
    }

    return true;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    if (isPalindrome(head)) {
        cout << "Palindrome";
    } else {
        cout << "Not Palindrome";
    }

    return 0;
}
