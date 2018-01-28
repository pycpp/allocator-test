//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.

#include "../allocator_test.h"
#include <pycpp/allocator/pool/allocator.h>
#include <gtest/gtest.h>
#include <vector>

PYCPP_USING_NAMESPACE

// TESTS
// -----


TEST(pool, is_relocatable)
{
    static_assert(!is_relocatable<pool_allocator<char>>::value, "");
    static_assert(!is_relocatable<fast_pool_allocator<char>>::value, "");
}


TEST(pool_allocator, pool_allocator)
{
    using allocator_type = pool_allocator<char>;
    allocator_type allocator;

    char* ptr = allocator.allocate(50);
    allocator.deallocate(ptr, 50);

    ptr = allocator.allocate(50);
    allocator.deallocate(ptr, 50);
}

