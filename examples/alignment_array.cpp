//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//! [alignment_array]
#include <fcppt/alignment/array.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/alignment_of.hpp>
#include <new>
#include <fcppt/config/external_end.hpp>

namespace
{

// Declare a test class
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

int
main()
{
	// Create an array with proper alignment for mystruct
	typedef fcppt::alignment::array<
		unsigned char,
		sizeof(mystruct),
		boost::alignment_of<
			mystruct
		>::value
	>::type raw_array;

	raw_array storage;

	// Now placement new can be used
	mystruct *ptr = new (storage.data()) mystruct();

	// Don't forget to call its destructor manually
	ptr->~mystruct();
}
//! [alignment_array]
