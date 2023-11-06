#include<stdio.h>
#include<math.h>
double solve(int a, int b, int c, int dep, int n) {
	double res = 0;
	if (n <= 2) {
		return 0;
	}
	res = sqrt(c);
	if (dep == n) {
		return res;
	}
	return res + solve(b, c, a + b + c, dep + 1, n);
}
int main() {
	int n;
	scanf("%d", &n);
	double sum = solve(0, 0, 1, 3, n);
	printf("%lf\n", sum);
	return 0;
}