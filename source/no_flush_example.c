// omp_flush.cpp
// compile with: /openmp
#include <stdio.h>
#include <omp.h>



void print_thread_info(){
    printf("Thread %d: ", omp_get_thread_num());
}
int main() {
   int data;

    data = 0;
    // run this entire section in 2 threads
   #pragma omp parallel sections
   {
      // first section 
      #pragma omp section
      {
        print_thread_info();
         // Do more work.
         data = 2;
         printf("data = %d\n", data);
      }

      // second thread
      #pragma omp section
      {
         print_thread_info();
         if (data == 2){
          printf("Data was consistent\n");  
         }
         else{
         printf("data = %d\n", data);
         }
      }
   }
}
