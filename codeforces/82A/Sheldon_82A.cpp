#include <stdio.h>
#include <cmath>

int main_Sheldon_82A() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	long n;
	scanf("%d", &n);
	
	int i = 0;
	long sum = 0;
	while (sum < n) {
		sum += 5*pow(2.0, i);
		i++;
	}

	int res = (sum - n)/pow(2.0, i-1);
	switch (res) {
		case 0: printf("Howard");
			break;
		case 1: printf("Rajesh");
			break;
		case 2: printf("Penny");
			break;
		case 3: printf("Leonard");
			break;
		case 4: printf("Sheldon");
			break;
	}

	return 0;
}