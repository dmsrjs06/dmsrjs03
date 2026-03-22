#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "my_fraction.h"

int main(void) {
    int  n1, d1, n2, d2;
    char op, line[128];
    Fraction f1, f2, result;

    fgets(line, sizeof(line), stdin);

    if (sscanf(line, "%d/%d %c %d/%d", &n1, &d1, &op, &n2, &d2) != 5) {
        printf("error!");
        return 1;
    }

    f1 = Create(n1, d1);
    f2 = Create(n2, d2);

    switch (op) {
    case '+': result = Add(f1, f2);
        break;
    case '-': result = Minus(f1, f2);
        break;
    case '*': result = Multiple(f1, f2);
        break;
    case '/': result = Divide(f1, f2);
        break;
    default:
        printf("error!");
        return 1;
    }

    Fstr(result);

    return 0;
}