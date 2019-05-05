#pragma once

#include <iterator>
#include<iostream>
#include<vector>
#include<string>


using namespace std;

namespace itertools{

  template <class T>
  class chain{

  typedef typename vector<T>::iterator iterator;

  private:
    vector<T> list;
  public:
    chain(T r1,T r2){
      // for(auto i : r1){
      //   list.push_back(i);
      // }
      // for(auto i : r2){
      //   list.push_back(i);
      // }
    }

    iterator begin() {
      return list.begin();
    }
    iterator end() {
      return list.end();
     }


  };
};
