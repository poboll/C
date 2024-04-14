# C++ STL

​	STL 是提高 C++ 编写效率的一个利器。包含在iterator库函数

## #include <vector&gt;变长数组

​	vector 是变长数组，支持随机访问，不支持在任意位置 O(1) 插入。为了保证效率， 元素的增删一般应该在末尾进行。[基于倍增的思想]

### 声明

​	`#include <vector>` 头文件。

​	`vector<int> a;` 相当于一个长度动态变化的int数组，

​	`vector<int> b[233];` 相当于第一维长233，第二位长度动态变化的int数组。

​	`struct rec{...};`

​	`vector<rec>C;` 自定义的结构体类型也可以保存在vector中

### size/empty

​	`size` 函数返回 vector 的实际长度(包含的元素个数)，`empty` 函数返回一个 bool 类型，表明 vector 是否为空。二者的时间复杂度都是 O(1)。

​	所有的 STL 容器都支持这两个方法，含义也相同，之后我们就不再重复给出。

### clear

​	`clear`函数把 vector清空。

### 迭代器

​	迭代器就像 STL 容器的 "指针"，可以用星号 "*" 操作符解除引用。

​	一个保存 int 的 vector 的迭代器声明方法为：

​	`vector<int>::iterator it;`

​	vector的迭代器是"随机访问迭代器"，可以把 vector 的迭代器与一个整数相加减， 其行为和指针的移动类似。可以把 vector 的两个迭代器相减，其结果也和指针相减类似，得到两个迭代器对应下标之间的距离。

### begin/end.

​	`begin`函数返回指向vector中第一个元素的迭代器。如果`a`是一个非空的vector，那么`*a.begin()`的作用等同于`a[0]`，都是获取vector的第一个元素。

​	所有的容器都可以看作是"前闭后开"的结构。`end`函数返回的是指向vector尾部的迭代器，也就是指向第`n`个元素之后的"边界"，其中`n=a.size()`。因此，`*a.end()`和`a[n]`都是越界访问，这是不被允许的。	

​	for (int i = 0; i < a.size(); i++)	cout << a[i] << endl;

​	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)	cout << *it << endl;

​	由于迭代器本身是一个指针类型。这意味着迭代器存储的是元素在内存中的地址，而不是元素本身的值。因此，如果我们直接打印迭代器，输出的将是一个内存地址，而不是我们想要的元素值。

​	为了获取迭代器指向的元素值，我们需要使用解引用操作符(*)。这个操作符可以获取指针或迭代器指向的元素值。例如，如果`it`是一个迭代器，那么`*it`就是迭代器`it`指向的元素值。

````C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a({1, 2, 3});

    // 使用下标遍历并打印 vector 的所有元素
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
    cout << endl;

    // 使用迭代器遍历并打印 vector 的所有元素
    for (auto i = a.begin(); i < a.end(); i++) {
        cout << *i << ' ';
    }
    cout << endl;

    // 使用范围for循环（C++11特性）遍历并打印 vector 的所有元素
    for (int x : a) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}
````

### Push_back() 和pop_back()

​	a. `push_back(x)`：把元素x插入到vector a 的尾部。

​	b. `pop_back()`：删除vector a 的最后一个元素。

## #include <queue&gt;队列：先进先出

​	头文件 `queue` 主要包括循环队列 `queue` 和优先队列 `priority queue` 两个容器。

### 声明
​	`queue<int> q;` //队列 先进先出 

​	`struct rec {...};queue<rec> q;` // 结构体 rec 中必须定义小于（大根堆 ）/ 大于（小根堆）号

​	`priority_queue<int> q;` // 大根堆：优先队列（大）

​	`priority_queue<int, vector<int>, greater<int>> q;` // 小根堆（取反）

​	`priority_queue<pair<int, int>> q;` // 二元组

```C++
pair<int, string> a;//支持比较运算
a= {3, "aaa"};
cout << a.first << a.second << endl;

a = make_pair(4, "bbb");
cout << a.first << a.second << endl;
```

```C++
struct Rec {
    int a, b;
    
    bool operator< (const Rec& t) const {
        return a <  t.a;
    }
};
priority_queue<Rec, vector<Rec>, greater<Rec>> d;
d.push({1, 2});
```

### 循环队列queue

​	`push` 从队尾插入

​	`pop` 从队头弹出

​	`front` 返回队头元素

​	`back` 返回队尾元素

### 优先队列 priority queue

​	`push` 把元素插入堆

​	`pop` 删除堆顶元素

​	`top` 查询堆顶元素(最大值)

清除：q = queue<int>(); // 重新初始化一遍 

## #include <stack&gt;栈：先进后出

​	头文件 `stack` 包含栈。声明和前面的容器类似。

​	`push`：向栈顶插入元素

​	`pop`：弹出栈顶元素

## #include <deque&gt;双端队列 

​	双端队列 `deque` 是一个支持在两端高效插入或删除元素的连续线性存储空间。它就像是 `vector` 和 `queue` 的结合。与 `vector` 相比，`deque` 在头部增删元素仅需要 O(1) 的时间；与 `queue` 相比，`deque` 像数组一样支持随机访问。

​	`begin/end` 返回 `deque` 的头/尾迭代器

​	`front/back` 队头/队尾元素

​	`push_back` 从队尾入队

​	`push_front` 从队头入队

​	`pop_back` 从队尾出队

​	`pop_front` 从队头出队

​	`clear`  清空队列

## #include <set&gt;

