struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // min-heap: smallest value on top
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;

    // Add the head of each list to the heap
    for (auto node : lists) {
        if (node != nullptr)
            pq.push(node);
    }

    ListNode dummy(0);  // Dummy node to build the result list
    ListNode* tail = &dummy;

    while (!pq.empty()) {
        ListNode* node = pq.top(); pq.pop();
        tail->next = node;
        tail = tail->next;

        if (node->next != nullptr) {
            pq.push(node->next);
        }
    }

    return dummy.next;
}
