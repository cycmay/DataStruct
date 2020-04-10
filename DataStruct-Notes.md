# DataStruct-Notes

## 引论

### 数学知识

列出一些需要记住或是能够推导出的基本公式，并且附上基本的证明方法。

#### 指数

![image-20200324141124414](imgs/DS-fig1.png)

#### 对数

在计算机科学中，所有的对数都是以2为底的，除非另有声明。

$X^A=B$ 等价于 $logX_B=A$ .

$log_AB=\frac{log_CB}{log_CA}$, A,B,C>0, A!=1

![image-20200324141943710](imgs/DS-fig2.png)

$log_AB=logA+logB$ 

其他一些有用的公式：

$logA/B=logA-logB$

$log(A^B)=BlogA$

$logX<X$对所有的X>0成立

$log1=0, log2=1, log1024=10, log1048576=20$

#### 级数

最容易记住的公式：

$\sum_{i=0}^N2^i = 2^{N+1}-1$

和

$\sum_{i=0}^NA^i=\frac{A^{N+1}-1}{A-1}$

如果0<A<1, 则有 $\sum_{i=0}^NA^i<=\frac{1}{1-A}$ , 当N趋近于无穷时，该和趋向于$1/(1-A)$

#### 模运算

#### 证明方法

**归纳法证明**

归纳法证明有两个标准的部分，第一步是证明基准情形(base case)，就是确定定理对某个(某些)小的值得正确性；接着，进行归纳假设(inductive hypothesis)，一般来说，这意味着假设定理对直到某个有限数k的所有情况都是成立的；然后使用这个假设来证明定理对下一个值(通常是k+1)也是成立的。至此定理得证(通常k是有限的)。

栗子，证明斐波那契数列，即$F_0=1, F_1=1, F_2=2, F_3=3, F_4=5, … , F_i = F_{i-1} + F_{i-2}$, 满足对i>=1, 有$F_i<(5/3)^i$.

1.  为了证明这个不等式，首先验证定理对平凡情形成立。容易验证$F_1=1<5/3$及$F_2=2<25/9$;这就证明了基准情形。
2.  假设定理对于$i = 1,2,3, … , k$ 成立；这就是归纳假设。
3.  为了证明定理，需要证明$F_{k+1}<(5/3)^{k+1}$。

根据定义有

$F_{k+1}=F_k+F_{k-1}$

将归纳假设用于等号右边，得到

$F_{k+1}<(5/3)^k+(5/3)^{k-1}$

$<(3/5)(5/3)^{k+1}+(3/5)^2(5/3)^{k+1}$

$<(3/5)(5/3)^{k+1}+(9/25)(5/3)^{k+1}$

化简：

$F_{k+1}<(3/5+9/25)(5/3)^{k+1}$

$<(24/25)(5/3)^{k+1}$

$<(5/3)^{k+1}$

定理得证。

**反证法证明**

反证法证明是通过假设定理不成立，然后证明该假设导致某个已知的性质不成立，从而证明原假设是错误的。

### 递归

递归的两个基本法则

1.  基准情形(base cases)。必须总有某些基准的而情形，他们不用递归就能求解。
2.  不断推进(making progress)。对于那些要被递归求解的情形，递归调用必须总能够朝着一个基准情形推进。

## 算法分析

### 数学基础

估计算法资源消耗是一个理论问题，因此需要一套正式的系统架构。先从数学定义开始。

1.  如果存在正整数$c$和$n_0$使得当$N>=n_0$时$T(N)<=cf(N)$, 则记为$T(N)=O(f(N))$
2.  如果存在正整数$c$和$n_0$使得当$N>=n_0$时$T(N)>=cg(N)$, 则记为$T(N) = \Omega(g(N))$
3.  当且仅当$T(N)=O(h(N))$同时$T(N) = \Omega(h(N))$，存在$T(N)=\Theta(h(N))$

例如，当N较小时，1000N要比$N^2$大；但是N=1000是转折点。令$T(N)=1000N$, $f(N)=N^2$, $n_0=1000$, $c=1$，因此我们可以说$1000N=O(N^2)$。

当我们说$T(N)=O(f(N))$时，我们是在保证函数$T(N)$是在以不快于$f(N)$的速度增长，因此$f(N)$是$T(N)$的一个**上界（upper bound）**；令一方面$f(N)=\Omega(T(N))$, 表示$T(N)$是$f(N)$的一个**下界(lower bound)**.

例如，$N^3$增长比$N^2$快，因此$N^2=O(N^3)$或者$N^3=\Omega(N^2)$；$f(N)=N^2$和$g(N)=2N^2$以相同的速率增长，从而$f(N)=O(g(N))$和$f(N)=\Omega(g(N))$都是正确的，即可以用$f(N)=\Theta(g(N))$表示。

几个重要的结论：

1.  如果$T_1(N)=O(f(N))$ 且$T_2(N)=O(g(N))$, 那么

    a. $T_1(N)+T_2(N) = O(f(N)+g(N))$, 非正式表达为$max(O(f(N)), O(g(N)))$

    b. $T_1(N)T_2(N) = O(f(N)g(N))$

2.  如果$T(N)$是一个k次多项式，则$T(N)=\Theta(N^k)$

3.  对任意常数k，$log^{k}N=O(N)$. 更直观的表示出对数增长非常缓慢

常见的函数增长率如下：

| 函数     | 名称       |
| -------- | ---------- |
| $c$      | 常量       |
| $logN$   | 对数       |
| $log^2N$ | 对数的平方 |
| $N$      | 线性       |
| $NlogN$  |            |
| $N^2$    | 二次       |
| $N^3$    | 三次       |
| $2^N$    | 指数       |

### 模型

为了在形式的框架中分析算法，我们需要一个计算模型。

我们的模型基本上是一台标准的计算机，在机器中指令被顺序地执行。该模型有一个标准的简单指令系统，如加法、乘法、比较和赋值等。为了简单起见，模型机做任意一件简单的工作都恰好花费一个时间单位。假设模型机有定长(如32位整数)并且不存在矩阵运算。假设模型机有无限内存。

### 运行时间计算

以计算$\sum_{i=1}^{N}i^3$为例的程序段

```c
int sum(int n)
{
	int partialSum;
    
    partialSum = 0;						// 1
    for(int i = 1; i <= n; i++)			// 2
        partialSum += i * i * i;		// 3
    return partialSum;					// 4
}
```

声明不计时间。

第一行和第四行各占1个单位时间。

第三行每执行一次占用4个单位时间(两个乘法、一次加法和一次赋值)，执行N次占用4N个单位时间。

第二行在初始化i，测试i<=N和i的自增运算开销总计为：初始化消耗1个时间单位，测试消耗（1+N）个时间单位，自增运算消耗N个时间单位，共计2N+2。

我们可以忽略调用方法和返回值的开销，计算出消耗总量是6N+4。因此，本程序是$O(N)$.

事实上，我们没有必要必须做上述详细的步骤计算，由于最终只是给出大Od的结果，因此采取捷径并不影响最后的结果。例如，第三行每次执行时显然是$O(1)$的语句，因此无须讨论到底是2、3还是4个单位时间；另外，第一行与for循环相比无关紧要。

#### 一般法则

1.  for循环。一个for循环的运行时间至多是该for循环内语句的运行时间乘以迭代次数。

2.  嵌套循环。从里向外分析这些循环。在一组嵌套循环内部的一条语句总的运行时间为该语句的运行时间乘以该组多有循环的大小的乘积。

    例如：$O(N^2)$的程序片段

    ```
    for(i=0,i<n;i++)
    	for(j=0;j<n;j++)
    		k++
    ```

3.  顺序语句。将各个语句的运行时间求和即可(一般取运行时间的最大值)。

    例如，下面的程序段先是花费$O(N)$, 接着花费$O(N^2)$，因此总量是$O(N^2)$.

    ```
    for(i=0;i<n;i++)
    	a[i]=0;
    for(i=0;i<n;i++)
    	for(j=0;j<n;j++)
    		a[i]+=a[j]+i+j;
    ```

4.  if/else语句。对于程序片段：

    ```
    if(condition)
    	S1
    else
    	S2
    ```

    一个if/else语句的运行时间不超过判断再加上$S_1$和$S_2$中运行时间较长者的总的运行时间。

#### 算法实例

**最大子序列和问题**    

给定整数$A_1, A_2, … ，A_N$ (有可能存在负数)，求$\sum_{k=i}^{j}A_k$的最大值。(为了方便起见，如果所有整数均为负数，则最大子序列和为0.)

例如：对于输入`-2, 11, -4, 13, -5, -2` 答案为20(从$A_2$到$A_4$).

解法1. 暴力搜索

穷举式地尝试所有的可能：

```cpp
int maxSubSum1(const vector<int> &a)
{
	int maxSum = 0;
    for(int i=0; i<a.size(); i++)
    {   for(int j=i; j<a.size(); j++)
        {
            int thisSum = 0;
            // add i to j
            for(int k=i; k<=j; k++)
                thisSum += a[k];
            // jduge if maxSum occur
            if(thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}
```

