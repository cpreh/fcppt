//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[alignment_new
#include <fcppt/alignment/array.hpp>
#include <boost/type_traits/alignment_of.hpp>
#include <new>

namespace
{

// declare a test class
struct mystruct
{
	int i;
	float f;

	mystruct()
	:
		i(42),
		f(3.5f)
	{}
};

}

int main()
{
	// create an array with proper alignment for mystruct
	typedef fcppt::alignment::array<
		unsigned char,
		sizeof(mystruct),
		boost::alignment_of<
			mystruct
		>::value
	>::type raw_array;

	raw_array array_;

	// now placement new can be used
	new (array_.data()) mystruct();
}
//]
