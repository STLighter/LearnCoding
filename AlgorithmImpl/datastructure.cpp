#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
class st_trie {
private:
    // 字典树节点
    struct TrieNode {
        // 表示是否为词尾
        bool isEnd;
        // 存储下一位的角标, -1表示暂时还没有节点. 这里假设字母只有26位小写字母
        int next[26];

        // 初始化
        TrieNode() {
            isEnd = false;
            memset(next,-1,sizeof(next));
        }
    };
    // 所有树节点, nodes[0]为根节点. 直接采用数组存储, 因为不删除所以数组不会有空位
    TrieNode *nodes;
    // 已用空间
    int _size;
    // 最大容量
    int _cap;
    // 扩容
    void resize(int new_cap) {
        TrieNode *tmp = new TrieNode[new_cap];
        memcpy(tmp, nodes, _cap*sizeof(TrieNode));
        delete[] nodes;
        nodes = tmp;
        _cap = new_cap;
    }
    // 插入字符串s, 当前搜到节点nodes[c], s[sp]是下一个字符
    void _insert(const string &s, int sp, int c) {
        if(sp == s.length()) {
            // 到达字符串结尾, 将标记变为true表示一个词结尾
            nodes[c].isEnd = true;
            return;
        }
        // 不是词尾则寻找表示下一个字符的节点
        int next = nodes[c].next[s[sp]-'a'];
        if(next == -1) {
            // 节点还不存在
            if(_size == _cap) // 如果容量已满则扩容一倍
                resize(_cap*2);
            // 分配新的节点
            next = nodes[c].next[s[sp]-'a'] = _size++;
        }
        // 递归调用, 插入下一个字符
        _insert(s, sp+1, next);
    }
    // 查询字符串, 参数意义与插入相同
    bool _find(const string &s, int sp, int c) {
        // 查询到词尾, 如果当前点标记为词尾则说明字典里有这个词, 否则没有
        if(sp == s.length())
            return nodes[c].isEnd;
        // 获取下一个字母节点
        int next = nodes[c].next[s[sp]-'a'];
        if(next == -1) // 下一个节点不存在, 则这个词一定不在字典里
            return false;
        // 查询下一个字母
        _find(s, sp+1, next);
    }
public:

    st_trie() {
        // 初始化nodes数组
        nodes = new TrieNode[_cap = 16];
        // _size为1因为有一个根节点
        _size = 1;
    }
    ~st_trie() {
        // 回收数组占用的内存
        delete[] nodes;
    }
    void insert(const string &s) {
        if(!s.length())
            return;
        _insert(s, 0, 0);
    }
    bool find(const string &s) {
        if(!s.length())
            return false;
        _find(s, 0, 0);
    }
};
class st_queue {
private:
    // 容量
    int _size;
    // 队列头
    int _start;
    // 队列尾
    int _end;
    // 队列长度
    int _len;
    // 存放队列的数组(循环队列)
    int *_arr;

    // 对数组扩容, 并将队列内容拷贝进新数组
    void resize(int new_size) {
        int *tmparr = new int[new_size];
        // 将原数组从队列头到数组结尾的位置复制进新数组的开始位置
        memcpy(tmparr, _arr + _start, sizeof(int)*(_size - _start));
        // 将原数组从数组头到队列尾的位置加进新数组
        memcpy(tmparr + _size - _start, _arr, sizeof(int)*_end);
        delete[] _arr;
        _arr = tmparr;
        _size = new_size;
        // 队列头和尾重新定位
        _start = 0;
        _end = _len;
    }

public:
    st_queue() {
        _start = 0;
        _end = 0;
        _len = 0;
        _size = 2;
        _arr = new int[2];
    }
    ~st_queue() {
        delete[] _arr;
    }
    void push(int v) {
        if(_len==_size) {
            // 队列已满则扩容
            resize(_size*2);
        }
        // 加到队列尾
        _arr[_end++] = v;
        // 更新队尾位置
        _end %= _size;
        // 更新队列长度
        ++_len;
    }
    int pop() {
        if(_len==0)
            throw "error";
        // 从队首取出
        int ret = _arr[_start];
        // 更新队首位置
        _start = (_start + 1) % _size;
        // 更新队列长度
        --_len;
        return ret;
    }
    bool isEmpty() {
        return (_len==0);
    }
    int size() {
        return _len;
    }
};

class st_stack {
private:
    // 最大容量
    int _size;
    // 实际大小
    int len;
    // 存储数据的数组
    int *arr;

    // 重新分配空间, 以便扩大容量
    void resize(int new_size) {
        int *tmparr = new int[new_size];
        memcpy(tmparr, arr, _size*sizeof(int));
        delete[] arr;
        arr = tmparr;
        _size = new_size;
    }
public:
    // 初始化栈的容量和大小
    st_stack() {
        len = 0;
        _size = 2;
        arr = new int[2];
    }
    // 释放arr占用的内存
    ~st_stack() {
        delete[] arr;
    }
    void push(int v) {
        if(len==_size) {
            // 如果容量已满, 扩容一倍
            resize(_size*2);
        }
        // 将数据加到数组尾部
        arr[len++] = v;
    }
    int pop() {
        // 从数组尾部取出数据
        if(len==0)
            throw "error";
        return arr[--len];
    }
    // 返回栈大小
    int size() {
        return len;
    }

    // 栈是否为空
    bool isEmpty() {
        return (len==0);
    }
};

int main() {
    st_trie trie;
    string ar[] = {"afgfg","afgfgf","dcfdgsfg","dffgasdfa","ffg","rtbrf","dbfg"};
    string ar2[] = {"afgffg","ghgfggdf","dcfdgsdgfg","dffgasdfa","ffg","rtbrf","dbfg"};
    for(int i=0;i<7;++i)
        trie.insert(ar[i]);
    for(int i=0;i<7;++i)
        printf("%d\n",trie.find(ar[i]));
    for(int i=0;i<7;++i)
        printf("%d\n",trie.find(ar2[i]));
}
