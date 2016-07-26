#include<cstdio>
#include<vector>
using namespace std;
void merge_sort(vector<int> &v) {
    // 递归终止条件, 当少于一个元素, 数组有序, 直接返回
    if(v.size()<=1)
        return;
    int l = v.size();
    int half = l/2;
    // 将数组分为两段
    vector<int> left(v.begin(),v.begin() + half);
    vector<int> right(v.begin() + half, v.end());

    // 递归, 将两段分别排序
    merge_sort(left);
    merge_sort(right);

    // 合并两段, 将两段中左侧的值相互比较, 将较小的值放入原数组中
    for(int i=0,j=0,k=0;i<left.size()||j<right.size();) {
        // 左侧的数组段都放进了原数组, 则直接放右侧的数组
       if(i==left.size())
        v[k++] = right[j++];
        // 右侧的数组段都放进了原数组, 则直接放左侧的数组
       else if(j==right.size())
        v[k++] = left[i++];
        // 左侧数组的值小
       else if(left[i]<right[j])
        v[k++] = left[i++];
        // 右侧数组的值小
       else
        v[k++] = right[j++];
    }
}
void _qsort(vector<int> &v, int st, int end) {
    // 元素少于两个, 直接返回
    if(end - st < 2)
        return;
    // 将v[st]选为pivot, small_end表示一个索引, v[st+1]到v[small_end](包括v[small_end])都不大于v[st], 而v[small_end+1]之后都大于v[st]
    int small_end = st, pv = v[st], tmp;
    for(int i=st+1;i<end;++i) {
        if(v[i] <= pv) {
            // v[i]也小于pivot的值, 需要将v[i]放到small_end之后
            ++small_end;
            if(small_end!=i) {
                // small_end之后如果不是当前位置i, 则一定是一个大于pivot的值, 则直接和v[i]交换
                tmp = v[i];
                v[i] = v[small_end];
                v[small_end] = tmp;
            }
        }
    }
    if(small_end!=st) {
        // 如果不是所有值都大于pivot, 则pivot的正确位置不是st而是small_end.
        v[st] = v[small_end];
        v[small_end] = pv;
    }
    // 分别递归两侧
    _qsort(v, st, small_end);
    _qsort(v, small_end+1, end);
}
void quick_sort(vector<int> &v) {
    _qsort(v, 0, v.size());
}

class Heap {
private:
    // 内部用数组存储, 模拟二叉树, 根节点索引为0, 当节点索引为id时, 左儿子是id*2+1, 右儿子是id*2+2, 父节点是(id-1)/2
    vector<int> arr;
public:
    // 插入新的节点
    void push(int v) {
        int p = arr.size(), q, tmp;
        // 将新值加入数组尾部
        arr.push_back(v);

        // 从尾部开始维护小顶堆性质, 从加入位置开始检查, 如果父节点较大就交换并继续维护父节点. p是当前节点索引, q是父节点索引
        while(p!=0&&arr[p]<arr[(q = (p-1)/2)]) {
            tmp = arr[p];
            arr[p] = arr[q];
            arr[q] = tmp;
            p = q;
        }
    }
    int pop() {
        // 没有值可以pop();
        if(!arr.size()) {
            throw "error";
        }
        // 用ret存储根节点(堆顶)的值, 也就是要返回的值
        int ret = arr[0], p=0, q, tmp, l;
        // 将数组最后一个元素的值放到根节点, 并移除最后一个元素, 等价于交换后移除根节点的值
        arr[0] = arr[arr.size()-1];
        arr.pop_back();
        l = arr.size();

        // 从顶部开始维护堆的性质.
        while(1) {
            // 找到当前节点与两个儿子中较小值的角标
            if(p*2+1 < l && arr[p]>arr[p*2+1]) {
                q = p*2+1;
            } else {
                q = p;
            }
            if(p*2+2 < l && arr[q]>arr[p*2+2]) {
                q = p*2+2;
            }

            if(q!=p) {
                // 如果一个儿子的值更小, 则需要交换, 并继续维护儿子
                tmp = arr[p];
                arr[p] = arr[q];
                arr[q] = tmp;
                p = q;
            } else {
                // 当前节点最小, 则已经满足小顶堆性质
                break;
            }
        }
        return ret;
    }
    void clear() {
        arr.clear();
    }
};
void heap_sort(vector<int> &v) {
    Heap heap;
    int l = v.size();
    // 插入堆, c++11语法
    for(auto i: v) {
        heap.push(i);
    }
    // 从堆中依次取出
    for(int i=0;i<l;++i) {
        v[i] = heap.pop();
    }
}

void insert_sort(vector<int> &v) {
	int l = v.size();
	int tmp;
	// 从左往右枚举i, v[0]到v[i-1]已经有序但不是最终顺序, 每次将v[i]放入其合适的位置
	for(int i=1;i<l;++i) {
        // 初始v[i] = v[j]
		for(int j=i;j>0;--j) {
		    // 将v[j]与前面的值比较
			if(v[j]<v[j-1]) {
			    // 如果v[j]比较小, 则与前面的值交换
				tmp = v[j];
				v[j] = v[j-1];
				v[j-1] = tmp;
			} else {
			    // 如果不是则已经保证了v[0]到v[i]有序
			    break;
			}
		}
	}
}

void bubble_sort(vector<int> &v) {
    int l = v.size();
    int tmp;
    bool flag;
    // 从右往左枚举i, v[i+1]到v[l-1]已经有序且是最终顺序, 每次循环将把v[0]到v[i]的最大值换给v[i]
    for(int i=l-1;i>0;--i) {
        // 从v[0]开始两两比较, 将大的数放到右侧, 最大的数自然被交换到了v[i]
        flag = false;   // 检测此次循环是否交换过, 如果没发生过交换则数组已经有序
        for(int j=0;j<i;++j) {
            // 两两比较
            if(v[j]>v[j+1]) {
                // 左侧较大则交换, 使得保持右侧较大
                tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
                flag = true;
            }
        }
        if(!flag)
            break;  //没有发生交换, 数组已经有序, 直接退出
    }
}

int main() {
    vector<int> arr = {
        123,35,235,784,234,68,45,6,3,236,2,125,64366,1283,12454,1,579
    };
	merge_sort(arr);
	for(auto i : arr) {
        printf("%d\n", i);
	}
}
