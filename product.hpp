#pragma once

#include <list>
#include <iostream>

namespace itertools{
  template<typename T>
  class product : public list<T>{

    typedef typename list<T>::iterator iterator;

    public:

    product(list<T> r1,list<T> r2){

    }

    product(list<T> r,string s){

    }

    product(string s,list<T> r){

    }

    product(string s1,string s2){
      
    }

    iterator begin() {
      return list<T>::begin();
    }
    iterator end() {
      return list<T>::end();
     }

  };
};
