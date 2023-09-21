#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N = 51;
typedef struct Node {
    char name[51];
    char pos[51];
    int num;
}node;
node* list;
int n, m;
void eql(node* a, node* b) {
    strcpy(a->name, b->name);
    strcpy(a->pos, b->pos);
    a->num = b->num;
}
void del(int pos) {
    for (int i = pos - 1;i < n - 1;i++) {
        eql(list + i, list + i + 1);
    }
    n--;
    list = (node*)realloc(list, sizeof(node) * n);
}
void ins(node* tmp, int pos) {
    n++;
    list = (node*)realloc(list, sizeof(node) * n);
    for (int i = n - 1;i > pos - 1;i--) {
        eql(list + i, list + i - 1);
    }
    eql(list + pos - 1, tmp);
}
void find(int pos) {
    pos--;
    printf("%s %s %d\n", list[pos].name, list[pos].pos, list[pos].num);
}
void show() {
    for (int i = 0;i < n;i++) {
        if (i == n - 1) {
            printf("%s %s %d\n", list[i].name, list[i].pos, list[i].num);
        }
        else
            printf("%s %s %d ", list[i].name, list[i].pos, list[i].num);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    list = (node*)malloc(n * sizeof(node));
    for (int i = 0;i < n;i++) {
        scanf("%s", list[i].name);
        scanf("%s", list[i].pos);
        scanf("%d", &list[i].num);
    }
    for (int i = 0;i < m;i++) {
        int mode, pos;
        scanf("%d", &mode);
        scanf("%d", &pos);
        if (mode == 1) {
            if (pos <= 0 || pos > n + 1) {
                printf("-1\n");
                continue;
            }
            del(pos);
            show();
            continue;
        }
        if (mode == 2) {
            node tmp;
            scanf("%s", tmp.name);
            scanf("%s", tmp.pos);
            scanf("%d", &tmp.num);
            if (pos <= 0 || pos > n + 1) {
                printf("-1\n");
                continue;
            }
            ins(&tmp, pos);
            show();
            continue;
        }
        if (mode == 3) {
            if (pos <= 0 || pos > n + 1) {
                printf("-1\n");
                continue;
            }
            find(pos);
            continue;
        }
    }
    return 0;
}