粗略分析运行时间为$O(N^3)$, 这取决于第9行和第10行，第10行是三重嵌套for循环的O(1)语句。第9行表示的第二个循环大小为N-i, 可能很小，但也可能取N，我们必须假设最坏的情况。第三个循环大小为$j-i+1$, 我们也要假设它的大小为N。

解法2.改进的暴力搜索

在解法1中，包含着大量不必要的计算。计算$\sum^j_{k=i}A_k = A_j+\sum^{j-1}_{k=i}A_k$, 因此算法中第9行的计算是重复计算耗费时间的。对此改进，将第三层for循环去掉，更改为记录每次j读取到的数值。

```cpp
int maxSubSum1(const vector<int> &a)
{
	int maxSum = 0;
    for(int i=0; i<a.size(); i++)
    {   
        int thisSum = 0;
        for(int j=i; j<a.size(); j++)
        {
           thisSum += a[j]; 
           if(thisSum > maxSum)
               maxSum = thisSum;
        }
    }
    return maxSum;
}
```

算法2显然是$O(N^2)$的。

解法3.采用递归——分治

该方法采用一种"分治"(divide-and-conquer)策略。就是把问题分成两个大致相等的子问题，然后递归地对它们进行求解；在"治"的阶段，将两个子问题的解合并到一起并尽可能的再做少量的附加工作，最后得到整个问题的解。

在本栗子中，最大子序列和可能出现在三个地方：1.整个出现在输入数据的左半部，2.整个出现在数据的右半部，3.跨越输入数据的中部占据两半部分。前两种情况可以使用递归求解，第三种情况可以通过求出前半部分(包含前半部分的最后一个元素)的最大和以及后半部分(包含后半部分的第一个元素)的最大和，并将二者相加而得到，

```cpp
int m_max3(int a, int b, int c);

int maxSumRec(const vector<int> &a, int left, int right)
{
	// base case
	if(left == right)
    {	// 题目指出子序列若全为负数则返回0
		if(a[left]>0)
            return a[left];
        else
            return 0;
    }
    int center = (left + right)/2;
	int maxLeftSum = maxSumRec(a, left, center);
	int maxRightSum = maxSumRec(a, center+1, right);

	int maxLeftBorderSum = 0, leftBorderSum = 0;
	for(int i=center; i>=left; i--)
	{
		leftBorderSum += a[i];
		if(leftBorderSum>maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}	

	int maxRightBorderSum = 0, rightBorderSum = 0;
	for(int i=center+1; i<=right; i++)
	{
		rightBorderSum += a[i];
		if(rightBorderSum>maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}

	return m_max3(maxLeftSum, maxRightSum, maxLeftBorderSum+maxRightBorderSum);

}

int m_max3(int a, int b, int c)
{
	int max = a;

	if(b>max)
		max = b;
	if(c>max)
		max = c;

	return max;
}

```

递归调用的一般形式是传递输入数组以及左右边界，它们界定了数组要被处理的部分。最后，通过单行驱动程序输入原始数组以及0和N-1调用算法。

首先说明基准情况(base-case)，当数组内只有一个元素时(`left==right`)，它就是最大子序列，然而题目指明最大子序列不为全负，所以若为负将其置0；第14行和第15行调用两个递归调用，因为递归总是去解决小于原问题的问题，所以计算center将原始数组分成左右两部分，并重新计算输入参数。两个递归调用可以计算左右两部分最大和；随后计算包含左半部分最后一个元素的最大和以及包含右半部分第一个元素的最大和(即前面叙述的第三种情况)二者相加，这部分就像是动态单向增长；最后通过调用`m_max3`求出上述三种情况最大值，即为本次调用所得最大子序列和。

**运行时间分析**

令$T(N)$是求解大小为N的最大子序列和所花费的时间。如果N=1，则算法执行第8行到第11行花费常数级单位时间，可以计算为O(1)，于是T(1)=1；如果N!=1，程序需执行第18行到第31行的两个for循环，这两个循环需读取N个元素，因此花费时间为O(N)，其余部分执行花费均为常量级，与N相比可以忽略；如果N!=1，程序还需执行两个大小为N/2的子序列问题，即13到15行，因此这三行花费时间为2T(N/2)单位时间。

得到算法总的花费时间为
$$
T(N)=
	\begin{cases}
		1,  & \text{N=1} \\
		2T(N/2)+O(N), & \text{N!=1}
	\end{cases}
$$
这里进行简化求解得到$T(N)=O(NlogN)$.

#### 有关对数时间

可以观察到，分治算法将以O(NlogN)的时间运行，一般的：

如果一个算法用常数时间O(1)将问题的大小削减为其一部分(通常是1/2)，那么该算法就是O(Nlog(N))的。

**二分搜索**

给定一个整数X和整数$A_0, A_1, A_2, …, A_{N-1}$, 后者序列已经预先排序并在内存中，求下标i使得$A_i=X$, 如果X不在数据中，则返回-1.

明显的算法是从左到右顺序扫描数据，花费时间为线性的。然而，这个算法没有用到该表已经排序的事实。另外一个策略是，验证X是否是中间位置元素，若是则找到答案；如果X小于中间元素，那么使用同样的策略用于左半部分已排序的子序列；如果X大于中间元素，那么检查数据的右半部分。当仅剩下一个元素，直接判断即可(base case)。

```cpp
template <typename Comparable>
int binarySearch(const std::vector<Comparable> &a, const Comparable x){
    int low = 0, high = int(a.size()-1);
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid]<x)
            low = mid + 1;
        else if(a[mid]>x)
            high = mid - 1;
        else
            return mid;
    }
    return NOT_FOUND;
}
```

显然，每次迭代在循环内所有工作花费时间为O(1)，因此分析需要确定的循环次数。循环从high-low=N-1开始，并在high-low>=-1结束。每次循环后high-low的值至少将该次循环前的值减半；因此，循环的次数最多为$[log(N-1)]+2$.所以，运行时间总计为$O(logN)$。

**欧几里得算法**

欧几里得算法用来计算最大公因数。两个整数的最大公因数(gcd)是同时整除二者的最大整数。例如gcd(50,15)=5.

对于算法`gcd(M,N)`，假设M>=N. 如果 M<N ，在循环的第一次迭代后会交换二者的值。

```cpp
long gcd(long m, long n){
	while(n!=0){
        long rem = m%n;
        m = n;
        n = rem;
    }
    
	return m;
}
```

算法通过连续计算余数直到余数是0为止。最后的非零余数就是最大公因数。不难看出，在两次迭代后，余数最多是原始值的一半。所以迭代次数最多是2logN = O(logN)

**幂运算**

计算$X^N$的算法是使用$N-1$次乘法自乘。但是使用递归算法会更好，N<=1是递归的基准情况。如果N是偶数，有$X^N=X^{N/2}·X^{N/2}$；如果N是奇数，有$X^N=X^{(N-1)/2}·X^{(N-1)/2}·X$.

例如，计算$X^{62}$:

$X^{62}=(X^{31})^2$, $X^{31}=(X^{15})^2$, $X^{15}=(X^7)^2$, $X^7=(X^3)^2$, $X^3=(X^2)X$

显然，所需要的乘法次数最多是2logN，因为把问题分半最多需要两次乘法

```cpp
long pow(long x, int n){
	if(n==0)
        return 1;
    if(n==1)
        return x;
    if(isEven(n))
        return pow(x * x, n/2);
    else
        return pow(x * x, (n-1)/2) * x;
}
```

## 表、栈和队列

抽象数据类型(abstract data type, ADT) 是带有一组操作的对象的集合。

### 链表 list

形容$A_0,A_1,A_2,A_3, …,A_{N-1}$的链表，表的大小是N。N=0的表为空表(empty list)。除空表外的任何表，称$A_{i-1}$为$A_i$的**前驱**，称$A_{i+1}$为$A_i$的**后继**。

数组可以使得printList以线性时间执行，使得findKth以常数时间执行。然而，数组执行插入和删除花费的时间却很高，因为插入和删除导致元素位置发生变化。最坏的情况下，在位置0处插入一个元素需要将整个数组后移一个位置以空出空间来；而删除第一个元素，需要将表中的所有元素向前移动一个位置，因此这两种操作最坏情况为O(N)。

为了避免插入和删除的线性开销，我们需要允许链表可以不连续存储，否则表的部分或全部需要整体移动。

链表有一系列不必再内存中相连的结点组成。每一个几点均含有表元素和到该元素后继的结点的**链**(link)，称之为next。最后一个单元的next指向NULL。

![image-20200325212122050](DataStruct-Notes.assets/image-20200325212122050.png)

执行printList()或find(x), 我们只需要从链表的第一个结点开始，然后使用next遍历链表即可。与数组一样，这种操作的花费时间是线性的。然而像findKth(i)寻找某个i位置的元素操作花费时间则效率会变低，为O(i)，因为findKth常常按照顺序执行。

remove方法可以通过修改next指向的位置来实现。如删除链表中元素$A_2$.

![image-20200325213133756](DataStruct-Notes.assets/image-20200325213133756.png)

insert方法使用new操作符，从系统申请一个新的结点，并执行两次next调整。如增加新元素X，虚线表示删除原来的链next

![image-20200325213521450](DataStruct-Notes.assets/image-20200325213521450.png)

### STL实现的向量和链表

