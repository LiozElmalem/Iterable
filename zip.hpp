#include <iostream>
#include <list>

namespace itertools{
  template<typename T>
  class zip : public list<T>{

      typedef typename list<T>::iterator iterator;

      public:

        zip(list<T> r1,list<T> r2){
          // pair<T,T> temp;
          // for(auto i = r1.begin(),j = r2.begin() ; i != r1.end(),j != r2.end() ; ++i,++j){
          //   temp(i,j);
          //   list<T>::push_back(temp);
          // }
        }

        zip(list<T> r,string s){
          // pair<T,char> temp;
          // for(auto i = r.begin(),j = s.begin() ; i != r.end(),j != s.end() ; ++i,++j){
          //   temp(i,j);
          //   list<T>::push_back(temp);
          // }
        }
        zip(string s,list<T> r){
        //   pair<T2,char> temp;
        //   for(auto i = r.begin(),j = s.begin() ; i != r.end(),j != s.end() ; ++i,++j){
        //     temp(i,j);
        //     pairs.push_back(temp);
        //   }
        }
        zip(string s1,string s2){
        //   // range<char> temp(s);
        //   // chain(temp,r);
        }
      

        iterator begin() {
          return list<T>::begin();
        }
        iterator end() {
          return list<T>::end();
         }


  };
};
