//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[make_array
#include <fcppt/assign/make_array.hpp>
#include <fcppt/container/array.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>
#include <boost/foreach.hpp>

int main()
{
	typedef fcppt::container::array<int,3> array_int3;

	array_int3 const array(
		fcppt::assign::make_array<int>
			(3)
			(4)
			(5)
	);
	
	BOOST_FOREACH(
		array_int3::const_reference ref,
		array
	)
		fcppt::io::cout
			<< ref
			<< FCPPT_TEXT(' '
		);
}
//]
