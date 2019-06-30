# OpenMP examples

## Shared Memory Consitency with OpenMP

There are two problems relating to shared memory parallel programs, Coherence and Consistency. Coherence refers to the behaviour of the memory system when a single memory location is accessed by multiple threads. Consistenc refers to the ordering of access to different memory locations, observable from various threads in the system.

OpenMP does not specify any coherence behaviour of the memory system. That is left to the underlyin base language and computer system. That is left to the underlying base language and computer system. OpenMP does not guarantee anything about the result of memory operations that constitute data races within a program. A data race in this context is defined to be accesses to a single variable by at least two threads, at least one of which is a write, not separated by a synchronization operation. OpenMP deos not guarantee consistency behaviour, however. That behavior is based on the OpenMP flush operation.


# Run

```bash
    # visualize for loop differences with openmp
    make for_example
    # to visualize memory inconsistencies without `flush` directive in openmp
    make consistency_example
