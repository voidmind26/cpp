/*
3.19 假设一个算术表达式中可以包含三种括号：
园括号"("和")"、方括号"["和"]"、花括号"{"和"}"，且这三种括号可按任意的次序嵌套使用
（如：…[…{…}…[…]…]…[…]…(…)…)。
编写判别给定表达式中所含括号是否正确配对出现的算法（已知表达式已存入数据元素为字符的顺序表中）。
*/


bool check(int n, char* data) {
    stack a;
    for (int i = 0;i < strlen(data);i++) {
        if (data[i] == '(' || data[i] == '[' || data[i] == '{') {
            a.push(data[i]);
        }
        else {
            if (a.top() == '(') {
                if (data[i] != ')') {
                    return 0;
                }
            }
            if (a.top() == '[') {
                if (data[i] != ']') {
                    return 0;
                }
            }
            if (a.top() == '{') {
                if (data[i] != '}') {
                    return 0;
                }
            }
            a.pop();
        }
    }
    if (!a.empty()) {
        return 0;
    }
    return 1;
}