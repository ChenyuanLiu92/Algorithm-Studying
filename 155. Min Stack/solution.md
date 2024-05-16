# 最小栈
1. 均衡时间
一个偷懒的办法，由于要求以常数级时间返回最小值，因此可以维护一个最小值，而维护最小值的时间开销可以分配到push和pop操作中。<br>
用vector作容器，维护一个min作为最小值，在push和pop操作时候遍历vector更新最小值。
2. 辅助栈——空间换时间
用一个辅助栈保存每个数字x进栈后的值和栈内最小值！相当于保存了每个阶段的状态。<br>
这里学习了一个新知识——元组，使用方法如下：
声明: pair<typeName, typeName> pairName;
查找: pairName.first   pairName.second;
赋值: pairName = {value_1, value_2}。