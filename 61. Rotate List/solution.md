# 旋转链表
## 1. 刷新值法（偷懒）
利用辅助栈来实现反转，这里由于调整结点比较麻烦，所以直接调整值。
1. 先获取k % length的值，k不管为多大，实际相当于旋转这么多次。
2. 用栈先对整个链表进行一次反转。
3. 再用栈对前k个结点和后面的结点进行反转，得到的就是结果。
住：这里直接调整了值，结点的连接关系比较复杂，所以可以考虑直接调整值。
