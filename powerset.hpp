
namespace itertools{
  template<typename T>
  class powerset : public list<T>{

    typedef typename list<T>::iterator iterator;

  public:

    powerset(list<T>){

    }

    powerset(string s){

    }

    iterator begin() {
      return list<T>::begin();
    }
    iterator end() {
      return list<T>::end();
     }


  };
};
