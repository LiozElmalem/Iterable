#pragma once

#include <iterator>
#include<iostream>
#include<list>
#include<string>

#include <assert.h>

using namespace std;

namespace itertools{

  template <class T>
  class range : public list<T>{

  typedef typename ::list<T>::iterator iterator;

  public:

    range(T a,T b){
      assert(b >= a);
      // include a and without b
      for (auto i = a; i < b; i++) {
        list<T>::push_back(i);
      }
    }

    range(string str){
      for(char i : str){
        list<T>::push_back(i);
      }
    }

    iterator begin() {
      return list<T>::begin();
    }
    iterator end() {
      return list<T>::end();
     }



  };
};
