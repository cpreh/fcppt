//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[tr1
#include <fcppt/tr1/functional.hpp>
#include <fcppt/tr1/array.hpp>
#include <fcppt/function/object.hpp>
#include <boost/foreach.hpp>
#include <ostream>
#include <iostream>
#include <iosfwd>

namespace
{

void
f(
	std::ostream &stream_
)
{
	// use std::tr1::array
	typedef std::tr1::array<
		int,
		5
	> i5_array;

	i5_array const array_ = {{
		0, 1, 2, 3, 4
	}};

	BOOST_FOREACH(
		i5_array::const_reference ref,
		array_
	)
		stream_
			<< ref
			<< ' ';
	
	stream_ << '\n';
}

}

int main()
{
	typedef fcppt::function::object<
		void ()
	> void_function;

	// use std::tr1::bind and std::tr1::ref
	void_function function_(
		std::tr1::bind(
			f,
			std::tr1::ref(
				std::cout
			)
		)
	);

	function_();
}
//]