​	头文件 set 主要包括 set 和 multiset 两个容器，分别是"有序集合"和"有序多重集合"，即前者的元素不能重复，而后者可以包含若干个相等的元素。set 和 multiset 的内部实现是一棵红黑树，它们支持的函数基本相同。

### 声明

​	`set<int> S;` // 元素不能重复

​	`struct rec{}; set<rec> s;` // 结构体 rec 中必须定义小于号

​	`multiset<double> s;` // 元素可以重复

```C++
set<int> a; // 元素不能重复
multiset<int> b; // 元素可以重复

struct Rec {
    int x, y;
    bool operator< (const Rec& t) const {
        return x < t.x;
    }
}; 
set<Rec> c;
```

### size/empty/clear

​	与 vector 类似

### 迭代器

​	`set` 和 `multiset` 的迭代器称为"双向访问迭代器"，不支持"随机访问"，支持星号(*)解除引用，仅支持"++"和"--"两个与算术相关的操作。

​	设 `it` 是一个迭代器，例如 `set<int>: iterator it;` 

​	若把 `it+`，则 `it` 会指向"下一个"元素。这里的"下一个"元素是指在元素从小到大排序的结果中，排在 `it` 下一名的元素。同理，若把 `it--`，则 `it` 将会指向排在"上一个"的元素。[有序序列]

```C++
set<int>::iterator it = a.begin();
it++; it--;
++it; --it;
a.end();
```

### begin/end

​	返回集合的首、尾迭代器，时间复杂度均为O(1)。

​	`s.begin()` 是指向集合中最小元素的迭代器。

​	`s.end()` 是指向集合中最大元素的下一个位置的迭代器。换言之，就像vector一样，是一个“前闭后开”的形式。因此，`--s.end()` 是指向集合中最大元素的迭代器。insert

​	`s.insert(x)` 把一个元素x插入到集合s中，时间复杂度为O(logn)。

​	在 `set` 中，若元素已存在，则不会重复插入该元素，对集合的状态无影响。

### find

​	`s.find(x)`在集合s中查找等于x的元素，并返回指向该元素的迭代器。若不存在，则返回 `s.end()`。时间复杂度为O(logn)。

判断是否在集合中（一般不）

```C++
a.insert(x);
if (a.find(x) == a.end()) // 判断x在集合a中是否存在
```

### Lower_bound/upper bound二分

​	这两个函数的用法与 find 类似，但查找的条件略有不同，时间复杂度为O(logn)。

​	`s.lower_bound(x)` 查找大于等于x的元素中最小的一个，并返回指向该元素的迭代器。

​	`s.upper_bound(x)` 查找大于x的元素中最小的一个，并返回指向该元素的迭代器。这两个函数的用法与 find 类似，但查找的条件略有不同，时间复杂度为O(logn)。

### erase

​	`	erase(it)` 方法用于从容器 `s` 中删除迭代器 `it` 指向的元素，其时间复杂度为 O(logn)。

​	`erase(x)` 方法用于从容器 `s` 中删除所有等于 `x` 的元素，其时间复杂度为 O(k+logn)。

​	其中，`k` 是被删除的元素个数。

### count

​	`s.count(x)` 方法用于返回集合 `s` 中等于 `x` 的元素个数，其时间复杂度为 O(k + logn)，其中 `k` 为元素 `x` 的个数。

## #include <map&gt;

​	`map` 容器是一个键值对 key-value 的映射，其内部实现是一棵以 `key` 为关键码的红黑树。`map` 的 `key` 和 `value` 可以是任意类型，其中 `key` 必须定义小于号运算符。

### 声明

```cpp
map<key type, value type> name;
```

### 例如

```cpp
map<long, long, bool> vis;
map<string, int> hash;
map<pair<int, int>, vector<int>> test;
```

### size/empty/clear/begin/end 均与set类似

​	`size()`：返回 `map` 中键值对的个数。

​	`empty()`：判断 `map` 是否为空。

​	`clear()`：清空 `map` 中的所有键值对。

​	`begin()`：返回指向 `map` 中第一个键值对的迭代器。

​	`end()`：返回指向 `map` 中最后一个键值对之后位置的迭代器。

```C++
map<string, vector<int>> a;
a["ухс"] = vector<int>({1,2,3,4});
cout << a["ухс"].size() << endl;
```

### insert/erase

​	与 `set` 类似，但其参数均是 `pair<key type, value type>`。

### find

​	`h.find(x)`：在变量名为 `h` 的 `map` 中查找键为 `x` 的键值对（二元组）。

### [ ]操作符

​	`h[key]`：返回键 `key` 映射的值的引用，时间复杂度为O(logn)。

​	`[]` 操作符是 `map` 最吸引人的地方。我们可以很方便地通过 `h[key]` 来得到 `key` 对应的值，还可以对 `h[key]` 进行赋值操作，改变 `key` 对应的值 `value`。

## #include <unordered_set&gt;

无序（无法支持二分）

```C++
unordered_set<int> a; //哈希表，不能存储重复元素
unordered_multiset<int> b; //哈希表，可以存储重复元素
```

## #include <unordered_map&gt;

无序（无法支持二分）；C++11

```C++
unordered_map<int, int> c;
```

## #include <bitset&gt;

无序（无法支持二分）

```C++
bitset<1000> a, b; //长度为1000的字符串
a[0] = 1;
cout << a[0] << endl; 
a.count();
// 位运算
a &= b;
a |= b; 
a.set(3);
a.reset(3);
```

