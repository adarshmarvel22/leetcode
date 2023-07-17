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
    string add_two_str_no(string n1, string n2){
        
        int n=n1.size()-1;
        int m=n2.size()-1;
        
        string ans="";
        
          int carry = 0;
           int sum = 0;
        
           while(n >= 0 and m>=0) {
                int a = n1[n] - '0';
                int b = n2[m] - '0';
                sum = (a + b + carry) % 10;
                carry = (carry + a + b) / 10;
               
               ans+=(sum+'0');
               n--,m--;
             }
        
        while(n>=0){
                int a = n1[n] - '0';
                sum = (a + carry) % 10;
                carry = (carry + a) / 10;
               ans+=(sum+'0');
               n--;
        }
        
            while(m>=0) {
                int b = n2[m] - '0';
                sum = (b + carry) % 10;
                carry = (carry + b) / 10;
               ans+=(sum+'0');
               m--;
             }
        
        if(carry>0){
            ans+=(carry+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

          string no1="",no2="";
        
        while(l1!=NULL){
           no1+=(l1->val+'0');
            l1=l1->next;
        }
        
        while(l2!=NULL){
           no2+=(l2->val+'0');
            l2=l2->next;
        }

        string s=add_two_str_no(no1,no2);
        cout<<s;
        
        ListNode*h=new ListNode();
    
        int n=s.size();
        ListNode*tmp=h;
        
        for(int i=0;i<n;i++){
            tmp->val=s[i]-'0';
            if(i!=n-1){
                tmp->next=new ListNode();
                tmp=tmp->next;
            }
        }
        
        return h;
    }
};