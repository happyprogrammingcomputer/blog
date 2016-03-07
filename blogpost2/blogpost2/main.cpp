
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <iostream>
#include <vector>
#include <string>
#include "catch.hpp"

//### INDENT TWO TABS SO TUMBLR MARKS CODE AS CODE


using std::vector;
using std::string;


class DateTime {
};

		DateTime FindNextYear(DateTime dt){
			return DateTime();
		}


////////////////////////////////////////		PLAIN_EXAMPLE



namespace PLAIN_EXAMPLE {

		struct post {
			//... functions go here.
			private:
				int _date;
				string _message;
		};

		struct person {
			public:
				person(){};
				person(string name, string title, string email,
					vector<post> posts) :
					_name(name),
					_title(title),
					_email(email),
					_posts(posts)
				{
				}
				person(const person& rhs);
				person& operator=(const person& rhs);
				void swap(person& other);

				string get_name() const { return _name; }
				string get_title() const { return _title; }
				string get_email() const { return _email; }
				vector<post> get_posts() const { return _posts; }

			////////  STATE
			private:
				string _name;
				string _title;
				string _email;
				vector<post> _posts;
		};

		TEST_CASE( "constructor", "[PLAIN_EXAMPLE]" ) {
			auto a = person();
			REQUIRE(a.get_name() == "");
			REQUIRE(a.get_title() == "");
			REQUIRE(a.get_email() == "");
			REQUIRE(a.get_posts().size() == 0);
		}

		TEST_CASE("manual mutation", "[PLAIN_EXAMPLE]"){
			person a("Bob", "Mr", "bob@gmail.com", vector<post>());
			person b = person("Bob_v2", a.get_title(), a.get_email(), a.get_posts());

			REQUIRE(a.get_name() == "Bob");
			REQUIRE(a.get_title() == "Mr");
			REQUIRE(a.get_email() == "bob@gmail.com");

			REQUIRE(b.get_name() == "Bob_v2");
			REQUIRE(b.get_title() == "Mr");
			REQUIRE(b.get_email() == "bob@gmail.com");
		}
}


namespace SET_NAME_EXAMPLE {

		struct post {
			//... functions go here.
			private:
				int _date;
				string _message;
		};

		struct person {
			public:
				person(){};
				person(string name, string title, string email,
					vector<post> posts) :
					_name(name),
					_title(title),
					_email(email),
					_posts(posts)
				{
				}
				person(const person& rhs) :
					_name(rhs._name),
					_title(rhs._title),
					_email(rhs._email),
					_posts(rhs._posts)
				{
				}
				person& operator=(const person& rhs);
				void swap(person& other);

				string get_name() const { return _name; }
				string get_title() const { return _title; }
				string get_email() const { return _email; }
				vector<post> get_posts() const { return _posts; }


				person set_name(const string& name) const{
					person result = *this;
					result._name = name;
					return result;
				}

			////////  STATE
			private:
				string _name;
				string _title;
				string _email;
				vector<post> _posts;
		};


		TEST_CASE("set_name()", "[SET_NAME_EXAMPLE]"){
			person a("Bob", "Mr", "bob@gmail.com", vector<post>());
			person b = a.set_name("Bob_v2");

			REQUIRE(a.get_name() == "Bob");
			REQUIRE(a.get_title() == "Mr");
			REQUIRE(a.get_email() == "bob@gmail.com");

			REQUIRE(b.get_name() == "Bob_v2");
			REQUIRE(b.get_title() == "Mr");
			REQUIRE(b.get_email() == "bob@gmail.com");
		}

}



////////////////////////////////////////		C++ swap() and operator=()



		TEST_CASE( "swap()", "[C++ value and identity]" ) {
			string a = "hello";
			string b = "goodbye";

			a.swap(b);

			/*
				Both string values are unchanged, we just change the
				variable a and b to refer to different values. We
				mutated a and b, not the string values.
			*/
			REQUIRE(a == "goodbye");
			REQUIRE(b == "hello");
		}

		TEST_CASE( "operator=()", "[C++ value and identity]" ) {
			string a = "hello";
			string b = "goodbye";

			a = b;

			/*
				Both string values are unchanged. We can no longer
				reach "hello" since we have no variable refering to it.
			*/
			REQUIRE(a == "goodbye");
			REQUIRE(b == "goodbye");
		}




unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}


/*
int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}
*/
