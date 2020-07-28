/*
    Multithreading with pthread.
*/

#include "useful_funcs.h"
#include <pthread.h>


//Oh boy.
//Return a void* for thready funcs.
void* does_not(void *a){
    for (int i = 0; i < 5; i++){
        sleep(1);
        puts("Does not.");
    }
    return NULL;
}

void* does_too(void *a){
    for (int i = 0; i < 5; i++){
        sleep(1);
        puts("Does too.");
    }
    return NULL;
}


int main(){
    //Create a place to store the threads.
    pthread_t t0;
    pthread_t t1;


    //Create the threads.
    if (pthread_create(&t0, NULL, does_not, NULL) == -1)
        error("Can not create thread.");
    if (pthread_create(&t1, NULL, does_too, NULL) == -1)
        error("Can not create thread.");

    //Waiting for threads to finish.
    void* result; //The void pointer from each function will be stored in here.
    //Join the thread and wait for it to finish.
    if(pthread_join(t0, &result) == -1)
        error("Can not join thread t0.");
    if(pthread_join(t1, &result) == -1)
        error("Can not join thread t1.");

}