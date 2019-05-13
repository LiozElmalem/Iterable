#pragma once

#include <iterator>
#include<iostream>

#include <assert.h>

using namespace std;

namespace itertools{

  template <class T>
  class range{

  T A; // start point
  T B; // end point

  public:

    range(T a,T b){
      assert(b >= a);
      // include a and without b
      A = a;
      B = b;
    }

    class iterator{
    public :

    T value;

    iterator(T val) : value(val){}

    iterator& operator++()
    {
        ++value;
        return *this;
    }

    bool operator== (const iterator& temp)
    {
       return value == temp.value;

     }
    bool operator!= (const iterator& temp)
    {
       return value != temp.value;

     }
    T& operator*()
    {
       return value;
     }

    };


    iterator begin() {
      return iterator(A);
    }
    iterator end() {
      return iterator(B);
     }

  };
};
