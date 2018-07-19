#include <cassert>
#include "analogliterals.hpp"
#include <stdio.h>

int main() {

    using namespace analog_literals::symbols;

    auto a = 4;
    unsigned int b = I---------I;

    printf("%d, %d\n", a, b);

    auto c = (o-----o
              |     !
              !     !
              !     !
              !     !
              o-----o).area;

    printf("%d\n",c);

    return 0;
}
