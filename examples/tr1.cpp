//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[tr1
#include <fcppt/ref.hpp>
#include <fcppt/container/array.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace
{

void
f(
	std::ostream &_stream
)
{
	typedef fcppt::container::array<
		int,
		5
	> i5_array;

	i5_array const array = {{
		0, 1, 2, 3, 4
	}};

	for(
		i5_array::const_iterator it(
			array.begin()
		);
		it != array.end();
		++it
	)
		_stream
			<< *it
			<< ' ';

	_stream << '\n';
}

}

int main()
{
	typedef fcppt::function::object<
		void ()
	> void_function;

	// use std::tr1::bind
	void_function function(
		std::tr1::bind(
			f,
			fcppt::ref(
				std::cout
			)
		)
	);

	function();
}
//]
