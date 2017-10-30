#include <stdio.h>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex a, b, c;

void A(){
    int i;
    while (1){
        for (i = 0; i < 2; ++i){
            a.lock();
            printf("c");
            b.unlock();
        }
    }
}

void C(){
    while(1){
        c.lock();
        printf("i");
        a.unlock();
        c.lock();
        printf("a");
        a.unlock();
    }
}

void B(){
    int j;
    while(1){
        for (j = 0; j < 2; j++){
            b.lock();
            printf("t");
            c.unlock();
        }
        b.lock();
        printf("\n");
        b.unlock();
    }
}


int main(){
    std::thread t1(A);
    std::thread t2(B);
    std::thread t3(C);

    b.unlock();

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
