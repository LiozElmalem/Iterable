#pragma once

#include <iterator>
#include<iostream>
#include<string>
#include <list>


using namespace std;

namespace itertools{

  template <typename T>
  class chain : public list<T>{

  typedef typename ::list<T>::iterator iterator;

  public:

    chain(list<T> r1,list<T> r2){
      for(auto i : r1){
        list<T>::push_back(i);
      }
      for(auto i : r2){
        list<T>::push_back(i);
      }
    }

    // private case for string
    chain(list<T> r,string s){
      for(auto i : r){
        list<T>::push_back(i);
      }
      for(auto i : s){
        list<T>::push_back(i);
      }
    }
    chain(string s,list<T> r){
      for(auto i : s){
        list<T>::push_back(i);
      }
      for(auto i : r){
        list<T>::push_back(i);
      }
    }
    chain(string s1,string s2){
      for(auto i : s1){
        list<T>::push_back(i);
      }
      for(auto i : s2){
        list<T>::push_back(i);
      }
    }
    // end string case

    iterator begin() {
      return list<T>::begin();
    }
    iterator end() {
      return list<T>::end();
     }


  };
};
