#ifndef STDAFX_HPP
#define STDAFX_HPP

#include <stdio.h>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>

#define BASE_SPRITE 32

using namespace std;
using namespace sf;

enum map_number {NOCHANGE,MAP1,MAP2,MAP3};

struct Delete 
{ 
   template <class T> void operator ()(T*& p) const 
   { 
      delete p;
      p = NULL;
   } 
}; 





#endif 
