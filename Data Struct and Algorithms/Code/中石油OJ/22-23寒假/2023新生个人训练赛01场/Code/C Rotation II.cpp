#include <stdio.h>
#include <stdlib.h>

char* getGyaku(char* grid) {
	char* tgrid = (char*) malloc(3 * sizeof(char));
	for(int i = 0; i < 3; ++i) {
		tgrid[2 - i] = grid[i];
	}
	return tgrid;
}

int main() {
	char grid[2][3];
	char* tgrid[2];
	int flag = 1;
	
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 3; ++j) {
			scanf("%c", &grid[i][j]);
		}
		tgrid[i] = getGyaku(grid[i]);
		getchar();
	}
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(tgrid[1 - i][j] != grid[i][j]) {
				flag = 0;
				break;
			}
		}
	}
	
	if(flag == 1) {
		printf("YES");
	} else {
		printf("NO");
	}
}
