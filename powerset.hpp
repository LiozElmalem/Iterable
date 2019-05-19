#include<vector> // dinamic array
#include<cmath> // for pow(x,n)

using namespace std;

namespace itertools{

// print vecotr(present a subvector)
  template <typename OBJECT>
  ostream & operator << (ostream & output, const vector<OBJECT> & input){
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
////////*****************//////////


  template<typename CONTAINER>
  class powerset{

    CONTAINER A; // one exactly container

  public:

    powerset(CONTAINER temp) : A(temp){}


    template<typename OBJECT>
    class iterator{

      private :

      vector<vector<OBJECT>>  getAllSubsets(const vector<OBJECT> & set){
        vector<vector<OBJECT>> subset;
          vector<OBJECT> empty;
          subset.push_back( empty );
          for (int i = 0; i < set.size(); i++){
              vector<vector<OBJECT>> subsetTemp = subset;
              for (int j = 0; j < subsetTemp.size(); j++)
                  subsetTemp[j].push_back( set[i] );
              for (int j = 0; j < subsetTemp.size(); j++)
                  subset.push_back( subsetTemp[j] );
          }
          return subset;
      }

      vector<OBJECT> change(const OBJECT i,const OBJECT j){
        vector<OBJECT> ans;
        OBJECT runner = i;
        while(runner != j){
          ans.push_back(runner);
          ++runner;
        }
        return ans;
      }

      size_t length(const OBJECT start,const OBJECT final){
        OBJECT runner = start;
        size_t ans = 0;
        while(runner != final){
          ans++;
          ++runner;
        }
        return pow(2,ans);
      }

      public :

      OBJECT start;
      OBJECT final;

      uint index;

      size_t size;

      vector<vector<OBJECT>> list;

      iterator(OBJECT start_temp,OBJECT final_temp) : start(start_temp),final(final_temp),size(length(start_temp,final_temp)),index(0){}

      auto operator*(){
        vector<OBJECT> v = change(start,final);
        list = getAllSubsets(v);
        vector<typename remove_const<typename remove_reference<decltype(*start)>::type>::type> vector; // every call to this operator function the vector is absoulutly new
        for(auto i : list[index]){
        vector.push_back(*i);
        }
        return vector;
      }

      auto operator++() { // advaced value
        ++index;
        return *this;
      }

      bool operator!= (const iterator & temp){
        return (index != size);
      }

    };

    auto begin() const{return iterator<decltype(A.begin())>(A.begin(), A.end());}
    auto end() const{return iterator<decltype(A.begin())>(A.end(), A.end());}

  };
};
