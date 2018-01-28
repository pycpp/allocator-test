//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.

#include "allocator_test.h"
#include <pycpp/allocator/new_delete.h>
#include <gtest/gtest.h>
#include <vector>

PYCPP_USING_NAMESPACE

// TESTS
// -----


TEST(new_delete, is_relocatable)
{
    using allocator_type = new_delete_allocator<char>;
    static_assert(is_relocatable<allocator_type>::value, "");
}


TEST(new_delete_allocator, new_delete_allocator)
{
    using allocator_type = new_delete_allocator<char>;
    allocator_type allocator;

    char* ptr = allocator.allocate(50);
    allocator.deallocate(ptr, 50);

    ptr = allocator.allocate(50);
    allocator.deallocate(ptr, 50);
}
