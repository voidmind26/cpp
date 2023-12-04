#include<stdio.h>

void solve(int a[], int n, int x) {
    int pos = -1;
    for (int i = 0;i < n - 1;i++) {
        if (a[i] > x) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        pos = n - 1;
    }
    for (int i = n - 1;i > pos;i--) {
        a[i] = a[i - 1];
    }
    a[pos] = x;
}

int main() {
    int a[] = { 1,2,4,6,10,46,52,0 };
    int x;
    scanf("%d", &x);
    solve(a, 8, x);
    for (int i = 0;i < 8;i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}