#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct node {
    node* left;
    node* right;
    char val;
    int dep;
};
node* root = nullptr;
int deepth;
int num;
string a;
int l;
int i = -1;
void add(node** r, int dep) {
    i++;
    if (i == l || a[i] == '#') {
        return;
    }
    num++;
    (*r) = new node;
    (*r)->val = a[i];
    (*r)->dep = dep;
    (*r)->left = nullptr;
    (*r)->right = nullptr;
    deepth = max(deepth, dep);
    add(&((*r)->left), dep + 1);
    add(&((*r)->right), dep + 1);
}


void mid(node* r) {
    if (r == nullptr) {
        return;
    }
    mid(r->left);
    cout << r->val;
    mid(r->right);
}


int main() {
    cin >> a;
    l = a.length();
    add(&root, 0);
    mid(root);
    return 0;
}