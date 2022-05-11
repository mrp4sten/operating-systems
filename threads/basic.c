#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_func(void *arg) {
	int value_to_int = *(int*)arg;
	printf("Value: %i\n", value_to_int);

	pthread_exit(0);
}

int main() {
	pthread_t thread1, thread2;
	int value1 = 5, value2 = 14;
	pthread_create(&thread1, NULL, thread_func, &value1);
	pthread_create(&thread2, NULL, thread_func, &value2);
	printf("Main thread\n");
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
}

