//2.19  已知线性表中的元素以值递增有序排列，并以单链表作存储结构。
//试写一高效的算法，删除表中所有值大于mink且小于maxk的元素（若表中存在这样的元素）
//同时释放被删结点空间，并分析你的算法的时间复杂度（注意： mink和maxk是给定的两个参变量
//他们的值可以和表中相同，也可以不同）

void data_del(List link, int mink, int maxk) {
    Node* p = NULL;
    bool flag_head = 0;
    Node* til;
    bool flag_til = 0;
    for (Node* i = link.head->next;i != NULL;i = i->next) {
        if (p != NULL) {//删除不符合条件的结点
            delete(p);
            p = NULL;
        }
        if (i <= mink || i >= maxk) {
            p = i;
            continue;
        }
        if (!flag_head) {//处理头指针
            flag = 1;
            link.head->next = i;
        }
        if (i->next->x >= maxk && !flag_til) {//记录删除后的链表结尾
            til = i;
            flag_til = 1;
        }
    }
    til->next = NULL;
}

//2.22 试写一算法，对单链表实现就地逆置。

void link_reverse(Link link) {
    Node* tl;
    bool hd = 0;
    for (Node* i = link.head->next;i != NULL;i = i->next) {
        link.head->next = i;
        if (!hd) {
            hd = 1;
            tl = i;
        }
    }
    tl->next = NULL;
}

/*
2.38   设有一个双向循环链表，每个结点中除有prior,data和next三个域外，
还增设了一个访问频度域freq。在链表被起用之前，频度域freq的值均初始化为零，
而每当对链表进行一次locate(L,x)的操作后，被访问的结点（即元素值等于x的结点）中的频度域freq的值便增1，
同时调整链表中结点之间的次序，使其按访问频度非递增的次序顺序排列，
以便始终保持被频繁访问的结点总是靠近表头结点。试编写符合上述要求的locate操作的算法。
*/

int locate(list& L, int x) {
    Node* p, q;//新建辅助指针和定位指针
    if (!L->head)return -1;//无链表
    p = L.head->next;
    q = L.head->next;
    for (;p != L.head;p = p->next) {//定位目标点
        if (p->data == x) {
            break;
        }
    }
    if (p == L->head)	return 0;
    p->freq++;				    //频数+1
    p->prior->next = p->next;
    p->next->prior = p->prior; 		//先将p结点从链表中脱离
    for (;q != L.head;q = q->next) {//辅助指针定位到插入位
        if (q->freq >= p->freq) {
            break;
        }
    }
    if (q == L) {//插入目标点
        p->next = q->next;
        q->next = p;
        p->prior = q->prior;
        q->prior = p;
    }//频数最小为0，所以q总是能找到插入位，如果q循环到头结点，表明原表只剩头结点
    else {
        p->next = q->prior->next;
        q->prior->next = p;
        p->prior = q->prior;
        q->prior = p;
    }//其余情况正常插入
    return 1;
}
