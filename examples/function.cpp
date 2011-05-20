//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[function
#include <fcppt/function/object.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/assert.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>

#include <boost/spirit/home/phoenix/core/reference.hpp>
#include <boost/spirit/home/phoenix/operator/self.hpp>

#include <ostream>
#include <cstdlib>

namespace
{

// a normal function object without a return type
struct functor1
{
	void operator() ()
	{
		fcppt::io::cout << FCPPT_TEXT("functor1\n");
	}
};

// a function object that also overloads operator &
struct functor2
{
	void operator() ()
	{
		fcppt::io::cout << FCPPT_TEXT("functor2\n");
	}

	float operator&()
	{
		static float f = 0.f;

		return f;
	}
};

// a function object with a return type
struct functor3
{
	int operator() ()
	{
		fcppt::io::cout << FCPPT_TEXT("functor3\n");

		return 5;
	}

};

// a function object with a return type and a parameter
struct functor4
{
	 int operator() ( int )
	 {
		fcppt::io::cout << FCPPT_TEXT("functor4\n");

		return 7;
	 }

};

// a free function
void function1()
{
	fcppt::io::cout << FCPPT_TEXT("function1\n");
}

}

int main()
try
{
	functor1 f1;
	functor2 f2;
	functor3 f3;
	functor4 f4;

	fcppt::function::object< void ()     > f_1( f1 );
	fcppt::function::object< void ()     > f_2( f2 );
	fcppt::function::object< void ()     > f_3( function1 );
	fcppt::function::object< int  ()     > f_4( f3 );
	fcppt::function::object< int ( int ) > f_5( f4 );

	f_1();
	f_2();
	f_3();

	fcppt::io::cout << f_4() << std::endl;
	fcppt::io::cout << f_5( 7 ) << std::endl;

	bool b = true;

	// test a phoenix functor
	fcppt::function::object<void()>(
		boost::phoenix::ref(b) = false
	)();

	FCPPT_ASSERT( b == false );
}
catch(
	fcppt::exception const &e
)
{
	fcppt::io::cerr
		<< e.string()
		<< FCPPT_TEXT('\n');

	return EXIT_FAILURE;
}
//]
