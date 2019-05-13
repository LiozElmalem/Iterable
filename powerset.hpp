#include<vector>

using namespace std;

namespace itertools{



// print vecotr(present a subset)
  template <typename V>
  ostream &operator<<(ostream &os, const vector<V> &S){
    os << "{";
    auto it = S.begin();
    if(it != S.end())
    { // first element is without comma seperator.
        os << *it;
        ++it;
    }
    while (it != S.end()){
        os << ',' << *it;
        ++it;
    }
    os << "}";
    return os;
}
//



  template<typename T>
  class powerset{

    T A;

  public:

    powerset(T a) : A(a){}

    template<typename K>
    class iterator{

      public :
      K start;
      K end;
      unsigned int index;

      iterator(K val1,K val2) : start(val1),end(val2){}

      // <decltype(*A),decltype(*B)>
      auto operator*() const{
        K runner = start;
           vector<typename remove_const<typename remove_reference<decltype(*start)>::type>::type> S;

           unsigned int i = index;
           while (i != 0 && runner != end)
           { // convert to binary, each '1' digit is an index of an element.
               unsigned int r = i % 2;
               i = i >> 1; //divide by 2.

               if (r == 1)
                   S.emplace_back(*runner);

               ++runner;
           }

           return S;
      }

      iterator& operator++() { // advaced value
        ++end;
        return *this;
      }

      bool operator!= (const iterator& temp){
        return (start != temp.start) && (end != temp.end);
      }

    };

    auto begin() {return iterator<decltype(A.begin())>(A.begin(), A.end());}
    auto end() {return iterator<decltype(A.begin())>(A.end(), A.end());}

  };
};
