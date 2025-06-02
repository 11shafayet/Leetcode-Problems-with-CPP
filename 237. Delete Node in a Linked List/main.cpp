// https://leetcode.com/problems/delete-node-in-a-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

// Function to delete the given node
void deleteNode(ListNode* node) {
    node->val = node->next->val;
    ListNode* temp = node->next;
    node->next = node->next->next;
    delete temp;
}

// Helper to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper to find node with a specific value
ListNode* findNode(ListNode* head, int val) {
    while (head != NULL && head->val != val)
        head = head->next;
    return head;
}

int main() {
    // Creating linked list: 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original List: ";
    printList(head);

    // Let's delete node with value 5
    ListNode* nodeToDelete = findNode(head, 5);
    if (nodeToDelete && nodeToDelete->next != NULL)
        deleteNode(nodeToDelete);

    cout << "After Deleting 5: ";
    printList(head);

    return 0;
}