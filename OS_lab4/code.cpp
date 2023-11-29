#include<bits/stdc++.h>

using namespace std;

struct node {
    node* last;
    node* next;
    int pid;
    int mem;
    int st_ads;
};

node head;
node tail;
bool pids[10];
queue<int>waitq;

void init();
void ui();
void inerr();
int getcmd(int&, int&);
int tonum(string);
int findemp(int);
void fork(node*, int, int);
int findpid();
void printqueue();
void printlist();
node* findpid(int);
void piderr();
void memerr();
int kill(int);
void freetar(node*);
void checklst(node*);
void checknxt(node*);
void checkqueue();



int main() {
    freopen("test.txt", "r", stdin);
    init();
    while (1) {
        int pid, mem;
        int cmd = getcmd(pid, mem);
        if (cmd == 0) {
            continue;
        }
        if (cmd == -1) {
            break;
        }
        if (cmd == 1) {
            pid = findemp(mem);
            if (pid == -1) {
                cout << "full memory ,added to waiting queue\n";
                waitq.push(mem);
            }
            else {
                cout << "fork success\n";
                cout << "pid is " << pid << "\n";
            }
        }
        if (cmd == 2) {
            int mem = kill(pid);
            if (mem != -1) {
                cout << "kill success\n";
                cout << mem << " bite memory has been free\n";
            }
            checkqueue();
        }
        if (cmd == 3) {
            printlist();
        }
        if (cmd == 4) {
            printqueue();
        }

    }
    return 0;
}

void piderr() {
    cout << "pid not exist\n";
}

void printlist() {
    for (node* p = &head;p != NULL;p = p->next) {
        if (p->pid != -1) {
            cout << "pid: " << p->pid << " mem use: " << p->mem << " address is " << p->st_ads << "\n";
        }
        else {
            if (p != &tail)
                cout << "memory-fragment: " << p->mem << " bites\n";
            else
                cout << "memory remain: " << p->mem << " bites\n";
        }
    }
}

void printqueue() {
    queue<int>tmp;
    int i = 0;
    while (!waitq.empty()) {
        int cur = waitq.front();
        i++;
        waitq.pop();
        cout << i << " " << "wait for mem: " << cur << "\n";
    }
    while (!tmp.empty()) {
        waitq.push(tmp.front());
        tmp.pop();
    }
}

void checkqueue() {
    int l = waitq.size();
    for (int i = 1;i <= l;i++) {
        int cur = waitq.front();
        waitq.pop();
        cout << "try to fork in queue request\n";
        int pid = findemp(cur);
        if (pid == -1) {
            cout << "full memory ,added to waiting queue\n";
            waitq.push(cur);
        }
        else {
            cout << "fork success\n";
            cout << "pid is " << pid << "\n";
        }
    }
}

node* findpid(int pid) {
    for (node* p = &head;p != NULL;p = p->next) {
        if (p->pid == pid) {
            return p;
        }
    }
    return NULL;
}

void checklst(node* tar) {
    node* last = tar->last;
    if (tar->last->pid == -1) {
        tar->mem += last->mem;
        tar->last = last->last;
        last->last->next = tar;
        delete last;
    }
    else {
        return;
    }
}

void checknxt(node* tar) {
    node* next = tar->next;
    if (next->pid == -1) {
        next->mem += tar->mem;
        next->last = tar->last;

        tar->last->next = next;
        delete tar;
    }
    else {
        return;
    }
}

void freetar(node* tar) {
    tar->pid = -1;
    checklst(tar);
    checknxt(tar);
}

int kill(int pid) {
    node* tar = findpid(pid);
    if (tar == NULL) {
        piderr();
        return -1;
    }
    int res = tar->mem;
    freetar(tar);
    return res;
}

void fork(node* tar, int mem, int pid) {
    node* p = new node;
    p->next = tar;
    p->last = tar->last;
    p->st_ads = p->last->st_ads + p->last->mem / 1024;
    tar->last->next = p;
    tar->last = p;
    p->mem = mem;
    tar->mem -= mem;
    p->pid = pid;
}

int findemp(int mem) {
    mem = ceil(mem * 1.0 / 1024.0) * 1024;
    bool get = 0;
    int pid;
    for (node* p = &head;p != NULL;p = p->next) {
        if (p->pid == -1 && p->mem >= mem) {
            pid = findpid();
            if (pid == -1) {
                cout << "full pid pushing into wait queue\n";
                waitq.push(mem);
                return -1;
            }
            fork(p, mem, pid);
            get = 1;
            break;
        }
    }
    if (get) {
        return pid;
    }
    else {
        memerr();
        return -1;
    }
}

void init() {
    head.next = &tail;
    head.last = NULL;
    head.pid = 0;
    head.st_ads = 0;
    head.mem = 128 * 1024;
    tail.next = NULL;
    tail.last = &head;
    tail.pid = -1;
    tail.mem = (512 - 128) * 1024;
    pids[0] = 1;
}

int findpid() {
    for (int i = 1;i <= 9;i++) {
        if (!pids[i]) {
            pids[i] = 1;
            return i;
        }
    }
    return -1;
}

void ui() {
    cout << "use fork [mem size] to create a program with mem size bite memory\n";
    cout << "use kill [pid] to kill the program with the pid\n";
    cout << "use list to check all of the program and their memory uses\n";
    cout << "use queue to check the wait queue\n";
    cout << "use exit to end this program\n";
}

void inerr() {
    cout << "input error\n";
    ui();
}

void memerr() {
    cout << "not have enough mem pushing into waiting queue\n";
}

int tonum(string s) {
    int res = 0;
    for (int i = 0;i < s.length();i++) {
        res += s[i] - '0';
        res *= 10;
    }
    return res / 10;
}

int getcmd(int& pid, int& mem) {
    string s;
    getline(cin, s);
    if (s == "help") {
        ui();
        return 0;
    }
    if (s == "exit") {
        return -1;
    }
    if (s == "list") {
        return 3;
    }
    if (s == "queue") {
        return 4;
    }
    string cmd, data;
    bool get = 0;
    for (int i = 0;i < s.length();i++) {
        if (s[i] == ' ') {
            cmd = s.substr(0, i);
            data = s.substr(i + 1, s.length());
            get = 1;
            break;
        }
    }
    if (!get) {
        inerr();
        return 0;
    }
    if (cmd == "fork") {
        mem = tonum(data);
        if (mem <= 0) {
            inerr();
            return 0;
        }
        else {
            if (mem > (512 - 128) * 1024) {
                cout << "too large request\n";
                return 0;
            }
        }
        pid = -1;
        return 1;
    }
    else if (cmd == "kill") {
        mem = -1;
        pid = tonum(data);
        return 2;
    }
    else {
        inerr();
        return 0;
    }
}
