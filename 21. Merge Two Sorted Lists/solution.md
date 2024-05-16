# 合并两个有序链表

## 思路一
    - 用list1和list2两个指针遍历两个链表，设置一个i指针用来构造新的链表，设置一个res指针用来返回值。
    - 当list1和list2都不为nullptr时，如果left的值小于等于list2的值，则将i的i连接到list1的节点，然后让list1 = list1->next，同理如果list2的值小于list1的值，则将i连接到list2的节点，然后让list2 = list2->next。
    - 将没有遍历完的节点与i进行连接

## 细节
    注意要让i每次循环变为其next所指的元素

## 思路二————递归
