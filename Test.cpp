#include <iostream>
using namespace std;
#include "badkan.hpp"
#include "chain.hpp"
#include "powerset.hpp"
#include "product.hpp"
#include "range.hpp"
#include "zip.hpp"

using namespace itertools;

int main() {

	badkan::TestCase testcase;
	int grade = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	int Temp = 0;
	if (signal == 0) {
	//My_Test
	//range_Test
		testcase.setname("range test");
		 Temp = 0;
		for (int i: range(0,20)) {
			testcase.CHECK_EQUAL(i, Temp);
			Temp++;
		}

		Temp = 8;
		for (int i: range(8,13)) {
			testcase.CHECK_EQUAL(i, Temp);
			Temp++;
		}

		Temp = -6;
		for (int i: range(-6,-1)) {
			testcase.CHECK_EQUAL(i, Temp);
			Temp++;
		}

		Temp = 2;
		for (int i: range(2,2)) {
			testcase.CHECK_EQUAL(i, Temp);
			Temp++;
		}
 
		char Tmp = 'a';
		for (int i: range('a','f')) {
			testcase.CHECK_EQUAL(i, Tmp);
			Tmp++;
		}

		Tmp = 'd';
		for (int i: range('d','l')) {
			testcase.CHECK_EQUAL(i, Tmp);
			Tmp++;
		}

		Tmp = 'u';
		for (int i: range('u','u')) {
			testcase.CHECK_EQUAL(i, Tmp);
			Tmp++;
		}

    //Chain_Test
		testcase.setname("Chain test");
		Temp = 0;
		int arr1[] = {1,2,3,4,5,6,7,8,9,10};
		for(int i: chain(range(1,6), range(5,11))) {
			testcase.CHECK_EQUAL(i, arr1[Temp]);
			Temp++;				
		}

		Temp = 0;
		int arr_2[] = {0,1,2,3,4,5,5,6,7};
		for(int i: chain(range(0,6), range(5,8))) {
			testcase.CHECK_EQUAL(i, arr_2[Temp]);
			Temp++;				
		}

		Temp = 0;
		char arr_3[] = {'a','b','c','d','e','f'};
		for(int i: chain(range('a','d'), range('d','g'))) {
			testcase.CHECK_EQUAL(i, arr_3[Temp]);
			Temp++;				
		}
		
		Temp = 0;
		char arr_4[] = {'a','b','c','A','B','C','D'};
		for(int i: chain(range('a','d'), range('A','E'))) {
			testcase.CHECK_EQUAL(i, arr_4[Temp]);
			Temp++;				
		}
			Temp = 0;
		char arr_5[] = {'D','E','F','G','H','I','J'};
		
		for(int i: chain(range('D','G'), range('G','K')))
		{
			testcase.CHECK_EQUAL(i, arr_5[Temp]);
			Temp++;				
		}

		// Test Zip
		testcase.setname("Test Zip ");
        Temp=0;
        string arr_10[]={"1,t","2,e","3,s","4,t"};
        for (auto pair: zip(range(1,5), string("test"))) {
		testcase.CHECK_OUTPUT(pair,arr_10[Temp]);
		Temp++;
        }

        Temp=0;
		string arr_11[]={"5,c","6,h","7,e","8,c","9,k"};
        for (auto pair: zip(range(5,10), string("check"))) {
		testcase.CHECK_OUTPUT(pair,arr_11[Temp]);
		Temp++;
        }

        Temp=0;
		string arr_12[]={"0,5","1,6","2,7","3,8","4,9"};
        for (auto pair: zip(range(0,5), range(5,10))) {
		testcase.CHECK_OUTPUT(pair,arr_12[Temp]);
		Temp++;
        }

        Temp=0;
		string arr_13[]={"2,e","3,f","4,g","5,h"};
        for (auto pair: zip(range(2,6), range('e','i'))) {
		testcase.CHECK_OUTPUT(pair,arr_13[Temp]);
		Temp++;
        }

        Temp=0;
		string arr_14[]={"A,a","B,b","C,c","D,d"};
        for (auto pair: zip(range('A','E'), range('a','e'))) {
		testcase.CHECK_OUTPUT(pair,arr_14[Temp]);
		Temp++;
}

	
    //Test_Product
        testcase.setname(" TEST PRODUCT");
	    int Temp=0;
		string arr_6[]={"0,e","0,d","1,e","1,d","2,e","2,d"};
        for (auto pair: product(range(0,3), string("ed")))
        {
		testcase.CHECK_OUTPUT(pair,arr_6[Temp]);
		Temp++;
        }
	    Temp=0;
		string arr_7[]={"0,3","0,4","1,3","1,4","2,3","2,4"};
        for (auto pair: product(range(0,3), range(3,5)))
        {
		testcase.CHECK_OUTPUT(pair,arr_7[Temp]);
		Temp++;
        }
	    Temp=0;
		string arr_8[]={"1,a","1,b","2,a","2,b","3,a","3,b","4,a","4,b"};
        for (auto pair: product(range(1,5), range('a','c')))
        {
		testcase.CHECK_OUTPUT(pair,arr_8[Temp]);
		Temp++;
        }
	    Temp=0;
		string arr_9[]={"6,c","6,d","7,c","7,d","8,c","8,d"};
        for (auto pair: product(range(6,9), range('c','e')))
        {
		testcase.CHECK_OUTPUT(pair,arr_9[Temp]);
		Temp++;
        }
     	

		// Test_PowerSet
	    testcase.setname(" Test PowerSet");
	    Temp=0;
		string arr_15[]={"{}","{5}","{6}","{7}","{5,6}","{5,7}","{6,7}","{5,6,7}"};
        for (auto pair: powerset(range(5,8))){
		testcase.CHECK_OUTPUT(pair,arr_15[Temp]);
		Temp++;
}

	    Temp=0;
		string arr_16[]={"{}","{a}","{b}","{1}","{2}","{a,b}","{a,1}","{a,2}","{b,1}","{b,2}","{1,2}","{a,b,1}","{a,b,2}","{a,1,2}","{b,1,2}","{a,b,1,2}"};
        for (auto subset: powerset(chain(range('a','c'),range('1','3')))) {
		testcase.CHECK_OUTPUT(subset,arr_16[Temp]);
		Temp++;
}

	Temp=0;
	string arr_17[]={"{}","{A}","{B}","{C}","{A,B}","{A,C}","{B,C}","{A,B,C}"};
    for (auto subset: powerset(string("ABC"))) {
	  testcase.CHECK_OUTPUT(subset,arr_17[Temp]);
 	   Temp++;
}

    grade = testcase.grade();
	}
	else
	{
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
