#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <chrono>
#include <assert.h>
#include <cmath>

#define VECTOR_W 10000000  

uint16_t* vector;

uint32_t vectorLength(){
    uint32_t sum = 0;

    for(uint32_t i = 0;i<VECTOR_W;i++){
        sum += vector[i]*vector[i];
    }

    return sqrt(sum);
}

uint32_t vectorLengthParallel(){
    uint32_t sum = 0;
    uint32_t i;
    #pragma omp parallel for shared(vector) private(i)
    for(i = 0;i<VECTOR_W;i++){
        sum += vector[i]*vector[i];
    }

    return sqrt(sum);
}

uint32_t vectorLengthParallelRed(){
    uint32_t sum = 0;
    uint32_t i;
    #pragma omp parallel for shared(vector) private(i) reduction(+ : sum)
    for(i = 0;i<VECTOR_W;i++){
        sum += vector[i]*vector[i];
    }

    return sqrt(sum);
}


int main(){

    srand( time( NULL ) );

    //alloc vector
        vector = new uint16_t[VECTOR_W];

    //fill vector random data normal way
    for(uint32_t i = 0;i<VECTOR_W;i++){
            vector[i] = (uint16_t)(rand() % 10);
    }

    auto start = std::chrono::high_resolution_clock::now();
    uint32_t vector_length = vectorLength();
    auto end = std::chrono::high_resolution_clock::now();

    printf("Length calculated normal way: %u in time: %llu ms\r\n", vector_length,
    std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());


    start = std::chrono::high_resolution_clock::now();
    vector_length = vectorLengthParallel();
    end = std::chrono::high_resolution_clock::now();

    printf("Length calculated parallel way: %u in time: %llu ms\r\n", vector_length,
    std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());


    start = std::chrono::high_resolution_clock::now();
    vector_length = vectorLengthParallelRed();
    end = std::chrono::high_resolution_clock::now();

    printf("Length calculated parallel way with reduction: %u in time: %llu ms\r\n", vector_length,
    std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

    return 0;
}