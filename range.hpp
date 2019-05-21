#pragma once

#include <iterator>
#include<iostream>

using namespace std;

namespace itertools{

  template <class T>
  class range{

  T A; // start point
  T B; // end point

  public:

    range(T a,T b) {
      A = a;
      B = b;
    }

    class iterator{
    public :

    T value; // "now" value

    iterator(T val) : value(val){}

    iterator& operator++() // advaced value
    {
        ++value;
        return *this;
    }

    bool operator== (range::iterator const & temp) const
    {
       return value == temp.value;

     }
    bool operator!= (range::iterator const & temp) const
    {
       return value != temp.value;

     }
    T operator*() const
    {
       return value;
     }

    };


    auto begin() const{
      return iterator(A);
    }
    auto end() const{
      return iterator(B);
     }

  };
};
