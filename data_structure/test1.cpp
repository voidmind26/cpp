#include<iostream>
#include<cstdio>    
#include<cstring>
#include<cstring>

using namespace std;

struct node {
    node() {
        val = '-';
        left = nullptr;
        right = nullptr;
    }
    node* left;
    node* right;
    char val;
};

int add(node** root, char val) {
    if (*root == nullptr) {
        *root = new node;
        (*root)->val = val;
        return 1;
    }
    else if ((*root)->val == '#') {
        return 0;
    }
    else {
        if (add(&((*root)->left), val) == 0)
            return add(&((*root)->right), val);
    }
    return 1;
}

void build(char* a, node** root) {
    for (int i = 0;i < strlen(a); i++) {
        add(root, a[i]);
    }
}

bool check(node* root, char last) {
    if (root->val == '#') {
        return true;
    }
    if (root->val <= last) {
        return false;
    }
    else {
        return check(root->left, root->val) && check(root->right, root->val);
    }

}

int main() {
    node* root = nullptr;
    char a[1000];
    cin >> a;
    build(a, &root);
    if (check(root, 'A' - 1)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}