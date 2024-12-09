#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

#ifndef HEADER_HPP
#define HEADER_HPP

class Base
{
    public:
        virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif