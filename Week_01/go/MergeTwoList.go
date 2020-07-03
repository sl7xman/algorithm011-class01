func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    var tmp ListNode
    cur := &tmp;

    for ( l1 != nil && l2 != nil ) {
        if l1.Val > l2.Val {
            cur.Next, l2 = l2, l2.Next
        } else {    
            cur.Next, l1 = l1, l1.Next
        }
        cur = cur.Next
    }
    if l1 != nil {
        cur.Next = l1
    }
    if l2 != nil {
        cur.Next = l2
    }
    return tmp.Next
}
