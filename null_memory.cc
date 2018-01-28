//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.

#include <pycpp/allocator/null_memory.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(null_memory, is_relocatable)
{
    using allocator_type = null_memory_allocator<char>;
    static_assert(is_relocatable<allocator_type>::value, "");
}


TEST(null_memory_allocator, null_memory_allocator)
{
    using allocator_type = null_memory_allocator<char>;
    allocator_type allocator;

    EXPECT_THROW(allocator.allocate(50), bad_alloc);
    EXPECT_THROW(allocator.allocate(1), bad_alloc);
}
