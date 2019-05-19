#include <iostream>
#include <utility>

using namespace std;

namespace itertools{

    // print the pair
    template<typename R1,typename R2>
    ostream & operator << (ostream & output, const pair<R1,R2> & pair){
    output << pair.first << ',' << pair.second;
    return output;
    }
    //

  template<class CONTAINER_1,class CONTAINER_2>

  class zip{

      CONTAINER_1 A1;
      CONTAINER_2 A2;

      public:

        zip(CONTAINER_1 a,CONTAINER_2 b) : A1(a),A2(b){}

        template<typename E1,typename E2>
        class iterator{

        public:

          E1 A;
          E2 B;

          iterator(E1 v1,E2 v2) : A(v1),B(v2){}

          auto operator*() const
          {
           return pair< decltype(*A),decltype(*B)> (*A,*B);
          }

          iterator& operator++() // advaced value
          {
                ++A;
                ++B;
              return *this;
          }

          bool operator!= (const iterator& temp)
          {
            return (A != temp.A) && (B != temp.B);
           }

        };

        auto begin() const{
          return iterator <decltype(A1.begin()),decltype(A2.begin())>(A1.begin(), A2.begin());
        }
        auto end() const{
          return iterator <decltype(A1.end()),decltype(A2.end())>(A1.end(), A2.end());
         }

  };
};
