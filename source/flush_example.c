// omp_flush.cpp
// compile with: /openmp
#include <stdio.h>
#include <omp.h>

void read(int *data) {
   printf("read data\n");
   *data = 1;
}

void process(int *data) {
   printf("process data\n");
   (*data)++;
}

void print_thread_info(){
    printf("Thread %d: ", omp_get_thread_num());
}
int main() {
   int data;
   int flag;

   flag = 0;

    // run this entire section in 2 threads
   #pragma omp parallel sections num_threads(2)
   {
      // first section 
      #pragma omp section
      {
        print_thread_info();
         read(&data);
         #pragma omp flush(data)
         flag = 1;
         #pragma omp flush(flag)
         // Do more work.
         printf("data = %d\n", data);
      }

      // second thread
      #pragma omp section
      {
         while (!flag) {
           #pragma omp flush(flag)
         }
         #pragma omp flush(data)

         print_thread_info();
         process(&data);
         if (data==2){
            printf("Data was consistent\n");
         }
         printf("data = %d\n", data);
      }
   }
}
