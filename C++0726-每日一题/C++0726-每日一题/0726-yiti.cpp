/*
数据结构知识点：
1、若某线性表最常见的操作是存取任意指定序号的元素和在最后进行插入和删除的运算，则利用“顺序表”的存储方式最节省时间；
2、“栈”是具有记忆功能的；
3、循环两列房子啊一维数组A[0.....M-1]中，end1指向队头元素，end2指向队尾元素的后一个位置。假设队列两端均可进行入队和出对操作，
队列中最多能容纳M-1个元素。初始时为空，下列判断队空和队满的条件：
			队空：end1 == end2；  队满：end1 == (end2+1)modM
4、对递归程序优化的一般手段是:伪递归优化；
5、将一棵二叉树的根结点放入到队列，然后递归执行如下操作，将出队节点所有子节点加入到队。
			以上操作实现了：层序遍历（一层一层的进行遍历）
6、将两个各有n个元素的有序表归并成一个有序表，最少的比较次数是：n

*/

//找出字符串中第一个只出现一次的字符：
