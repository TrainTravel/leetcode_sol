# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # if l1.val == 0:
        #     return l2
        # elif l2.val == 0:
        #     return l1

        curr1, curr2 = l1, l2
        res_node = None
        curr_res_node = None
        carry = 0
        while(curr1 or curr2 or carry):
            # print(carry)
            if curr1 and curr2:
                original_digit_sum = curr1.val + curr2.val + carry
                # print(original_digit_sum)
            elif curr1 and not curr2:
                original_digit_sum = curr1.val + carry
            elif curr2 and not curr1:
                original_digit_sum = curr2.val + carry
            else: #carry = 1
                curr_res_node.next = ListNode(1)
                break
            carry = 0
            new_digit = original_digit_sum
            if original_digit_sum > 9:
                new_digit = original_digit_sum - 10
                # print(new_digit)
                carry = 1
            if not res_node:
                # print("first res_node")
                res_node = ListNode(new_digit)
                curr_res_node = res_node
            else:
                curr_res_node.next = ListNode(new_digit)
                curr_res_node = curr_res_node.next
        
            if curr1:
                curr1 = curr1.next
            if curr2:
                curr2 = curr2.next
        return res_node
