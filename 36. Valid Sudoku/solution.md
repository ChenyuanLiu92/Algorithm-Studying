# 有效数独
## 1.一遍循环法
要判断一个数独是否为有效数独，则分辨需要满足三个条件：
· 在board上的元素在此行上出现一次；
· 在board上的元素在此列上出现一次；
· 在board上的元素在其所在的盒子中出现过一次；
本题的关键是计算盒子的序号，需要根据i，j进行推到，具体推到结果为j/3 + （i/3）*3。剩下则只需要判断每个元素是否满足条件。可以用三个二维数组作为哈希表，如下：
row[9][10]  col[9][10]  box[9][10]
row表示在第i行中是否存在x元素，后面的序号10表示0-9 10种数字；
col 和 box同理。

## 2.暴力求解法
1. 判断是否行只有其一个
2. 判断列是否只有其一个
3. 判断小盒子是否只有其一个