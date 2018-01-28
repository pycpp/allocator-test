//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.

#include "allocator_test.h"
#include <pycpp/allocator/aligned.h>
#include <gtest/gtest.h>
#include <vector>

PYCPP_USING_NAMESPACE

// TESTS
// -----


TEST(aligned, is_relocatable)
{
    using allocator_type = aligned_allocator<char>;
// TODO: restore resource
//    using resource_type = aligned_resource;
    static_assert(is_relocatable<allocator_type>::value, "");
//    static_assert(is_relocatable<resource_type>::value, "");
}


TEST(aligned_allocator, aligned_allocator)
{
    using allocator_type = aligned_allocator<char>;
    allocator_type allocator;

    char* ptr = allocator.allocate(50);
    allocator.deallocate(ptr, 50);

    ptr = allocator.allocate(50);
    allocator.deallocate(ptr, 50);
}


TEST(aligned_allocator, relocatable)
{
    using allocator_type = aligned_allocator<char>;
    allocator_type allocator;

    size_t old_size = 50;
    size_t new_size = 100;
    size_t count = old_size;
    char* ptr = allocator.allocate(old_size);
    new (static_cast<void*>(ptr)) char('c');
    ptr = allocator.reallocate(ptr, old_size, new_size, count, 0, 0);
    EXPECT_EQ(ptr[0], 'c');
    allocator.deallocate(ptr, new_size);
}


TEST(aligned_allocator, non_relocatable)
{
    using allocator_type = aligned_allocator<non_relocatable>;
    allocator_type allocator;

    // check allocate
    size_t old_size = 50;
    non_relocatable* ptr = allocator.allocate(old_size);
    new (static_cast<void*>(ptr)) non_relocatable();
    EXPECT_EQ(ptr[0].x, 5);
    EXPECT_EQ(ptr[0].ptr, &ptr[0].x);

    // check reallocate
    size_t new_size = 100;
    size_t count = old_size;
    ptr = allocator.reallocate(ptr, old_size, new_size, count, 0, 0);
    EXPECT_EQ(ptr[0].x, 5);
    EXPECT_EQ(ptr[0].ptr, &ptr[0].x);
    allocator.deallocate(ptr, new_size);
}


TEST(aligned_allocator, vector)
{
    using allocator_type = aligned_allocator<char>;
    using vector_type = std::vector<char, allocator_type>;

    vector_type v1;
    v1.emplace_back(1);
}


// TODO: restore resource
//TEST(aligned_allocator, polymorphic)
//{
//    using allocator_type = polymorphic_allocator<int>;
//    using resource_type = aligned_resource;
//    using vector_type = std::vector<int, allocator_type>;
//
//    resource_type resource;
//    vector_type v1 = vector_type(allocator_type(&resource));
//    v1.emplace_back(1);
//}