C++提供一个标准模板库(Standard Template Library, STL). 在STL中，链表ADT的实现由两种——vector和list

vector实现了链表ADT的可增长的数组，使用vector可以在常量的时间里索引某个值。但是它在插入新元素和删除已有元素的代价很高，除非操作发生在vector容器末尾。

list实现了链表ADT的双向链表。如果已知发生变化的元素的具体位置，插入和删除操作代价就非常小。但是list不容易索引某个值。

一般STL容器具备的方法：

-   `int size() const `: 返回容器内元素个数。
-   `void clear()`: 删除容器内所有元素。

-   `bool empty()`: 如果容器没有元素，则返回true，否则返回false。

vector和list都支持在常量的时间内在末尾添加或删除项。支持在常量的时间内访问表的前端和尾端的元素：

-   `void push_back(const Object &x)`: 在容器末尾添加x。
-   `void pop_back()`: 删除容器的末尾的 对象。
-   `const Object & back() const`: 返回容器的尾尾的对象。
-   `const Object & front() const `: 返回容器的前端对象。

双向链表list可以高效的改变链表的前端：

-   `void push_front(const Object &x)`: 在双向链表的前端添加x。
-   `void pop_front()` ：删除双向链表的前端的对象。

vector可以进行高效的索引：

-   `Object & operator[] (int idx)`: 返回vector容器中idx索引位置的对象。
-   `Object & at(int idx)`: 返回vector容器中idx索引位置的对象。
-   `int capacity() const`: 返回vector容器内部容量。
-   `void reserve(int new Capacity)`: 设定vector的新容量。

#### 迭代器 Iterator

STL中的迭代器是用来指明当前循环到容器的索引位置，类似于指针变量。

容器中对iterator定义的方法：

`iterator begin()`: 返回指向容器的第一项的迭代器。

`iterator end()`: 返回指向容器的终止的标志，注意是容器最后一个元素的后继位置，不代表实际元素。看起来就是指向了容器边界以外。

迭代器的方法，假设`iterator itr`：

`itr++, ++itr`: 推进迭代器itr到下一个位置。

`*itr`：返回存储在迭代器itr指向位置的对象的引用。

`itr1==itr2`: 是否二者指向同一个位置，若是则返回true， 否则返回false。

`itr1!=itr2`: 与上同理。

需要迭代器的容器操作：

`iterator insert(iterator pos, const Object &x)`: 添加x到表中迭代器pos所指向位置之前的位置。这对list是常量级操作，但是对vector却不是。返回值是指向插入项位置的迭代器。

`iterator erase(iterator pos)`: 删除pos指向位置的对象元素。这对list是常量级操作，对vector则不是。返回值是调用函数之前pos指向元素的下一个对象元素的位置。

`iterator erase(iterator start, iterator end)`: 删除所有从位置start开始直到位置end(左闭右开，不包括end)的所有元素。

**const_iterator**

`const_iterator`的`operator*`返回常量引用，意味着该类型的迭代器的引用`*itr`不能出现在赋值语句的左边。而且，编译器要求必须使用`const_iterator`来遍历常量集合。

#### vector 向量实现

将重新实现的类模板命名为Vector。

Vector是基本数组的可增长形式，通过一个指针变量来分配的内存块。数组的容量和当前的数组内对象数量存储在Vector里。

Vector实现基本函数——`size()，clear()，back()，pop_back，push_back和empty()`，实现复制构造函数和operator=提供深复制。同时提供析构函数回收数组。

Vector提供resize()函数来改变Vector的大小。提供reserve()函数来改变Vector容量。实现方式为给基本数组分配新的更大的内存块，并将旧内存块的内容复制到新块中，最后释放旧块的内存。

Vector提供operator[]的实现

Vector提供支持嵌套的iterator和const_iterator类型，并提供相关联的begin和end方法。

```cpp
template <typename Object>
class Vector{
public:
    explicit Vector(int initSize = 0):theSize(initSize), theCapacity(initSize +
        SPARE_CAPACITY){
            objects = new Object[theCapacity];
        }
    Vector(const Vector & rhs): objects(NULL){
        operator=(rhs);
    }
    ~Vector(){
        delete[] objects;
    }
    
    const Vector & operator= (const Vector &rhs){
        if(this != rhs){
            delete [] objects;
            theSize = rhs.size();
            theCapacity = rhs.theCapacity;
            
            objects = new Object[capacity()];
            for(int k = 0; k < size(); k++)
                objects[k] = rhs.objects[k];
        }
        
        return *this;
    }
    
    Object & operator[] (int index){
        return objects[index];
    }
    const Object & operator[](int index) const{
        return objects[index];
    }
    
    bool empty(){
        return size()==0;
    }
    
    int resize(int newSize){
        if(newSize > theCapacity)
            reserve(newSize*2+1);
        theSize = newSize;
    }
    
    void reserve(int newCapacity){
        if(newCapacity < theSize)
        {
            return ;
        }
        Object *oldArray = objects;
        objects = new Object[newCapacity];
        for(int k = 0; k < theSize; k++){
            objects[k] = *(oldArray+k);
        }
        theCapacity = newCapacity;
        delete [] oldArray;
    }
    
    int capacity() const {
        return theCapacity;
    }
    
    int size() const {
        return theSize;
    }
    
    void push_back(const Object &x){
        if(theSize == theCapacity)
            reserve(2*theCapacity +1);
        objects[theSize++] = x;
    }
    
    void pop_back(){
        theSize--;
    }
    
    const Object & back() const {
        return objects[theSize-1];
    }
    
    typedef Object * iterator;
    typedef const Object * const_iterator;
    
    iterator begin(){
        return &objects[0];
    }
    const iterator begin() const {
        return &objects[0];
    }
    iterator end(){
        return &objects[size()];
    }
    const iterator end() const{
        return &objects[size()];
    }
    
    enum { SPARE_CAPACITY = 16 };
    
private:
    int theSize = 0;
    int theCapacity = 0;
    Object *objects;
};

```

为了实现一个Vector，在其内部设计了已经存储元素的个数theSize，容器的最大容量theCapacity，基本类型数组objects。

Vector类的默认构造函数参数为用户自定义的存储大小，并将其标识为explicit，表明不可隐式转换。重载了运算符 = ，等同于定义了拷贝构造函数，重新定义类内成员基本数组objects，并拷贝源对象的内容到本对象中，返回this指针。

析构函数释放掉基本数组内存空间。

reserve函数用来扩展/缩小容器容量，前提要保证数据不丢失即数据量不能缩小先保存原基本数组指针，向系统申请新的参数为newcapacity大小的基本数组，并将旧数组元素挨个拷贝到新数组，更新容量大小，最后删除旧的数组。

resize函数重新设定容器内使用范围，如果重新设定的范围超过容器容量，那么扩展至二倍大小。

重载operator[]，可以利用[]来进行数据索引

const修饰返回值和类内成员不可更改来标识常量

将模板类型Object的指针类型重新定义为iterator，标识为迭代器。

使用内置类型iterator和`const_iterator`声明的begin方法和end方法，分别返回类内基本数组首个元素地址和数组有效元素后继的起始地址。

#### list 双向链表实现

由于链表的结点是用户从系统堆heap区申请的内存空间，其数量是不定的，所以不能通过指针来增减指向的位置。设计iterator类，该类抽象了位置的概念，是一个公有的嵌套类。该类存储指向某个结点的指针，且尾部是有效位置，所以应该在末尾增加额外的结点。在表的前端也增加一个结点，在逻辑上表示开始，这样会避免某些特例，极大简化代码。额外的结点被称为哨兵结点，头部的结点称为表头结点(header node)，末端的结点称为尾结点(tail node)。

![image-20200327175249838](DataStruct-Notes.assets/image-20200327175249838.png)

Node类是使用struct声明的，struct是C遗留产物，默认成员为公有；而class默认成员为私有。在List内Node为私有的，外部不能访问之。

```cpp
private:
    struct Node{
        Object data;
        Node *prev;
        Node *next;
        Node(const Object & d = Object(), Node *p = NULL, Node *n = NULL ):
        data(d), prev(p), next(n){}
    };
```

data为结点的数据，prev为指向前驱元素的指针，next为指向后继元素的指针。

Node结构体的构造函数有三个参数，可以定义好三个成员变量。

`iterator`和`const_iterator`区别在于iterator类型的迭代器是可以更改其内部成员的，所以`const_iterator`是基类，`iterator`继承之，重载`*`运算符。

在List类内定义三个数据成员——theSize容器内元素数量，head指向头部结点的指针，tail指向尾部结点的指针。

begin()和end()函数返回迭代器，迭代器的类型是iterator还是const_iterator由声明变量时决定，在定义该函数时，使用const修饰是否改变类内成员即可重载函数类型。返回的迭代器由传入链表表头或表尾元素的指针的构造函数实例化的对象。

**const_iterator类**

