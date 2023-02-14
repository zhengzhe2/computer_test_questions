#include "test_case_OK2.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>

#define TOTAL_SIZE 30
#define FALSE 0
#define TRUE 1

pthread_mutex_t mutex;

static int desktop_nums[TOTAL_SIZE];
static int queue_a[TOTAL_SIZE];
static int queue_b[TOTAL_SIZE];
static int queue_c[TOTAL_SIZE];
static int is_a_get = FALSE;
static int is_b_get = FALSE;
static int is_c_get = FALSE;

void update_desktop_nums(int num)
{
    for (int i = 0; i < TOTAL_SIZE; ++i) {
        if (desktop_nums[i] == -1) {
            desktop_nums[i] = num;
            break;
        }
    }
}

void handle_a()
{
    if (is_a_get == TRUE && (is_b_get == FALSE || is_c_get == FALSE)) {
        return;
    } else if (is_a_get == TRUE && is_b_get == TRUE && is_c_get == TRUE) {
        is_a_get = FALSE;
    }
    int start_num = desktop_nums[0];
    int end_num_index = 0;
    for (int i = 0; i < TOTAL_SIZE; ++i) {
        if (desktop_nums[i] == -1) {
            end_num_index = i -1;
            break;
        }
    }
    int end_num = desktop_nums[end_num_index];
    int is_insert = FALSE;
    if (start_num == end_num_index && start_num >= 0 && start_num <= 4) {
        for (int j = 0, k = 0; j < TOTAL_SIZE; ++j) {
            if (queue_a[j] == -1) {
                if (desktop_nums[k] != -1) {
                    is_a_get = TRUE;
                    is_insert = TRUE;
                    queue_a[j] = desktop_nums[k++];
                }
            }
        }
    }
    if (is_insert == TRUE) {
        printf("records:");
        printf_queue(4);
        printf("\n");
        memset(desktop_nums, -1, sizeof(int) * TOTAL_SIZE);
    }
}

void handle_b()
{
    if (is_b_get == TRUE && (is_a_get == FALSE || is_c_get == FALSE)) {
        return;
    } else if (is_b_get == TRUE && is_a_get == TRUE && is_c_get == TRUE) {
        is_b_get = FALSE;
    }
    int start_num = desktop_nums[0];
    int end_num_index = 0;
    for (int i = 0; i < TOTAL_SIZE; ++i) {
        if (desktop_nums[i] == -1) {
            end_num_index = i -1;
            break;
        }
    }
    int end_num = desktop_nums[end_num_index];
    int is_insert = FALSE;
    if (start_num == end_num_index && start_num >= 5 && start_num <= 9) {
        for (int j = 0, k = 0; j < TOTAL_SIZE; ++j) {
            if (queue_b[j] == -1) {
                if (desktop_nums[k] != -1) {
                    is_b_get = TRUE;
                    is_insert = TRUE;
                    queue_b[j] = desktop_nums[k++];
                }
            }
        }
    }
    if (is_insert == TRUE) {
        printf("records:");
        printf_queue(4);
        printf("\n");
        memset(desktop_nums, -1, sizeof(int) * TOTAL_SIZE);
    }
}

void handle_c()
{
    if (is_c_get == TRUE && (is_a_get == FALSE || is_b_get == FALSE)) {
        return;
    } else if (is_c_get == TRUE && is_a_get == TRUE && is_b_get == TRUE) {
        is_c_get = FALSE;
    }
    int start_num = desktop_nums[0];
    int end_num_index = 0;
    for (int i = 0; i < TOTAL_SIZE; ++i) {
        if (desktop_nums[i] == -1) {
            end_num_index = i -1;
            break;
        }
    }
    int end_num = desktop_nums[end_num_index];
    int start_end_total = start_num + end_num;
    int is_insert = FALSE;
    if (start_end_total >= 8 && start_end_total <= 10) {
        for (int j = 0, k = 0; j < TOTAL_SIZE; ++j) {
            if (queue_c[j] == -1) {
                if (desktop_nums[k] != -1) {
                    is_c_get = TRUE;
                    is_insert = TRUE;
                    queue_c[j] = desktop_nums[k++];
                }
            }
        }
    }
    if (is_insert == TRUE) {
        printf("records:");
        printf_queue(4);    
        printf("\n");
        memset(desktop_nums, -1, sizeof(int) * TOTAL_SIZE);
    }
}

static void* main_callback(void(*handle)(void))
{
    for (int i = 0; i < TOTAL_SIZE; i++) {
        pthread_mutex_lock(&mutex);
        struct timeb timer;
        ftime(&timer);
        srand(timer.time * 1000 + timer.millitm);
        int num = rand() % 10;
        update_desktop_nums(num);
        handle();
        pthread_mutex_unlock(&mutex);
        sleep(1);
    } 
}

void printf_queue(int index)
{
    for (int i = 0; i < TOTAL_SIZE; ++i) {
        if (index == 0) {
            if (queue_a[i] != -1) {
                printf("%d", queue_a[i]);
            }
        } else if (index == 1) {
            if (queue_b[i] != -1) {
                printf("%d", queue_b[i]);
            }
        } else if (index == 2) {
            if (queue_c[i] != -1) {
                printf("%d", queue_c[i]);
            }
        } else if (index == 4) {
            if (desktop_nums[i] != -1) {
                printf("%d", desktop_nums[i]);
            }
        }
    }
}

void solution_2()
{
    memset(desktop_nums, -1, sizeof(int) * TOTAL_SIZE);
    memset(queue_a, -1, sizeof(int) * TOTAL_SIZE);
    memset(queue_b, -1, sizeof(int) * TOTAL_SIZE);
    memset(queue_c, -1, sizeof(int) * TOTAL_SIZE);

    pthread_mutex_init(&mutex, NULL);
    pthread_t thread_a;
    pthread_t thread_b;
    pthread_t thread_c;
    int ret_a = pthread_create(&thread_a, NULL, main_callback, handle_a);
    if (ret_a != 0) {
        printf("pthread_create thread_a failed !!!\n");
        return;
    }
    int ret_b = pthread_create(&thread_b, NULL, main_callback, handle_b);
    if (ret_b != 0) {
        printf("pthread_create thread_b failed !!!\n");
        return;
    }
    int ret_c = pthread_create(&thread_c, NULL, main_callback, handle_c);
    if (ret_c != 0) {
        printf("pthread_create thread_c failed !!!\n");
        return;
    }
    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);
    pthread_join(thread_c, NULL);

    printf("records:");
    printf_queue(4);
    printf("\n");
    printf("a queue:");
    printf_queue(0);
    printf("\n");
    printf("b queue:");
    printf_queue(1);
    printf("\n");
    printf("c queue:");
    printf_queue(2);
    printf("\n");
}   