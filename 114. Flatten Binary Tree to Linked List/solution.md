# 二叉树展开为链表
## 1. 笨办法——用队列保存遍历结果
·用一个队列保存先根遍历的结果，然后进行指针连接。
# 2. 空间复杂度为常数的方法
· 考虑到先根遍历时，上一个结点的left显然不会再使用；
· 则根据上述性质，可以使用left结点连接链表，然后再将链表反转即可；
注： 由于递归的原因，在不同阶段的pre不是最新的pre结点，则用一个全局的pre结点来保存最新的pre结点。