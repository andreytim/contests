#include <stdio.h>

int main_Melon_4A() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int w;
	scanf("%d", &w);
	if ((w & 1) != 0 || w == 2) {
		printf("NO");
	} else {
		printf("YES");
	}
	return 0;
}