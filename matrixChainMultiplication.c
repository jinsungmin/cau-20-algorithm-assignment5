#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int count = 0;	// 계산 수
int array[100];
int index = 0;
typedef struct {
	int rows;
	int columns;
	int** arr;
	
} Matrix;

void initMatrix(Matrix* matrix, int rows, int columns, int zero) {
	matrix->rows = rows;
	matrix->columns = columns;
	matrix->arr = (int**)malloc(sizeof(int*) * matrix->rows);
	srand(time(NULL));

	for (int i = 0; i < matrix->rows; i++) {
		matrix->arr[i] = (int*)malloc(sizeof(int) * matrix->columns);
	}
	for (int i = 0; i < matrix->rows; i++) {
		for (int j = 0; j < matrix->columns; j++) {
			int random = rand() % 10;
			if (zero != 0) {
				matrix->arr[i][j] = random;
			}
			else {
				matrix->arr[i][j] = 0;
			}
		}
	}
}

void printMatrix(Matrix* matrix) {
	for (int i = 0; i < matrix->rows; i++) {
		for (int j = 0; j < matrix->columns; j++) {
			printf("%d ", matrix->arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


Matrix matrixMultiply(Matrix* A, Matrix* B) {
	Matrix temp;
	initMatrix(&temp, A->rows, B->columns,0);
	
	if (A->columns != B->rows) {
		printf("Error: incompativle dimentsions");
	}
	else {
		for (int i = 0; i < A->rows; i++) {
			for (int j = 0; j < B->columns; j++) {
				temp.arr[i][j] = 0;
				for (int k = 0; k < A->columns; k++) {
					temp.arr[i][j] = temp.arr[i][j] + A->arr[i][k] * B->arr[k][j];
					count++;	// 계산 수 + 1
				}
			}
		}
	}
	return temp;
}

void printMultorder(int s[][500], int i, int j) {
	
	if (i == j) {
		printf("M%d", i);
		array[index++] = i;
		return;
	}
	int k = s[i][j]; // k번째 위치에서 잘림.
	printf("(");
	array[index++] = '(';
	printMultorder(s, i, k);
	printMultorder(s, k + 1, j);
	printf(")");
	array[index++] = ')';
	return;
}

void solve() {
	
	int n;
	int** m;
	int d[1001] = { 0 };
	printf("<Input number n > ");
	scanf("%d", &n);

	m = (int**)malloc(sizeof(int*) * 501);
	for (int i = 0; i < 501; i++) {
		m[i] = (int*)malloc(sizeof(int) * 501);
	}
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			m[i][j] = 0;
		}
	}
	
	int s[500][500];
	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 500; j++) {
			s[i][j] = 0;
		}
	}

	for (int i = 0; i <= n; i++) {
		scanf("%d", &d[i]);
	}
	Matrix* matrix = (Matrix*)malloc(sizeof(Matrix) * n);		// n개의 matrix 생성
	for (int i = 0; i < n; i++) {
		initMatrix(&matrix[i], d[i], d[i + 1],1);
	}
	Matrix result;

	for (int len = 2; len <= n; len++) {
		for (int i = 1; i <= n - len + 1; i++) {
			int j = i + len - 1;
			m[i][j] = 10000000000;
			for (int k = i; k < j; k++) {
				int cost = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
				if (m[i][j] > cost) {
					m[i][j] = cost;
					s[i][j] = k;
				}
			}
		}
	}
	printf("최소 계산수: <%d>\n", m[1][n]);
	printMultorder(&s, 1, n);
	printf("\n");

	// printMultorder(&s, 1, n) 의 결과를 보고 임의로 수정
	result = matrixMultiply(&matrix[1], &matrix[2]);
	result =matrixMultiply(&matrix[0], &result);
	printMatrix(&result);
	
	// 동적 배열 해제
	free(matrix);
	for (int i = 0; i < 501; i++) {
		free(m[i]);
		
	}
	free(m);
	
}


int main(void) {
	
	solve();

	system("pause");
	return 0;
}