```cpp
public:
    class const_iterator{
    public:
        const_iterator(): current(NULL){}
        const Object & operator* () const{
            return retrieve();
        }
        const_iterator & operator++ () {
            current = current->next;
            return *this;
        }
        
        const_iterator operator++ (int){
//            不是通过new 申请heap 后缀运算符先要使用原来的对象，使用完后自加
            const_iterator old = *this;
            // 调用重载过的++运算符
            ++( *this);
            return old;
        }
        
        bool operator== (const const_iterator & rhs) const{
            return current == rhs.current;
        }
        
        bool operator!= (const const_iterator &rhs) const{
            return !(*this==rhs);
        }
        
    protected:
        Node *current;
        
        Object & retrieve() const {
            return current->data;
        }
        const_iterator(Node *p):current(p){}
        
        friend class List<Object>;
    };
```



`const_iterator(Node *p):current(p){}`，这个构造函数是构造指向pNode的迭代器，仅仅在begin和end函数的实现中用到，所以该构造函数不应该被其他外部类访问，所以将其设置为protected成员，只有派生类内才能访问，其他类不允许访问。但是在外部List类begin()和end()成员函数需要访问之，所以声明List类为const_iterator的友元`friend class List<Object>;`，这样外部List就可以访问protected下的构造函数。

current为指向Node类型的指针。是List类用于遍历Node链表的指针，是迭代器指向Node元素的真实指针。

retrieve函数返回当前迭代器指向的Node元素的数据。

const_iterator的公有操作符重载: `==,++,!=,*`，对于++操作符，前缀和后缀是完全不同的，C++通过给前缀形式指定空参数表，后缀形式指定一个匿名int参数来区分。这个int参数永远也不使用，其存在的意义仅仅是给出不同的标识。

`*`解引用，意为读取迭代器指向的元素Object，返回对象的引用，与retrieve()函数一致。

`++`后缀运算符，迭代器Node指针后移一个元素，即current指向next，返回对象的引用。前缀运算符，定义一个局部变量保存旧迭代器的上下文，通过this指针调用后缀自加运算完成指针后移，最后返回旧迭代器的实例，系统会自动回收这类stack区变量。

`==`判断迭代器是否相同，参数为目标迭代器，只需判断二者的实际指针current是否是同一个指针即可。

`!=`调用`==`完成判断。

**iterator类**

继承自const_iterator基类，同样其带参数Node类型指针的构造函数需设置为protected，并声明List类为友元类。

```cpp
class iterator:public const_iterator{
    public:
        iterator(){}
        Object & operator *(){
            return this->retrieve();
        }
        const Object & operator*() const{
            return const_iterator::operator*();
        }
        
        iterator & operator++ (){
            this->current = this->current->next;
            return *this;
        }
        
        iterator & operator-- (){
            this->current = this->current->prev;
            return *this;
        }
        
        iterator operator++ (int){
            iterator old = *this;
            ++(*this);
            return old;
        }
    	iterator operator-- (int){
            iterator old = *this;
            --(*this);
            return old;
        }
        
        
    protected:
        iterator(Node *p):const_iterator(p){}
        friend class List<Object>;
        
    };
```

重载的`*`运算符解引用，返回的引用可以修改其内容。

同时提供const的返回。

其他操作运算符返回类型改变为iterator类型。

**List 类**

类内主要实现构造函数，拷贝构造函数，并通过迭代器完成对链表元素的读取写入等操作。

```cpp
	List(){
        init();
    }
    ~List(){
        clear();
        delete head;
        delete tail;
    }
    List(const List & rhs){
        init();
//        使用重载的=运算符
        *this = rhs;
    }
    
//  const 修饰返回地址不可变
    const List & operator= (const List & rhs){
//        判断地址是否相同来决定是否是同一个对象
        if(this == &rhs){
            return *this;
        }
        clear();
        for(const_iterator it = rhs.begin(); it != rhs.end(); ++it){
            push_back(*it);
        }
        
        return *this;
    }
    
    iterator begin(){
        return iterator(head->next);
    }
    const_iterator begin() const{
        return const_iterator(head->next);
    }
    
    iterator end(){
        return iterator(tail);
    }
    const_iterator end() const{
        return const_iterator(tail);
    }
    
    int size(){
        return theSize;
    }
    bool empty(){
        return size() == 0;
    }
    
    Object & front(){
        return *begin();
    }
    const Object & front() const{
        return *begin();
    }
    Object & back(){
        //        end是界外起始位置 back返回最后一个有效元素
        return *(--end());
    }
    const Object & back() const{
        return *(--end());
    }
    void push_front(const Object & x){
        insert(begin(), x);
    }
    void push_back(const Object & x){
        insert(end(), x);
    }
    void pop_front(){
        erase(begin());
    }
    void pop_back(){
        erase(back());
    }
    iterator insert(iterator it, const Object & x){
        Node *p = it.current;
        theSize++;
        //        插入prev结点的next 即p结点的prev位置
        Node *temp = new Node;
        temp->data = x;
        temp->next = p;
        temp->prev = p->prev;
        p->prev->next = temp;
        p->prev = temp;
        //        浓缩成一句话就是
        //        return iterator(p->prev = p->prev->next = new Node(x, p->prev, p));
        return iterator(temp);
    }
    
    iterator erase(iterator it){
        Node *p = it.current;
        iterator rtnitr(p->next);
        
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        theSize--;
        return rtnitr;
    }
    iterator erase(iterator start, iterator end){
        iterator it;
        for(it = start; it != end;){
            earse(it);
        }
        return it;
    }
    
    void clear(){
        while(!empty()){
            pop_front();
        }
    }
private:
    int theSize;
    Node *head;
    Node *tail;
    
    void init(){
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
    
```

插入元素

![image-20200328171607640](DataStruct-Notes.assets/image-20200328171607640.png)

删除元素

![image-20200328171633826](DataStruct-Notes.assets/image-20200328171633826.png)

### 栈 stack 

栈是限制插入和删除只能在一个位置上执行的链表，该位置在链表的末端，称之为栈顶top。栈的基本操作有push(入栈)和pop(出栈)，前者相当于插入，后者相当于删除最后的元素。另外对空栈不能执行push和pop操作。栈是先进后出(LIFO)的表。

![image-20200328173451899](DataStruct-Notes.assets/image-20200328173451899.png)

**栈的实现**

由于栈是一个表，所以List和Vector都能实现栈。栈的操作都是常量级操作，基本上不会有优化。

通常pop和push操作在机器指令存在，所以栈可以说是机器上一种最基本的数据结构

**栈的应用**

检验符号是否成对出现

将栈置空，读入字符直到文件结束。如果字符是一个开放符号(符号开始部分)，将其压入栈中。如果字符是一个封闭符号(符号结束那一半)，如果栈为空则报错；栈不空弹出顶端元素，判断是否为对应开放符号，若不是则报错。重复操作直到文件尾。

**后缀表达式**

![image-20200328175128308](DataStruct-Notes.assets/image-20200328175128308.png)

类似于这种表达式，称为后缀(postfix)或逆波兰(reserve Polish notation)表达式。

算法流程为 使用一个栈，当遇到一个数时，就把它压入栈中；遇到操作符时，将该操作符作用于弹出的两个数上，并将结果压入栈中。直到最后只有一个数将其输出。

中缀转换为后缀

当读到一个操作数后，立即将它放到输出

如果遇到一个右括号，将栈的元素弹出，直到一个对应的左括号，注意左括号不输出

