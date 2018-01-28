# Allocator

**Table Of Contents**

- [Aligned](#aligned)
- [CRT](#crt)
- [Null](#null)

## Aligned

Type-aligned C-runtime allocator. A general-purpose allocator that uses shallow wrappers around `aligned_alloc`, `aligned_realloc`, and `aligned_free`. Only suitable as an allocator for the type (or types smaller than or equal to the size of the request type) requested, since on certain hardware, unaligned access may lead to difficult-to-debug faults. Should have notable performance enhancements on older hardware over the [CRT](#crt) allocator, however, on new x86 hardware, this performance difference should be minimal.

## CRT

C-runtime allocator. A general-purpose allocator that uses shallow wrappers around `malloc`, `realloc`, and `free`. A good fallback allocator for chained allocators, but suffers poor performance for small allocations.

## Null

Null memory resource allocator, throws `bad_alloc` on allocation, and in debug builds, aborts if non-null pointers are deallocated.
