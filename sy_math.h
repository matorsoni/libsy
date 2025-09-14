#ifndef SY_MATH_H
#define SY_MATH_H

/*************************************
*                                    *
 *           vec2f & mat2f            *
*                                    *
*************************************/
typedef union sy_vec2f sy_vec2f;
union sy_vec2f {
    float elt[2];
    //struct { float x, y; };
};

typedef union sy_mat2f sy_mat2f;
union sy_mat2f {
    float    elt[4];
    sy_vec2f col[2];
};

static inline sy_vec2f sy_vec2f_add(sy_vec2f a, sy_vec2f b) {
    sy_vec2f res;
    res.elt[0] = a.elt[0] + b.elt[0];
    res.elt[1] = a.elt[1] + b.elt[1];
    return res;
}

static inline sy_vec2f sy_vec2f_mul(sy_vec2f a, sy_vec2f b) {
    sy_vec2f res;
    res.elt[0] = a.elt[0] * b.elt[0];
    res.elt[1] = a.elt[1] * b.elt[1];
    return res;
}

static inline sy_vec2f sy_vec2f_sub(sy_vec2f a, sy_vec2f b) {
    sy_vec2f res;
    res.elt[0] = a.elt[0] - b.elt[0];
    res.elt[1] = a.elt[1] - b.elt[1];
    return res;
}

static inline sy_vec2f sy_vec2f_div(sy_vec2f a, sy_vec2f b) {
    sy_vec2f res;
    res.elt[0] = a.elt[0] / b.elt[0];
    res.elt[1] = a.elt[1] / b.elt[1];
    return res;
}

static inline sy_vec2f sy_vec2f_scale(sy_vec2f a, float s) {
    sy_vec2f res;
    res.elt[0] = a.elt[0] * s;
    res.elt[1] = a.elt[1] * s;
    return res;
}

static inline float sy_vec2f_dot(sy_vec2f a, sy_vec2f b) {
    return a.elt[0] * b.elt[0] + a.elt[1] * b.elt[1];
}

static inline sy_vec2f sy_mat2f_vecmul(sy_mat2f A, sy_vec2f v) {
    sy_vec2f res;
    res.elt[0] = A.elt[0] * v.elt[0] + A.elt[2] * v.elt[1];
    res.elt[1] = A.elt[1] * v.elt[0] + A.elt[3] * v.elt[1];
    return res;
}

static inline sy_mat2f sy_mat2f_matmul(sy_mat2f A, sy_mat2f B) {
    sy_mat2f res;
    res.col[0] = sy_mat2f_vecmul(A, B.col[0]);
    res.col[1] = sy_mat2f_vecmul(A, B.col[1]);
    return res;
}

static inline sy_mat2f sy_mat2f_add(sy_mat2f A, sy_mat2f B) {
    sy_mat2f res;
    res.col[0] = sy_vec2f_add(A.col[0], B.col[0]);
    res.col[1] = sy_vec2f_add(A.col[1], B.col[1]);
    return res;
}

static inline sy_mat2f sy_mat2f_mul(sy_mat2f A, sy_mat2f B) {
    sy_mat2f res;
    res.col[0] = sy_vec2f_mul(A.col[0], B.col[0]);
    res.col[1] = sy_vec2f_mul(A.col[1], B.col[1]);
    return res;
}

static inline sy_mat2f sy_mat2f_sub(sy_mat2f A, sy_mat2f B) {
    sy_mat2f res;
    res.col[0] = sy_vec2f_sub(A.col[0], B.col[0]);
    res.col[1] = sy_vec2f_sub(A.col[1], B.col[1]);
    return res;
}

//static inline sy_mat2f sy_mat2f_inv(sy_mat2f A) {
//    sy_mat2f res;
//    return res;
//}

static inline sy_mat2f sy_mat2f_scale(sy_mat2f A, float s) {
    sy_mat2f res;
    res.col[0] = sy_vec2f_scale(A.col[0], s);
    res.col[1] = sy_vec2f_scale(A.col[1], s);
    return res;
}



#endif  /* SY_MATH_H */
