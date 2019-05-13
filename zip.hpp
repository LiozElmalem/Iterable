#include <iostream>
#include <utility>

using namespace std;

namespace itertools{

    // print the pair
    template<typename R1,typename R2>
    ostream & operator<<(ostream &os, const pair<R1,R2> & pair){
    os << pair.first << ',' << pair.second;
    return os;
    }
    //

  template<class T1,class T2>

  class zip{

      T1 A1;
      T2 A2;

      public:

        zip(T1 a,T2 b) : A1(a),A2(b){}

        template<typename E1,typename E2>
        class iterator{

        public:

          E1 A;
          E2 B;

          iterator(E1 v1,E2 v2) : A(v1),B(v2){}

          pair <decltype(*A),decltype(*B)> operator*() const
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

        auto begin() {
          return iterator <decltype(A1.begin()),decltype(A2.begin())>(A1.begin(), A2.begin());
        }
        auto end() {
          return iterator <decltype(A1.end()),decltype(A2.end())>(A1.end(), A2.end());
         }

  };
};
