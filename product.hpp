#pragma once

#include <utility>
#include <iostream>

using namespace std;

namespace itertools{
  template<typename T1,typename T2>
  class product{

          T1 A1;
          T2 A2;

          public:

            product(T1 a,T2 b) : A1(a),A2(b){}

            template<typename E1,typename E2>
            class iterator{

            public:

              E1 A;
              E2 B;

              E2 C; // for b loops

              iterator(E1 v1,E2 v2) : A(v1),B(v2),C(v2){}

              pair <decltype(*A),decltype(*B)> operator*() const
              {
               return std::pair< decltype(*A),decltype(*B)> (*A,*B);
              }

              iterator& operator++() // advaced value
              {
                  //   ++A;
                  //   ++B;
                  // return *this;
              }

              bool operator!= (const iterator& temp)
              {
                // return (A != temp.A) && (B != temp.B);
               }

            };

            auto begin() {
              return iterator <decltype(A1.begin()),decltype(A2.begin())>(A1.begin(), A2.begin());
             }
            auto end() {
              return iterator <decltype(A1.end()),decltype(A2.end())>(A1.end(), A2.end());
             }


  };
};
