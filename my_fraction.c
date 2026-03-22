#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "my_fraction.h"
#define MAX 100

typedef int Fraction;

static int nums[MAX];
static int dens[MAX];
static int top = 0;


Fraction Create(int num, int den) {
    if (den == 0) {
        printf("error");
        exit(1);
    }
    if (den < 0) {
        num = -num;
        den = -den;
    }
    nums[top] = num;
    dens[top] = den;
    return top++;
}

int Getnum(Fraction f) {
    return nums[f];
}

int Getden(Fraction f) {
    return dens[f];
}

Fraction Simplify(Fraction f) {
    int* num = &nums[f];
    int* den = &dens[f];
    int  i;
    int  abnum;

    if (*den < 0) {
        *num = -(*num);
        *den = -(*den);
    }
    if (*num == 0) {
        *den = 1;
        return f;
    }

    abnum = (*num < 0) ? -(*num) : (*num);

    for (i = 2; i <= abnum && i <= *den; i++) {
        while (abnum % i == 0 && *den % i == 0) {
            abnum = abnum / i;
            *den = *den / i;
            if (*num < 0) *num = -abnum;
            else          *num = abnum;
        }
    }

    return f;
}



Fraction Add(Fraction f1, Fraction f2) {
    int num = nums[f1] * dens[f2] + nums[f2] * dens[f1];
    int den = dens[f1] * dens[f2];
    return Simplify(Create(num, den));
}

Fraction Minus(Fraction f1, Fraction f2) {
    int num = nums[f1] * dens[f2] - nums[f2] * dens[f1];
    int den = dens[f1] * dens[f2];
    return Simplify(Create(num, den));
}

Fraction Multiple(Fraction f1, Fraction f2) {
    int num = nums[f1] * nums[f2];
    int den = dens[f1] * dens[f2];
    return Simplify(Create(num, den));
}

Fraction Divide(Fraction f1, Fraction f2) {
    if (nums[f2] == 0) {
        printf("error");
        exit(1);
    }
    int num = nums[f1] * dens[f2];
    int den = dens[f1] * nums[f2];
    return Simplify(Create(num, den));
}

void Fstr(Fraction f) {
    printf("%d/%d\n", nums[f], dens[f]);
}