#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_func(void *arg) {
	int value_to_int = *(int*)arg;
	printf("Im thread, value: %i\n", value_to_int);

	pthread_exit(0);
}

int main() {
	pthread_t thread;
	int value = 5;
	pthread_create(&thread, NULL, thread_func, &value);
	printf("Main thread\n");
	pthread_join(thread, NULL);
}

