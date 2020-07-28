//Exercise, thread lockouts with mutex.

#include "useful_funcs.h"
#include <pthread.h>

pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;

int beers = 2000000;
void* drink_lots(void *a)
{
    pthread_mutex_lock(&beers_lock); //Will print every 100,000. Locking threads out of the loop til current thread is done.
    for(int i; i < 100000; i++){
        //pthread_mutex_lock(&beers_lock); //Will print at the end of every thread's execution. Only locks out when writing to beers.
        beers -= 1;
        //pthread_mutex_unlock(&beers_lock);
    }
    pthread_mutex_unlock(&beers_lock);
    printf("%i beers\n", beers);
    return NULL;
}

int main(){
    pthread_t threads[20]; //An array of threads, I suppose.
    int t;
    printf("%i bottles of beer on the wall\n%i bottles of beer\n", beers,beers);
    for(t = 0; t < 20; t++){
        //Spin up some threads.
        if(pthread_create(&threads[t], NULL, drink_lots, NULL) == -1)
            error("Can not create thread.");
    }

    void *result;
    for(t=0; t<20; t++){
        //Join the threads.
        pthread_join(threads[t], &result);
    }
    puts("Invite some cyborg buds over and suddenly...");
    printf("There are %i bottles of beer on the wall \n",beers);
    
    return 0;
}