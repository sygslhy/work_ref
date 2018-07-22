/*
 * main.c
 *
 *  Created on: 5 nov. 2017
 *      Author: Administrator
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

#define NUM 10
static int shared = 0;
static unsigned int cnt = 0;
char message[20];
static sem_t sem_get;
static sem_t sem_set;
static pthread_mutex_t mutex_work;
void* thread_get_routine(void* arg)
{
	printf("this is thread get:%s shared=%d cnt=%d\n",(char*)arg, shared, cnt);
	while(shared<NUM){
		sem_wait(&sem_get);
		pthread_mutex_lock(&mutex_work);
		cnt--;
		printf("get shared=%d cnt=%d\n", shared, cnt);
		shared++;
		pthread_mutex_unlock(&mutex_work);
		sleep(2);
		sem_post(&sem_set);
	}
	pthread_exit("Thread get is over");
}

void* thread_set_routine(void* arg)
{
	printf("this is thread set:%s shared=%d cnt=%d\n",(char*)arg, shared, cnt);
	while(shared<NUM){
		sem_wait(&sem_set);
		pthread_mutex_lock(&mutex_work);
		cnt++;
		printf("set shared=%d cnt=%d\n", shared, cnt);
		shared++;
		pthread_mutex_unlock(&mutex_work);
		sleep(1);
		sem_post(&sem_get);
	}
	pthread_exit("Thread set is over");
}


int main()
{
	void *thread_result;
	int res;

	res = sem_init(&sem_get, 0, 0);
	res = sem_init(&sem_set, 0, 5);
	res = pthread_mutex_init(&mutex_work, NULL);
	pthread_t thread_get;
	pthread_t thread_set;
	res = pthread_create(&thread_set, NULL, thread_set_routine, (void*)message);
	res = pthread_create(&thread_get, NULL, thread_get_routine, (void*)message);
	res = pthread_join(thread_get,  &thread_result);
	res = pthread_join(thread_set,  &thread_result);
	printf("thread_get is finished %d\n", shared);
	res = sem_destroy(&sem_get);
	res = sem_destroy(&sem_set);
	res = pthread_mutex_destroy(&mutex_work);
	return 0;
}

