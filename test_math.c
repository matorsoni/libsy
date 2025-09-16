#include "sy_math.h"

#include <stdio.h>

void print_vec2f(sy_vec2f v) {
    printf("[%f %f]\n", v.elt[0], v.elt[1]);
}

void print_mat2f(sy_mat2f M) {
    printf("[[%f %f]\n [%f %f]]\n", M.elt[0], M.elt[2], M.elt[1], M.elt[3]);
}

int main(void) {

    sy_vec2f a = {{1.0f, 1.0f}};
    sy_vec2f b = {{2.0f, 2.0f}};
    sy_vec2f c = sy_vec2f_add(a, b);
    print_vec2f(c);

    c = sy_vec2f_sub(c, b);
    print_vec2f(c);

    sy_mat2f m = {.elt = {1.f, 3.f, 2.f, 4.f}};
    print_mat2f(m);

    c = sy_mat2f_vecmul(m, c);
    print_vec2f(c);





    return 0;
}
