#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define LL long long


using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* mergeTwoLists(ListNode* a, ListNode *b)
	{
		ListNode *list = NULL;

		


		return list;
	}

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
       	int n = lists.size();
       	if(n == 0) return NULL;
       	if(n == 1) return lists[0];
       	
       	vector<ListNode*> v[2];
       	for(int i = 0; i < n; i++)
       	{
       		v[i%2].push_back(lists[i]);
       	}

       	return mergeTwoLists(mergeKLists(v[0]), mergeKLists(v[1]));
    }
};

