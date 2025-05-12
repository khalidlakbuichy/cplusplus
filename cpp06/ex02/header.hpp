#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <typeinfo>


#ifndef HEADER_HPP
#define HEADER_HPP

class Base
{
    public:
        virtual ~Base() {} // make the class polymorphic becasue dynamic_cast needs a polymorphic type
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif