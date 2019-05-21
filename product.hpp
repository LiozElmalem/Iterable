#pragma once

#include <utility>
#include <assert.h>

// print the pair
// taken from zip.hpp and present the same idea



using namespace std;

namespace itertools{


  bool flag = false; // variable that pointing on the B iterator length


  template<typename CONTAINER_1,typename CONTAINER_2>
  class product{

          CONTAINER_1 A1;
          CONTAINER_2 A2;

          public:

            product(CONTAINER_1 a,CONTAINER_2 b) : A1(a),A2(b) {
              flag = false;
              if(!(b.begin() != b.end())) // private check for b iterator
              flag = true;
            }

            template<typename E1,typename E2>
            class iterator{

            public:

              E1 begin_A; // start first

              E2 begin_B; // start second

              E2 temp_begin_B; // back to start with b temp

              bool ready_for_next_round; // sign the position


              iterator(E1 v1,E2 v2) : begin_A(v1),begin_B(v2),temp_begin_B(v2),ready_for_next_round(false){}

              auto operator*() const
              {
               return pair<decltype(*begin_A),decltype(*begin_B)> (*begin_A,*begin_B);
              }

              iterator& operator++() { // advaced value
              if(!ready_for_next_round)
              ++begin_B;
              return *this;
              }

              bool operator!= (iterator const & temp)
              {
                if ((begin_A != temp.begin_A) && !(begin_B != temp.begin_B)){
                    ready_for_next_round = true;
                  }
                if(ready_for_next_round){
                  begin_B = temp_begin_B;
                  ++begin_A;
                  ready_for_next_round = false;
                }
                return (begin_A != temp.begin_A && !flag); // check flag --
              }

            };

            auto begin() const {
              return iterator<decltype(A1.begin()),decltype(A2.begin())>(A1.begin(), A2.begin());
             }
            auto end() const {
              return iterator<decltype(A1.end()),decltype(A2.end())>(A1.end(), A2.end());
             }


  };
};
