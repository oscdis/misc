#include <stdio.h>

extern "C" int sum(int, int);

int main(){
	printf("st:%d\n", sum(1, 3));

	return 0;
}
