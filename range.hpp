#pragma once

#include <iterator>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

namespace itertools{

  template <class T>
  class range{

  typedef typename vector<T>::iterator iterator;

  private:
    vector<T> list;
  public:

    range(T a,T b){
      // include a and without b
      for (auto i = a; i < b; i++) {
        list.push_back(i);
      }
    }
    range(string str){
      for (size_t i = 0; i < str.length(); i++) {
        list.push_back(str[i]);
      }
    }
    vector<T> get(){
      return list;
    }

    iterator begin() {
      return list.begin();
    }
    iterator end() {
      return list.end();
     }



  };
};
