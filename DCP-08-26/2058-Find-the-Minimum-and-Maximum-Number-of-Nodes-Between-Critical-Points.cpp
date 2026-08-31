/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ind;

        ListNode* temp = head->next;
        int firstVal = head->val;
        int i = 1;
        while(temp->next){
            if(temp->val > firstVal && temp->val > temp->next->val){
                ind.push_back(i);
            }
            else if(temp->val < firstVal && temp->val < temp->next->val){
                ind.push_back(i);
            }
            i++;
            firstVal = temp->val;
            temp = temp->next;
        }

        for (auto it : ind){
            cout<<it<<endl;
        }
        if(ind.size()<2) return {-1,-1};
        int minDis = INT_MAX;
        int maxDis = -1;

        for (int i = 1;i<ind.size();i++){
            minDis = min(minDis,ind[i]-ind[i-1]);
        }

        int n = ind.size();
        maxDis = ind[n-1] - ind[0];

        return {minDis,maxDis};
    }
};