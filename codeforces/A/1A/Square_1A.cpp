#include <stdio.h>

int main_Square_1A() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	long n, m, a;
	scanf("%d%d%d", &n, &m, &a);
	
	long width;
	if (n%a == 0) {
		width = n/a;
	} else {
		width = n/a + 1;
	}

	long height;
	if (m%a == 0) {
		height = m/a;
	} else {
		height = m/a + 1;
	}

	printf("%I64d\n", (long long)height*(long long)width);
	return 0;
}