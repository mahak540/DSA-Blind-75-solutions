ListNode* mergeKLists(vector<ListNode*>& lists) {
         priority_queue<int,vector<int>,greater<int>>minheap;
        for(auto it:lists)
        {
            while(it!=NULL)
            {
                minheap.push(it->val);
                it=it->next;
                
            }
        }
        ListNode *dummy=new ListNode(0);
        ListNode *curr=dummy;
        while(!minheap.empty())
        {
            curr->next=new ListNode(minheap.top());
            minheap.pop();
            curr=curr->next;
        }
        return dummy->next;
    }
