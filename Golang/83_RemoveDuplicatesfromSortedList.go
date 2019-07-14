/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil {
        return head
    }
    
    p := head
    q := head.Next
    for {
        if q == nil {
            break
        }
        
        if p.Val == q.Val {
            p.Next = q.Next
        } else {
            p = p.Next
        }
        q = q.Next
    }
    return head
}
