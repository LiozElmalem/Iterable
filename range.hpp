#pragma once

#include <iterator>
#include<iostream>
#include<list>
#include<string>



using namespace std;

namespace itertools{

  template <class T>
  class range : public list<T>{

  typedef typename ::list<T>::iterator iterator;

  public:

    range(T a,T b){
      // include a and without b
      list<T>();
      for (auto i = a; i < b; i++) {
        list<T>::push_back(i);
      }
    }

    list<T> get(){
      return list<T>::get();
    }

    iterator begin() {
      return list<T>::begin();
    }
    iterator end() {
      return list<T>::end();
     }



  };
};