其他符号，从栈顶弹出元素，直到发现优先级更低的元素。+的优先级最低，(的优先级最高，同时除了右括号其他情况都不能弹出(。当元素都弹出后，将他们按照弹出顺序写入输出。最后将该符号压入栈。

当读到末尾，将所有元素弹出，写入输出。

核心思想是：当遇到一个操作符时，把它放到栈中，栈表示的是挂起的操作符。然而，当栈中高优先级的操作符完成使用时，则应弹出它们。判断是否完成使用，就是遇到的操作符级别低于栈顶的那部分操作符，表示高级操作已经完成了。

**函数调用**

函数调用和函数返回类似于开括号和闭括号，当存在函数调用时，需要存储的信息，例如寄存器的值和返回地址等以抽象的方式存在于堆(pile)的顶部。随后，控制转移到新的函数，该函数自由控制寄存器等。如果新函数继续调用其他函数，则执行相同的过程。函数返回时，它检查堆顶部的信息，并将寄存器复原，进行返回转移。

所存储的信息称为活动记录(activation record)，或称为帧栈(stack frame). 

### 队列 queue

跟栈一样，队列也是表。然而，队列的插入在一端，删除则是在另外一端。

**队列模型**

队列的基本操作是入队（enqueue）和出队（dequeue）。入队是在标的队尾插入一个元素，出队则是删除并返回表开头的元素。

![image-20200328201926674](DataStruct-Notes.assets/image-20200328201926674.png)

实现方法：

保留一个数组theArray，以及位置front和back分别代表队列的两端。设置currentSize记录实际存在于队列中元素的个数。

![image-20200328202407057](DataStruct-Notes.assets/image-20200328202407057.png)

对于操作。enqueue操作，先将currentSize和back自增1，然后置theArray[back]为x。dequeue操作，置返回值为theArray[front]，并将currentSize自减1，front自增1.

对于一定长度的数组，可能在多次操作后两个指针都移动到了 界。这是可以使用循环数组(circular array)

**队列的应用**

打印机文件排队

## 树

对于大量的数据，链表的线性访问时间太长，然而树（tree）结构的操作运行时间则平均为O(logN)

通过递归的方法定义树(tree)，一棵树是一些结点的集合，这个集合可以是空集；若不是空集，则树由根(root)的结点r以及零个或多个非空的子树组成，这些子树中每一颗的根都被来自根r的一条有向边(edge)所连接。

每一颗子树的根结点叫做root结点的孩子(child)，而root结点是每一颗子树的根结点的父亲(parent)。

![image-20200329154633756](DataStruct-Notes.assets/image-20200329154633756.png)

![image-20200329154846941](DataStruct-Notes.assets/image-20200329154846941.png)

如上图所示结点A是root根结点，没有孩子的结点称为叶子结点(leaf)如I、P、Q等。具有相同父结点的结点称为兄弟结点(sibling)，如K、L、M同属于F，I、J同属于E。

连接结点之间的线称为边(edge)。从结点$n_1到n_k$的一个序列定义为路径(path)。

对任意结点$n_i$，从根结点到$n_i$的唯一路径的长，称为深度(depth)；从$n_i$到一片叶子结点**最长路径**的长称为高(height)。一颗树的高等于它的根结点的高。

### 实现

一般将树结点的数据结构设计成一个结点包含数据元素和指向兄弟结点的指针。

### 二叉树

二叉树（binary tree) 定义为一棵每个结点都不能有多于两个孩子结点的树。

![image-20200329161825224](DataStruct-Notes.assets/image-20200329161825224.png)

二叉树的一个性质是平均深度要比结点个数N小得多，为$O(\sqrt{N})$.

**实现**

由元素element和两个孩子结点的引用的结构组成

```
template <typename Object>
struct BinaryNode{
    Object element;
    BinaryNode * left;
    BinaryNode * right;
};
```

**应用**

表达式树(expression tree)

![image-20200329163131245](DataStruct-Notes.assets/image-20200329163131245.png)

表达式树的叶子结点是操作数（operand），其他结点为操作符(operator)。上图所示的表示的是`(a+(b*c))+(((d*e)+f)*g)`

计算法这种表达式结果的方法有中序遍历(inorder traversal)，即通过递归产生带括号的左表达式，然后访问根处的操作符，最后递归产生带括号的右表达式。

同理的还有后序遍历(postorder traversal)，前序遍历(preorder traversal).

**由后缀表达式构建二叉的表达式树**

假设输入`ab+cde+**`

算法思路，类似于后缀表达式求值，将符号读入，如果符号是 操作数，建立一个单结点的树，并将其压入栈中；如果符号是操作符，从栈中弹出两个子树$T_2和T_1$, 形成一个新的树，该树的根就是操作符，它的左右孩子结点分别是$T_1$和$T_2$，然后将指向这棵新树的指针压入栈中。最后栈中只存在一个树的根结点。

### 二叉查找树

二叉树的一个重要应用就是它在查找中的应用。二叉查找树的性质是，对于树中的每个结点X，它的左子树的所有项的值小于X，而它的右子树中所有项的值大于X。

二叉查找树的平均深度是O(logN)，不必担心栈空间耗尽。

查找基于`<`操作符，该操作符必须在元素类内定义。

#### **接口**

```cpp
template <typename Comparable>
class BinarySearchTree {
private:
    struct BinaryNode{
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;
        
        BinaryNode(const Comparable & theElement, BinaryNode *lf,
                   BinaryNode *rt):element(theElement), left(lf), right(rt){}
    };
    BinaryNode *root;
    
    void insert(const Comparable & x, BinaryNode * & t) const;
    void remove(const Comparable & x, BinaryNode * & t) const;
    BinaryNode * findMin(BinaryNode * t) const;
    BinaryNode * findMax(BinaryNode * t) const;
    bool contains(const Comparable & x, BinaryNode * t) const;
    void makeEmpty(BinaryNode * & t);
    void printTree(BinaryNode * t) const;
    BinaryNode * clone(BinaryNode * t) const;
    
public:
    BinarySearchTree();
    ~BinarySearchTree();
    BinarySearchTree(const BinarySearchTree & rhs);
    
    const Comparable & findMin() const;
    const Comparable & findMax() const;
    bool contains(const Comparable & x) const;
    bool isEmpty() const;
    void printTree() const;
    
    void makeEmpty();
    void insert(const Comparable & x);
    void remove(const Comparable & x);
    
    const BinarySearchTree & operator=(const BinarySearchTree & rhs);
    
    
};

```

在接口中声明了默认构造函数、拷贝构造函数，以及是否存在某个元素、查找最大最小元素，还有插入删除数据等。

#### 是否存在

```cpp
//类内部接口 contains< x, t>
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable & x, BinaryNode *t) const{
//    判断树中是否含有元素值为x的结点
    if(t == NULL){
        return false;
    }
    else if(x < t->element){
//      若树的根结点t的元素值大于x，则去左子树递归查询是否contains
        return contains(x, t->left);
    
    }
    else if(x > t->element){
//      若树的根结点t的元素值小于x，则去右子树递归查询是否contains
        return contains(x, t->right);
    }
    else
//        若相等，则返回true
        return true;
}

// 公共接口 contains
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable &x) const{
//   从根结点root处调用contains函数
    return contains(x, root);
}

```

这里进行了子树的递归调用。

#### 查找最大最小

最小的元素在最左侧结点，所以一直在左子树递归调用，直到NULL为止。或者使用循环的方式，一直迭代到最左侧即做孩子为NULL的。

```cpp
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *
BinarySearchTree<Comparable>::findMin(BinaryNode * t) const{
    if(t == NULL)
        return NULL;
    if(t->left == NULL)
        return t;
    return findMin(t->left);
    
    ////        或者使用循环的方式
    //#if 0
    //        if(t != NULL)
    //            while(t->left!=NULL)
    //                t = t->left;
    //        return t;
    //#endif
    
}

template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *
BinarySearchTree<Comparable>::findMax(BinaryNode * t) const {
    if(t == NULL)
        return NULL;
    if(t->right == NULL)
        return t;
    return findMax(t->right);
}

```

#### insert 插入

为了将x插入到树T中，可以像contains一样，沿着树进行查找，如果找到x则do nothing；否则将x插入到遍历到的路径上的最后一个结点。

```cpp
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x,
                                            BinaryNode * & t) const{
    if(t == NULL)
        t = new BinaryNode(x, NULL, NULL);
    if(x < t->element)
        insert(x, t->left);
    if(x > t->element)
        insert(x, t->right);
    else
        return;
}

```

#### remove 删除

在一般的数据结构中，删除操作一般是比较复杂的，因为它要考虑几种可能的情况。

如果结点是一片叶子结点，那么它可以立即删除。

如果结点有一个孩子结点，那么在其父结点调整它的链。如删除4结点，而4结点有一个孩子结点3：

![image-20200331090715762](DataStruct-Notes.assets/image-20200331090715762.png)

如果结点有两个孩子结点，一般的策略是用右子树的最小结点的数据交换该结点的数据，并递归地删除该结点(交换后该结点必然不包含左子树，因为已经是最小结点的位置)。

![image-20200331092203268](DataStruct-Notes.assets/image-20200331092203268.png)

如删除2结点，将其与右子树最小结点3交换，随后删除其在3号位置的结点，此时执行删除只有一个子结点的函数。

#### 删除树

私有的makeEmpty()函数递归地处理t的子树，对t执行delete。最后root置NULL。

```cpp
template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode * & t){
    if(t == NULL)
        return;
    else{
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
//    将t置空
    t = NULL;
}
//公共接口
template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(){
    makeEmpty(root);
}
```



#### 克隆树

对于NULL，直接返回NULL；

创建一个新结点，并将rhs的值拷贝到新结点。对于子树，克隆左右孩子树到自己的左右孩子。

```cpp
//deep copy
template <typename Comparable>
const BinarySearchTree<Comparable> & BinarySearchTree<Comparable>::operator=
    (const BinarySearchTree & rhs){
//    删除原来的树
        makeEmpty();
        root = clone(rhs);
        return *this;
}

// clone a subtree
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *
BinarySearchTree<Comparable>::clone(BinaryNode * t) const{
    if(t == NULL)
        return NULL;
    BinaryNode * temp = new BinaryNode;
    temp->element = t->element;
    temp->left = clone(t->left);
    temp->right = clone(t->right);
    return temp;
}

```

同样的重载=运算符，对参数进行拷贝。

### AVL树

AVL(Adelson-Velskii and Landis)树是带有平衡条件(balance condition)的二叉查找树。平衡条件，保证树的深度是O(logN)，最简单的想法是要求左右子树具有相同的高度，甚至要求每个结点必须有相同高度的左子树和右子树。后者虽然保证了树的深度足够小，但是难以实现以及使用。

一颗AVL树是其每个结点的左子树和右子树的高度最多差1的二叉查找树(空树的高度为-1)，在每个结点上保留高度信息。

插入一个结点可能破坏AVL树的特性(例如插入某个结点后高度发生变化，破坏了差1的平衡性)，这时可以通过对树的修正，称之为旋转(rotation)。

插入结点后，从插入点到根结点的路径上的结点的平衡性可能发生改变，因为只有这些结点的子树可能发生变化。在这条路径上，存在一个必须平衡的结点a，由于任意结点最多有两个孩子结点，高度不平衡时，a结点的两棵子树高度差2.



#### 单旋转

single rotation

对a的左孩子结点的左子树插入

![image-20200403125957994](DataStruct-Notes.assets/image-20200403125957994.png)

结点$k_2$不满足AVL平衡性质，因为它的左子树比右子树深2层，图中虚线表示树的各层。新增的结点在X子树，它比子树Z深出2层。

为了恢复平衡，把X上移一层，并把Z下移一层。k1变成了新的根，依据原树的关系，k2应该放在k1右子树；子树Y包含原树中介于k1和k2之间的结点，可以将它放在新树k2的左子树。新生成的树是一颗AVL树，且高度不影响上层树。

#### 双旋转

对a的左孩子结点的右子树或者a的右孩子结点的左子树进行插入

使用单旋转算法产生问题：子树Y在单旋转后并没有减低它的深度

![image-20200403133155076](DataStruct-Notes.assets/image-20200403133155076.png)

假设Y中某一个子树B或者C比D深两层，在整颗树中无论单旋k1或者k3都不能降低k2的高度差，此时重新选择k2作为树的根结点，调整k1，k3分别称为它的子结点，这样ABCD四棵树都确定了位置，冰鞋满足AVL性质。

### B/B+树

假如数据量大到计算机内存不足以存放之，那就意味着必须存放之到磁盘上。

然而磁盘的I/O操作速度取决于磁盘的机械运动速度，即磁盘转速和磁头移动速度。一般的磁盘旋转速度为7200RPM，即7200转/min，也就是1转占用1/120s，约合8.3ms，平均认为磁盘转到1半就能找到信息。但是CPU的速度是惊人的，执行400w条指令对应一次磁盘访问，显然是不匹配的。因此，磁盘的访问代价是极其昂贵的。

假如有一份数据，共计1000w项，键占用空间为32字节，记录占用空间为256字节。CPU和磁盘资源为：1s内执行100w次指令，或者执行6次磁盘访问。

如果使用二叉查找树存储数据，在最糟糕的情况下，可能需要1000w次磁盘访问；即使采用平均值1.38logN次，计算出平均查找一次记录需要32次磁盘访问或者说需要5s的时间。如何将访问次数降低到最小呢？

试着使用更多叉的树，即一颗M叉查找树(M-ary search tree). 一颗完全M叉树的高度大约是$log_MN$

为了保证M叉树的平衡条件，就使用到了B+树。

阶为M的B+树是一棵具有以下结构特性的树：

1.  数据项存储在叶子结点上
2.  非叶结点存在至多M-1个键，以指示搜索的方向；键i代表子树i+1中的最小的键。
3.  树的根要么没有孩子结点，要么孩子结点个数在2-M。
4.  除了树的根，所有非叶子结点的孩子结点个数在|-M/2-|到M之间。
5.  所有叶子结点都在相同的深度上，并有|-L/2-|到L之间的数据项。

例如5阶B树：

![image-20200403203307998](DataStruct-Notes.assets/image-20200403203307998.png)

所有非叶结点的子结点个数都在3到5之间(从而有2到4个键)，根的子结点个数则为2到5之间。

每个结点代表一个磁盘区块，于是根据所存储项的大小来选择L和M。

假设一个区块存储容量为8192Bytes。存储10^7份记录(键占用32B，记录占用256B)。

在M阶的B+树中，每个非叶结点至多存在M-1个键，占用空间为`4*(M-1)B`，指向的M结点使用指针存储占用`4B*M`，所以一个非叶节点占用空间为`(36M-32)Bytes`。计算不超过区块存储容量的最大M为228.

在叶子结点上，每个记录占用256B，计算的一个区块最多存放L=32个记录。

由于平衡性性质，每个非叶子结点最少有M/2个分支，同时10^7份记录存储在10^7/32=625000个叶子结点。最坏的访问次数有公式$log_{M/2}N$，大约为3-4次磁盘访问。

**插入数据**

1.  插入后叶子结点不满。特别简单，直接加入即可。

    ![image-20200403210421119](DataStruct-Notes.assets/image-20200403210421119.png)

2.  插入后叶子结点满，父结点键不满。将其一分为二，二者都会有满足最小的L/2个数据记录。

    ![image-20200403210520789](DataStruct-Notes.assets/image-20200403210520789.png)

3.  插入后叶子结点满，父结点键也满。子执行分裂后，父再执行分裂

    ![image-20200403210952557](DataStruct-Notes.assets/image-20200403210952557.png)

4.  依次类推，当根节点也需要分裂时，不可能同时出现两个根节点，这时只需要分裂后的两个根节点重新定义一个父结点，并将此父结点作为该树的根节点root即可。这也就是为什么B树允许根结点的最少孩子结点个数为2.

**删除数据**

通过查找要被删除的项，并执行删除操作。如果被删除的项所在叶子结点的数据项数已经最小，从而删除之后导致叶子结点的项数低于约定的最小值。这时可以从邻结点领养一个项作为子结点，如果邻结点已经是最小值，那么可以与该结点联合成一片满叶，如果联合导致父结点的子结点数低于约定最小值，使用本策略继续进行，直到根，根最少可以有两个子结点，两个子结点可以联合成新的根节点。

![image-20200404100217383](DataStruct-Notes.assets/image-20200404100217383.png)

### STL中的set和map

标准库中这两个容器的基本操作(插入、删除和查找)时间开销为logN

#### set

set是排序后的容器，容器内元素不允许重复。set的成员方法包括begin、end、size、empty

set特有的操作时高效的插入、删除和执行查找。

由于set内元素不允许重复，所以insert可能失败，所以该方法的返回值类型应为布尔变量。然而查找到互斥的元素后，应将其位置iterator返回以便删除，从而避免查找操作。所以返回值类型的数据结构较复杂。

STL定义了一个pair的模板类，该类有两个用来访问成员的first和second。

`pair<iterator, bool> insert(const Object & x);`

`pair<iterator, bool> insert(iterator it, const Object & x);`



#### map

map存储排序后由键和值组成的项的集合。键必须唯一，多个键可以对应同一个值。

对于map的迭代器iterator是pair<KeyType, ValueType>类型。

map可以通过[]操作符重载实现查找索引。

`ValueType & operator[](const KeyType & key);`

如果在map中存在key，就返回指向相应的值的引用。如果在map中不存在该key，就插入一个默认值。如果map通过常量引用，那么operator[]就不该使用。



#### **set和map的实现**

C++中set和map支持在最坏的情况下对基本的操作insert、erase和find仅仅消耗对数时间。相应的，其底层实现是平衡二叉查找树。典型的不是使用AVL树，而是使用红黑树。

为了在容器set和map中提供对迭代器类的支持，如何保证高效地推进迭代器至下一个结点。

每个结点保持额外链接：向前至较小结点，向后至较大结点。仅仅为那些左侧或者右侧邻接点为NULL保持额外链接，并在节点内使用布尔变量指示是否有左右链接。这种思想称为线索树(threaded tree).

## 散列

散列是一种用于常数时间内执行插入、删除和查找的技术，但是不支持元素键排序操作。

### 思想

散列的数据结构是一个包含一些项的固定大小的数组。

将每个键映射到0至TableSize-1范围中的某个单元，这个映射就被成为散列函数。理想情况下，散列函数应该运算简单并且能够保证任何不同的两个键映射不到同一个单元，并且所有的键应该被均匀分配。

如果两个键散列到同一个值，称为冲突(collision)。

### 散列函数

简单的有模运算法，保证表的大小是素数，当输入的键是随机整数时，散列函数会简单，而且键的分配也会均匀。

### 冲突

分离链接法(separate chaining)

![image-20200404205123411](DataStruct-Notes.assets/image-20200404205123411.png)

TODO：

​	一些不常用的不常见的知识点。



## 优先队列

优先队列是至少允许以下两种数据操作：insert(插入)；deleteMin(删除最小项)。

insert操作等价于入队(enqueue)，而deleteMin则是队列操作中出队(dequeue

**模型**

![image-20200404210756937](DataStruct-Notes.assets/image-20200404210756937.png)



### 简单实现

简单链表以O(1)执行插入操作，O(N)遍历该链表以删除最小元素。

另外使用二叉查找树，两种操作都会是O(logN)。但是删除操作删除的是最小元的结点，这会导致右子树加重，导致树的不平衡性。

### 二叉堆

二叉堆(binary heap)，与二叉查找树一样，堆也有两个性质，即结构性质和堆序性质。

#### 结构性质

堆是一棵完全二叉树（complete binary tree），除了底层元素从左向右填入，其他都被完全填满的二叉树。

因为完全二叉树的规律，所以它可以用数组表示，而不用链表。

![image-20200405152820324](DataStruct-Notes.assets/image-20200405152820324.png)

对于数组中任一位置i上的元素，其左子结点在位置2i上，右子结点在(2i+1)上，其父结点在└i/2┘。所以遍历该树操作简单，

#### 堆序性质

最小元应该在根上，且任意子树也是堆。

### 基本堆操作

#### insert

在将元素x插入堆中，在完全二叉树空闲位置创建一个空穴。将x放入空穴，若不满足堆序，则交换父结点，并向根的方向继续进行，直到找到放置x的正确位置。

![image-20200405215249045](DataStruct-Notes.assets/image-20200405215249045.png)

向上浮动x的策略称为上虑(percolate up).

```cpp
// insert item x allowing duplicates
template <typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable &x){
    if(currentSize == array.size() - 1)
        array.resize(array.size() * 2);
    
    // percolate up
    int hole = ++currentSize;
    for(; hole > 1 && x < array[hole/2]; hole /= 2)
        array[hole] = array[hole/2];
    array[hole] = x;
}
```



#### deleteMin

先找到最小元，然后删除之。在根结点建立空穴。将空穴的两个子结点比较，较小者与空穴互换，这样就把空穴向下推进一层，重复该步骤，直到最后一个元素放进空穴。

![image-20200405215937753](DataStruct-Notes.assets/image-20200405215937753.png)

```cpp
// remove the minimum item
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin(){
    if(empty())
        return;
    // 将最后一个结点的值赋予root结点 同时最后一个指针自减
    array[1] =  array[currentSize--];
    // 将root结点的值下滤
    percolateDown(1);

}

// Internal method to percolate down in the heap
// hole is the index at which the percolate begin
template <typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole){
    int child;
    Comparable temp = array[hole];
    // 迭代直到没有子结点
    for(; hole*2 <= currentSize; hole = child){
        child = hole*2;
        // 选定两个孩子结点较小的一个
        if(child != currentSize && array[child+1]<array[child])
            child++;
        // 若孩子结点比hole结点更小 交换之 
        if(array[child]<temp)
            array[hole] = array[child];
        else
            break;
    }
    array[hole] = temp;
}
```

deleteMin操作的最坏运行时间为O(logN)，因为绝大多数的元素从根处下滤到叶子结点。

#### buildHeap

通过函数的参数项的一个序列来构造堆，首先将N项以任意顺序放入树中，保持结构特性，随后对每个非叶结点使用下滤策略生成一颗堆序树。

```cpp
// Establish heap order property from an arbitary arrangement of items.
template <typename Comparable>
void BinaryHeap<Comparable>::buildHeap(){
    for(int i = currentSize/2; i >0;  --i)
    // currentsize / 2 是当前二叉堆完全二叉树的最后一个非叶子结点
        percolateDown(i);
}

// contractor function
template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(const Vector<Comparable> & items):
    currentSize(items.size()), array(items.size()+1){
    // insert items
    // 二叉数组的第一个元素没有实际意义 故加1
    for(int i = 0; i < items.size();  ++i)
        array[i+1] = items[i];
    // build heap
    buildHeap();
}
```

建立N个元素的二叉堆的基本方法花费O(N)时间。

## 排序算法

假设算法中:

-   元素都是可以互换的
-   程序中元素个数为N
-   存在">, <"操作符

在这些条件下的排序称为基于比较的排序(comparison-based sorting)

STL中，排序通过使用函数sort完成

`void sort(Iterator begin, Iterator end);`

`void sort(Iterator begin, Iterator end, Comparator cmp);`

sort算法不能保证相等的项保持它们原始的相对次序(可以用stable_sort代替)

`sort(v.begin(), v.end());` 将整个容器v按照非降序排列。

`sort(v.begin(), v.end(), greater<int>());` 将整个容器按非升序排列。

`sort(v.begin(), (v.end()-v.begin())/2)`将容器的前半部分按非降序排列



### 插入排序

insertion sort最简单的排序算法之一。排序过程由N-1趟(pass)完成。

对于从p到N-1趟（p初始值为1），保证从位置0到位置p上的元素都已经是排序好的状态。

过程实例如下：

![image-20200407090408507](DataStruct-Notes.assets/image-20200407090408507.png)

在第p趟，将位置p上的元素向左移动到它之前p个元素中正确的位置。

```cpp
template <typename Comparable>
void insertionSort(Vector<Comparable> &a){
    int j;
    for(int p = 1; p < a.size(); ++p){
        Comparable temp = a[p];
        for(j = p; temp<a[j-1] && j>0 ; --j){
            // 从p位置向前遍历，移动前一项元素到后一项，直到遍历到迭代器指向的位置前一项不
            // 再大于原p位置的元素值，即找到了p位置元素的合适位置
            a[j] = a[j-1];
        }
        // 将p位置的元素放到适合位置j
        a[j] = temp;
    }
}
```

**分析**

对于每一个p值，嵌套内代码最多执行p+1次，对所有p求和:

得到总数

$\sum_{i=2}^{N}i =  2 + 3 + 4+…+N = \Theta(N^2)$

如果输入数据几乎已经排序，嵌套内判断立即终止，那么运行时间为O(N)。

**定理**：通过交换相邻元素进行排序的任何算法平均时间为$\Omega(N^2)$.

### 希尔排序

希尔排序(shellsort)源自于其发明者Donald shell，该算法是打破二次时间屏障的第一批算法之一。

它通过比较相距一定间隔的元素进行比较，各趟比较的距离随算法进行而减小，直到比较相邻元素的最后一趟排序为止。因此希尔排序也称缩减增量排序(diminishing increment sort)。

希尔排序使用一个增量序列(increment sequence)，一般是素数序列。在一趟排序（对每个子数组执行一次插入排序）后，所有相隔hk元素被排序。

![image-20200407202352620](DataStruct-Notes.assets/image-20200407202352620.png)

使用希尔增量时希尔排序的最坏情形运行时间为$\Theta(N^2)$，

```cpp
// 希尔排序
template <typename Comparable>
void shellSort(Vector<Comparable> &a){
    for(int gap = a.size() / 2; gap>0; gap /=2){
        // 希尔增量序列 gap 
        for(int i = gap; i < a.size(); ++i){
            // 分组 对每一组进行插入排序
            Comparable temp = a[i];
            int j = i;
            for(; j >= gap && temp < a[j-gap]; j -= gap)
                a[j] = a[j-gap];
            a[j] = temp;
        }
    }
}
```

使用Hibbard增量的希尔排序的最坏情形运行时间为$\Theta(N^{3/2})$

### 堆排序

优先队列可以以O(NlogN)时间进行排序。

建立N个元素的二叉堆花费O(N)的时间，执行N次deleteMin操作以获取最小元素花费O(NlogN)时间。获取到最小元素后将其记录到第二个数组然后拷贝回原数组，因此存储空间多消耗了一倍。可以巧妙地在deleteMin操作后，将item保存到参数后的位置上，最终得到递减顺序的序列。若想要得到递增顺序的序列，增加deleteMax方法即可。

```CPP
template <typename Comparable>
void heapsort(Vector<Comparable> & a){
    // build heap
    for(int i = a.size()/2; i>=0; --i)
        percolateDown(a, i, a.size());
    // sort // delet max
    for(int j = a.size()-1; j>0 ; --j){
        // swap 0,j
        Comparable temp = a[0];
        a[0] = a[j];
        a[j] = temp;
        // 将顶部的元素下滤
        percolateDown(a, 0, j);
    }
        
}


/* 
 * @Description: 二叉堆中的下滤策略 
 * @param a: 容器Vector
 * @param i: 下滤的元素位置 从0开始
 * @param n: 结点个数 
 * @return: 
*/ 
template <typename Comparable>
void percolateDown(Vector<Comparable> & a, int i, int n){
    int child; // 子结点
    Comparable temp;
    // 在源Vector中元素索引下标从0位置开始 i位置元素的孩子结点位置为2*i+1
    for(temp = a[i]; 2*i+1 < n; i = child){
        child = i * 2 + 1;
        // 找到两个子结点中较大的一个
        // 必须要判断是否还存在邻结点
        if(child != n-1 && a[child] < a[child+1])
            child++;
        //  将较小的元素向下滤
        if(temp < a[child])
            a[i] = a[child];
        else 
            break;
    }
    a[i] = temp;
}
```

**分析**

对N个互异项的随机排列进行堆排序，所用的比较平均次数为2NlogN-O(Nlog logN).





### 归并排序

归并排序(mergesort)，以O(NlogN)时间运行，使用递归。

基本算法是合并两个已经排序的表。将A、B数组合并到C数组中，需要三个计数器(Actr、Bctr和Cctr)。将三个极计数器放置在对应数组的起始位置，比较A和B的较小者被复制到C的位置，并迭代一次，当一个表的指针指向末尾，将另一个表的所有元素复制到C即可。

![image-20200408233127615](DataStruct-Notes.assets/image-20200408233127615.png)

![image-20200408233142580](DataStruct-Notes.assets/image-20200408233142580.png)

合并两个已排序的表的时间是线性的。最多进行了N-1次比较。因为每次比较完都会放一个元素到C，最后一次却会添加两个元素，所以最多比较N-1.

算法描述：如果N=1，那么只有一个元素直接放到C；否则，递归的归并前半部分数据和后半部分数组，得到归并好的两个数组，使用上述方法合并到一起。

```cpp
template <typename Comparable>
void mergeSort(Vector<Comparable> &a){
    Vector<Comparable> tempArray(a.size());
    mergeSort(a, tempArray, 0, a.size()-1);
}

template <typename Comparable>
void mergeSort(Vector<Comparable> &a,
                Vector<Comparable> & tempArray, int left, int right){
    if(left < right){
        int center = (left + right) /2;
        mergeSort(a, tempArray, left, center);
        mergeSort(a, tempArray, center+1, right);
        merge(a, tempArray, left, center+1, right);
    }
}

/* 
 * @Description: 将一个前后两半部分已排好序的数组合并为一个完整排好序的数组
 * @param a: 源数组
 * @param tempArray: place the merge result. 
 * @param leftpos: left-most index of the subarray. 
 * @param rightpos: the start of the second half.
 * @param rightend: the right-most index of the subarray. 
 * @return: 
*/ 
template <typename Comparable>
void merge(Vector<Comparable> & a, Vector<Comparable> & tempArray, int leftpos,
            int rightpos, int rightend){
    int leftend = rightpos - 1;
    int temppos = leftpos;
    int numElements = rightend - leftpos + 1;

    // main loop
    while(leftpos <= leftend && rightpos <= rightend){
        if(a[leftpos] <= a[rightpos])
            tempArray[temppos++] = a[leftpos++];
        else
            tempArray[temppos++] = a[rightpos++];
    }

    // 将剩余序列全部复制到结果中
    while(leftpos <= leftend){
        tempArray[temppos++] = a[leftpos++];
    }
    while(rightpos <= rightend){
        tempArray[temppos++] = a[rightpos++];
    }

    // copy tempArray back to a
    for(int i = 0; i < numElements; ++i, rightend--)
        a[rightend] = tempArray[rightend];
}
```

在递归调用中并不创建临时的数组，而是传入最开始创建的数组，这样任意时刻就不是有logN个临时数组存在，而是只需要一个临时数组活动。

**分析**

对运行时间进行递推关系。

对于N=1，归并排序使用常数时间；

其他的对N个数用时等于完成两个大小为N/2的递归排序，再加上合并的时间(线性时间)。

$T(1) = 1$

$T(N) = 2T(N/2) + N$

等式两边同时除以N，

![image-20200409110455051](DataStruct-Notes.assets/image-20200409110455051.png)

将等式叠加得到：

$T(N)/N = T(1)/1 + logN$

所以有$T(N) = NlogN + N = O(NlogN)$

整个算法中还要花费时间将数据复制到临时数组，这样严重减慢了排序的速度。在java中，元素比较耗时多于移动元素，所以流行使用归并排序；而在c++中，复制对象的代价大于对象的比较。

### 快速排序

快速排序(quicksort)是实践中最快的已知排序算法，它的平均运行时间为O(NlogN)。

快排最坏情形下耗时$O(N^{2})$，使用堆排序和快排结合，就可以优化为O(NlogN)。

快速排序也是一种分治的递归算法。假设源数组为S其步骤如下：

1.  如果S中元素个数为0或1，返回。
2.  取S中任意一个元素v作为枢纽元(pivot)
3.  将S-{v}(S中剩余元素)划分为两个不相交的集合：$S_1= \{ x \in S - \{v\}  | x<= v \}$ 和 $S_2= \{ x \in S - \{v\}  | x>= v \}$ 
4.  返回{quicksort(S1)}, v ,以及quicksort(S2)

一般的，像二叉查找树一样，我们选择中间元素作为枢纽元，划分左右各一半大小的序列。

快速排序的高效性体现在第三步，在适当位置进行。

#### 选取枢纽元

1 选取第一个元素作为枢纽元，如果输入序列是预排序的或者反序的，这样的枢纽元产生单向分割，这样快速排序花费了原本不必要的时间。

2 随机选取，相对来说比较安全，但是生产随机数是昂贵操作，因此不可取。

3 选取序列首尾和中间值三者中的中值，这样确实会节省比较次数。

#### 分割策略

第一步是将枢纽元与最后的元素交换使其与要被分割的数据段分离。设置两个指针i和j，i指向第一个元素并向后移动，j指向倒数第二个元素，向前移动。

![image-20200409131755020](DataStruct-Notes.assets/image-20200409131755020.png)

如图，6为选中的枢纽元。

第二步，分割阶段，把所有较小的元素(与枢纽元相比)移动到数组左边，所有较大的元素移动到数组右边。移动指针i和j，直到分别指向大元素和小元素，如果i在j的左边，将二者元素互换。

![image-20200409133232915](DataStruct-Notes.assets/image-20200409133232915.png)

随后i与j相对位置发生变化，停止交换操作。此时将枢纽元素与i指向的元素交换。

![image-20200409133403364](DataStruct-Notes.assets/image-20200409133403364.png)

最后一步，这时，所有位置p<i的元素都是较小元素，所有位置p>i的元素都是较大元素。

#### 实现

首先选取枢纽元，对源数组中left、right和center进行排序。这样使较小者分配在最左侧，较大者分配在最右侧，同时将center分配在right左侧一个位置，这样在分割阶段就可以将i和j初始化为left+1和right-2，进行指针移动。

```cpp
template <typename Comparable>
const Comparable & median3(Vector<Comparable> & a, int left, int right){
    // 三个数调整顺序 left，right，center
    int center = (left + right)/2;
    if(a[center] < a[left])
        swap(a[center], a[left]);
    if(a[right] < a[left])
        swap(a[right], a[left]);
    if(a[right] < a[center])
        swap(a[right], a[center]);
    
    // place pivot at position right-1
    swap(a[center], a[right-1]);
    return a[right-1];
}
```

然后进行分割和递归调用，注释部分是错误的，原因在于如果开始的i和j元素值都等于pivot会停止指针移动，从而程序陷入死循环。

```cpp
template <typename Comparable>
void quickSort(Vector<Comparable> &a, int left, int right){
    // 寻找枢纽元至少需要存在3个元素，所以小数组使用插入排序完成
    if(left + 10 <= right){
        // 根据左右界找到枢纽元素
        Comparable pivot = median3(a, left, right);

        // begin partitioning
        // // 枢纽元素被交换到倒数第二个位置
        // int i = left+1, j = right-2;
        // for(; ;){
        //     // 此时的left绝对小于等于pivot
        //     // 左边i右边j，分别指向小于和大于pivot元素的值，非条件触发后交换之
        //     while(a[i] < pivot){ ++i;}
        //     while(pivot < a[j]){ --j;}
        //     if(i<j)
        //         swap(a[i], a[j]);
        //     else
        //         break;
        // }

        int i = left, j = right-1;
        for(; ;){
            // 此时的left绝对小于等于pivot
            // 左边i右边j，分别指向小于和大于pivot元素的值，非条件触发后交换之
            while(a[++i] < pivot){}
            while(pivot < a[--j]){}
            if(i<j)
                swap(a[i], a[j]);
            else
                break;
        }


        // i指向的元素必然大于pivot 交换之
        swap(a[i], a[right-1]);

        // 递归执行左右子序列
        quickSort(a, left, i-1);
        quickSort(a, i+1, right);
    }
    else{
        // Do an insertion sort on the subarray
        insertionSort(a, left, right);
    }
}

```

**分析**

假设不使用三数中值分割法选取枢纽元，而使用随机的，并且对元素个数不设置下限。和归并排序一样，取$T(0)=T(1)=1$, 快速排序的运行时间等于两个递归调用运行时间加上分割所耗费的线性时间：

$T(N) = T(i) + T(N-i-1) +cN $, 其中i是分割后一个序列的元素个数。

最坏情形下，枢纽元总是最小元素，i=0，那么：

$T(N)=T(N-1)+cN, N>1$

反复使用方程得到：

![image-20200409223754749](DataStruct-Notes.assets/image-20200409223754749.png)

最佳情形下，枢纽元正好位于中间，

$T(N)=2T(N/2)+cN$, 用N去除两边，得到：

$\frac{T(N)}{N} = \frac{T(N/2)}{N/2} +c$, 反复使用方程得到：

![image-20200409224109816](DataStruct-Notes.assets/image-20200409224109816.png)

叠加方程等到：![image-20200409224138443](DataStruct-Notes.assets/image-20200409224138443.png)

平均情况下，分析比较困难，但是记住结果仍然是O(NlogN)。

#### 解决选择问题

可以修改快速排序以解决选择问题(selection problem)。查找集合S中第k个最小元的算法，并称之为快速选择(quick select)。其步骤如下：

1.  如果S=1，那么k=1将S中元素返回。
2.  选取枢纽元$v\in S$
3.  将集合$S-\{v\}$ 分割为S1和S2
4.  如果k<=S1, 那么第k个最小元在S1中，返回quickselect(S1,k)。如果k=1+S1，那么枢纽元就是第k个最小元。否则，第k个最小元就在S2中，它是S2中第k-S1-1个最小元，进行递归调用quickselect(S2, k-S1-1).



### 间接排序

基于算法的函数模板，如果要排序的Comparable对象很大，在移动和复制元素的时候就会降低效率。解决方案：设置一个指向Comparable的指针数组，重新排列这些指针，不必进行过多的中间复制操作，称之为中间置换(in-situ permutation)。

定义一个Comparable数组，称之为copy

### 外部排序



## 图论

### 定义

图(graph)G=(V, E) 由顶点(vertex)的集合V和边(edge)的集合E构成。