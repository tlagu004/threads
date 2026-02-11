#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include <pthread.h>
#define SIZE 10

typedef struct {
    int start_index;
    int end_index;
} ListData;

int numbers[] = {7, 12, 19, 3, 18, 4, 2, 6, 15, 8};
int result[SIZE];


void *selection_sort(void *params){
    ListData *ptr = (ListData *)params;
    int start = ptr->start_index;
    int end = ptr->end_index;
    printf("Sorting from index %d to index %d...\n", start, end);
    
    for (int i = start; i <= end; i++) {
        for (int j = i + 1; j <= end; j++) {
            if (numbers[i] > numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    pthread_exit(0);
}

void *merge(void *params) {
    printf("Merging...\n");
    int left = 0;          
    int right = SIZE / 2;         
    int i = 0;              
    
    while (left < (SIZE / 2) && right < 10) {
        if (numbers[left] < numbers[right])
        result[i++] = numbers[left++];
    else
            result[i++] = numbers[right++];
    }
    while (left < (SIZE / 2)) result[i++] = numbers[left++];
    while (right < SIZE) result[i++] = numbers[right++];
    
    pthread_exit(0);
}

int main(){
    printf("Welcome to MultiThreads\n");
    printf("Unsorted Array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    pthread_t thread_sort1, thread_sort2, thread_merge;

    printf("Memory Allocation and ListData Creation...\n");
    ListData *data1 = (ListData *) malloc(sizeof(ListData));
    data1->start_index = 0;
    data1->end_index = (SIZE / 2) - 1;

    ListData *data2 = (ListData *) malloc(sizeof(ListData));
    data2->start_index = SIZE / 2;
    data2->end_index = SIZE - 1;

    printf("Creating Threads...\n");
    pthread_create(&thread_sort1, NULL, selection_sort, data1);
    pthread_create(&thread_sort2, NULL, selection_sort, data2);

    printf("Joining Threads...\n");
    pthread_join(thread_sort1, NULL);
    pthread_join(thread_sort2, NULL);

    printf("Creating & Joining Merge Thread...\n");
    pthread_create(&thread_merge, NULL, merge, NULL);
    pthread_join(thread_merge, NULL);

    printf("Sorted Array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    printf("Freeing Memory...\n");
    free(data1);
    free(data2);

    printf("Exiting...\n");
    return 0;
}