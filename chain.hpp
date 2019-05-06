#pragma once

#include <iterator>
#include<iostream>
#include<string>
#include <list>


using namespace std;

namespace itertools{

  template <class T>
  class chain : public list<T>{

  typedef typename list<T>::iterator iterator;

  public:
    chain(T r1,T r2){
      for(auto i : r1){
        list<T>::push_back(i);
      }
      for(auto i : r2){
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
