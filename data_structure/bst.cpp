#include<iostream>
#include<algorithm>

using namespace std;

struct node {
    node* l;
    node* r;
    int val;
    int cnt;
    bool empty;
    node() {
        empty = true;
        l = r = nullptr;
        cnt = 0;
    }
};

void insert(node* root, int x) {
    if (root->empty) {
        root->empty = 0;
        root->val = x;
        return;
    }
    if (root->val < x) {
        if (root->r == nullptr)
            root->r = new node;
        insert(root->r, x);
    }
    else if (root->val > x) {
        if (root->l == nullptr)
            root->l = new node;
        insert(root->l, x);
    }
    else {
        root->cnt++;
    }
}

void show(node root) {
    if (root.l != nullptr)
        show(*root.l);
    for (int i = 0;i <= root.cnt;i++) {
        cout << root.val << " ";
    }
    if (root.r != nullptr)
        show(*root.r);
}

int find(node* root, int x, int res) {
    if (root->empty) {
        root->empty = 0;
        root->val = x;
        return -1;
    }
    else {
        if (root->val < x) {
            if (root->r == nullptr)
                root->r = new node;
            return find(root->r, x, res + 1);
        }
        else if (root->val > x) {
            if (root->l == nullptr)
                root->l = new node;
            return find(root->l, x, res + 1);
        }
        else {
            root->cnt++;
            return res + 1;
        }
    }
}

int main() {
    node root;
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int x;
        cin >> x;
        insert(&root, x);
    }
    show(root);
    cout << endl;
    int x;
    cin >> x;
    int ans = find(&root, x, 0);
    if (ans != -1) {
        cout << "查找成功" << " " << ans << endl;
    }
    else {
        cout << "插入成功" << endl;
        show(root);
    }
    return 0;
}