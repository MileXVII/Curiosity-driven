#include <stdio.h>
#include <stdlib.h>

struct fract {
    int num;
    int den;
};

/*  Create a new fraction, setting num and den as the numerator
    and denominator of the fraction.
    otherwise The faction object is returned. */
struct fract create_fraction(int num, int den) {
    struct fract f;
    f.num = num;
    f.den = den;
    return f;
}

/* Simplify the provided fraction. */
void simplify_fraction(struct fract *f) {
    for (int d = 2; d <= f->num && d <= f->den; d++) {
        while (f->num % d == 0 && f->den % d == 0) {
            f->num /= d;
            f->den /= d;
           }
    }
}

void print_fraction(struct fract *f) {
    printf("%d/%d\n", f->num, f->den);
}

int main(void) {
    struct fract f1 = create_fraction(10, 20);
    struct fract f2 = create_fraction(3, 4);
    simplify_fraction(&f1);
    print_fraction(&f1);
    print_fraction(&f2);
    return 0;

}
