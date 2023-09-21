#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 55;
int a[N];
int insert[N];

void ins(int pos, int x, int n) {
    for (int i = n;i > pos;i--) {
        insert[i] = insert[i - 1];
    }
    insert[pos] = x;
}

void insert_sort(int n) {
    for (int i = 0;i < n; i++) {
        if (i == 0) {
            insert[i] = a[i];
        }
        else {
            for (int j = 0;j <= i; j++) {
                if (insert[j] == -1) {
                    insert[j] = a[i];
                    break;
                }
                if (insert[j] > a[i]) {
                    ins(j, a[i], i);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << insert[i] << " ";
    }
    cout << endl;
}

int bubble[N];

void bubble_sort(int n) {
    int len = n;
    for (int i = 0; i < n; i++) {
        bubble[i] = a[i];
    }
    int flag = n;
    while (flag > 0) {
        flag = 0;
        for (int i = 1; i < n; i++) {
            if (bubble[i - 1] > bubble[i]) {
                swap(bubble[i], bubble[i - 1]);
                flag = i;
            }
        }
        n = flag;
    }
    for (int i = 0; i < len; i++) {
        cout << bubble[i] << " ";
    }
    cout << endl;
}

int qsort1[N];

void quick_sort(int l, int r) {
    if (l < r) {
        int i = l, j = r, k = rand() % (r - l + 1) + l;
        swap(qsort1[k], qsort1[l]);
        int n = qsort1[l];
        while (i < j) {
            while (i < j && qsort1[j] > n)
                j--;
            if (i < j)
                qsort1[i++] = qsort1[j];
            while (i < j && qsort1[i] < n)
                i++;
            if (i < j)
                qsort1[j--] = qsort1[i];
        }
        qsort1[i] = n;
        quick_sort(l, i - 1);
        quick_sort(i + 1, r);
    }

}

int select1[N];

void select_sort(int n) {
    bool flag[N];
    memset(flag, 0, sizeof(flag));
    for (int i = 0;i < n;i++) {
        int maxx = -1;
        int pos = -1;
        for (int j = 0;j < n;j++) {
            if (maxx < a[j] && !flag[j]) {
                maxx = a[j];
                pos = j;
            }
        }
        select1[i] = maxx;
        flag[pos] = 1;
    }
    for (int i = 0; i < n; i++) {
        cout << select1[i] << " ";
    }
    cout << endl;
}

int msort[N];
int temp[N];

void mergeArray(int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r) {
        if (msort[i] > msort[j]) {
            temp[k++] = msort[i];
            i++;
        }
        else {
            temp[k++] = msort[j];
            j++;
        }
    }
    while (j <= r) {
        temp[k++] = msort[j];
        j++;
    }
    while (i <= mid) {
        temp[k++] = msort[i];
        i++;
    }
    for (i = 0;i < k;i++) {
        msort[l + i] = temp[i];
    }
}

void merge_sort(int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    mergeArray(l, mid, r);
}

int heap[N];

void check(int start, int end) {
    int fa = start;
    int son = fa * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && heap[son] < heap[son + 1])
            ++son;
        if (heap[fa] > heap[son])
            return;
        else {
            swap(heap[fa], heap[son]);
            fa = son;
            son = son * 2 + 1;
        }
    }
}

void heap_sort(int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        check(i, n - 1);
    for (int i = n - 1; i > 0; --i) {
        swap(heap[0], heap[i]);
        check(0, i - 1);
    }
}

void init() {
    memset(insert, -1, sizeof(insert));
    memset(bubble, -1, sizeof(bubble));
    memset(select1, -1, sizeof(select1));
    memset(heap, -1, sizeof(heap));
}

int main() {
    init();
    int n;
    cin >> n;
    for (int i = 0;i < n; i++) {
        cin >> a[i];
    }
    insert_sort(n);
    bubble_sort(n);
    for (int i = 0; i < n; i++) {
        qsort1[i] = a[i];
    }
    quick_sort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << qsort1[i] << " ";
    }
    cout << endl;
    select_sort(n);
    for (int i = 0; i < n; i++) {
        msort[i] = a[i];
    }
    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << msort[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        heap[i] = a[i];
    }
    heap_sort(n);
    for (int i = n - 1; i >= 0; i--) {
        cout << heap[i] << " ";
    }
    return 0;
}