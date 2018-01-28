//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.

// DATA
// ----

struct non_relocatable
{
    int x = 5;
    int* ptr = &x;

    non_relocatable(int y = 5):
        x(y), ptr(&x)
    {}

    non_relocatable(const non_relocatable& rhs):
        non_relocatable(rhs.x)
    {}

    non_relocatable& operator=(const non_relocatable& rhs)
    {
        x = rhs.x;
        return *this;
    }

    non_relocatable(non_relocatable&& rhs):
        non_relocatable(rhs.x)
    {}

    non_relocatable& operator=(non_relocatable&& rhs)
    {
        x = rhs.x;
        return *this;
    }
};
