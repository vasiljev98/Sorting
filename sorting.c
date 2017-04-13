/*
V 0.1: считываем n, выводим:
	сгенерированный массив, 
	отсортированный массив, 
	время

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void quicksort(int *A, int len);
void bubble_sort(int *A, int len);
void insertion_sort(int *A, int len);
void shell_sort(int *A, int len);

int main() {
	int n = 40000; // TODO: нужно считывать это число с консоли
	int i;
	int quick_s[n];
	int shell_s[n];
	int inser_s[n];
	int bubbl_s[n];

	// scanf("%d",&n);

	for (int i=0; i<n; i++){ // Производим заполнение массива
		quick_s[i]=rand()%10000000; 
		shell_s[i]=rand()%10000000; 
		inser_s[i]=rand()%10000000; 
		bubbl_s[i]=rand()%10000000; 
	};
	
	// for (i = 0; i < n; i++){
	// 	printf("%d ", x[i]);
	// }
	// printf("\n");
	double start_quick = clock();
	quicksort(quick_s, n);
 	printf("qs: %.4lf\n", (clock() - start_quick) / CLOCKS_PER_SEC);
	

	double start_shell = clock();
	shell_sort(shell_s, n);
 	printf("ss: %.4lf\n", (clock() - start_shell) / CLOCKS_PER_SEC);

	double start_inser = clock();
	insertion_sort(inser_s, n);
 	printf("is: %.4lf\n", (clock() - start_inser) / CLOCKS_PER_SEC);

	double start_bubbl = clock();
	bubble_sort(bubbl_s, n);
 	printf("bs: %.4lf\n", (clock() - start_bubbl) / CLOCKS_PER_SEC);


	// for (i = 0; i < n; i++){ 
	// 	printf("%d ", x[i]);
	// }
	// printf("\n"); 

	
	return 0;

};

void quicksort(int *A, int len){
	if (len < 2) return;
	int pivot = A[len / 2];
	int i, j;
	for (i = 0, j = len - 1; ; i++, j--){
		while (A[i] < pivot) i++;
		while (A[j] > pivot) j--;
		if (i >= j) break;
		int temp = A[i];
		A[i]     = A[j];
		A[j]     = temp;
	}

	quicksort(A, i);
	quicksort(A + i, len - i);
};
 

void bubble_sort (int *a, int n) {
    int i, t, s = 1;
    while (s) {
        s = 0;
        for (i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                t = a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;
                s = 1;
            }
        }
    }
};

void insertion_sort(int *a, int n) {
	for(size_t i = 1; i < n; ++i) {
		int tmp = a[i];
		size_t j = i;
		while(j > 0 && tmp < a[j - 1]) {
			a[j] = a[j - 1];
			--j;
		}
		a[j] = tmp;
	}
};

void shell_sort (int *a, int n) {
    int h, i, j, t;
    for (h = n; h /= 2;) {
        for (i = h; i < n; i++) {
            t = a[i];
            for (j = i; j >= h && t < a[j - h]; j -= h) {
                a[j] = a[j - h];
            }
            a[j] = t;
        }
    }
};

void merge (int *a, int n, int m) {
    int i, j, k;
    int *x = malloc(n * sizeof (int));
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n      ? a[i++]
             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             :               a[i++];
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    free(x);
};
 
void merge_sort (int *a, int n) {
    if (n < 2)
        return;
    int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
};

