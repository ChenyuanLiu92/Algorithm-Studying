# 相同的树

## 深度优先遍历

1. 同时遍历两颗树，同时比较每个节点的值，如果两个节点都为空，则说明相等，如果两个节点都不为空并且值相同，则继续递归；若节点一个存在一个不存在则返回false。
2. 可以直接用一个函数的递归就可以得出，额外创建一个函数的递归会导致时间开销。

## 广度优先遍历
思路和深度优先遍历一样。