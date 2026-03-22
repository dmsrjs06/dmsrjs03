#ifndef MY_FRACTION_H
#define MY_FRACTION_H

typedef int Fraction;

Fraction Create(int num, int den);
int Getnum(Fraction f);
int Getden(Fraction f);
Fraction Add(Fraction f1, Fraction f2);
Fraction Minus(Fraction f1, Fraction f2);
Fraction Multiple(Fraction f1, Fraction f2);
Fraction Divide(Fraction f1, Fraction f2);
Fraction Simplify(Fraction f);
void Fstr(Fraction f);

#endif