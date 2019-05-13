

#include <iostream>
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
#define COMMA ,


using namespace std;
using namespace itertools;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

    testcase.setname("test for itertools homework")
    .CHECK_OK(range<int> temp(1,4))
		// .CHECK_OK(range<char> r("hello"))
    // .CHECK_OK(chain<char> e3("a,y","y,z"))
    // .CHECK_OK (chain f(range e(1,6),range h(7,10)))
    // .CHECK_OK(chain<char>(range<int>(1,6),range<char>("abaaa")))
    // .CHECK_OK(chain(range<int>(1,4),"assssdda"))
    // .CHECK_OK(chain("asgcfhagsbh",range(90,100)))
    // .CHECK_OK(zip(range(1,6), string("hello")))
    // .CHECK_OK(zip(range(1,4), string("xyz")),zip(string("abc"),range(6,9))))
    // .CHECK_OK(zip e(chain u(range r1(9,10),range r2(11,12)), "hello"))

    ;

    grade = testcase.grade();
  }else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
