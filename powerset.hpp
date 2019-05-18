#include<vector>

using namespace std;

namespace itertools{



// print vecotr(present a subvector)
  template <typename Object>
  ostream & operator << (ostream & output, const vector<Object> & input){
    output << "{";
    auto it = input.begin();
    if(it != input.end()) { // first element is without comma seperator.
        output << *it;
        ++it;}
    while (it != input.end()){
        output << ',' << *it;
        ++it;}
    output << "}";
    return output;
}
//////////////////////////////////////////////////



  template<typename CONTAINER>
  class powerset{

    CONTAINER A; // one exactly container

  public:

    powerset(CONTAINER temp) : A(temp){}


    template<typename OBJECT>
    class iterator{

      private :

      ////////// calculate the size of the range /////////
      size_t group_size(OBJECT start_temp,OBJECT final_temp){
        OBJECT runner = start_temp;
        size_t ans = 0;
        while(runner != final_temp){
          ans++;
          ++runner;
        }
        return ans;
      }
      //////////***************************//////////


      public :

      OBJECT start;
      OBJECT final;

      OBJECT runner;

      iterator(OBJECT start_temp,OBJECT final_temp) : start(start_temp),final(final_temp),runner(start_temp){}

      auto operator*() const{
        vector<typename remove_const<typename remove_reference<decltype(*start)>::type>::type> vector; // every call to this operator function the vector is absoulutly new
        if(runner == start)
          vector = {};
        else{
          OBJECT temp = start;
          while(temp != runner){
            vector.emplace_back(* temp);
            ++temp;
          }
        }
        return vector;
      }

      auto operator++() { // advaced value
        ++runner;
        return *this;
      }

      bool operator!= (const iterator & temp){
        return (runner != temp.runner);
      }

    };

    auto begin() const{return iterator<decltype(A.begin())>(A.begin(), A.end());}
    auto end() const{return iterator<decltype(A.begin())>(A.end(), A.end());}

  };
};
