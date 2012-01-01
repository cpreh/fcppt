//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/apply_binary.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace
{
//! [variant_binary_visitor]
struct visitor
{
	typedef void result_type;

	template<
		typename T1,
		typename T2
	>
	result_type
	operator()(
		T1 const &t1,
		T2 const &t2
	) const
	{
		std::cout
			<< t1
			<< ' '
			<< t2
			<< '\n';
	}
};
//! [variant_binary_visitor]
}

int main()
{
	// typedef a variant that can either hold a string or an int
	typedef fcppt::variant::object<
		boost::mpl::vector2<
			std::string,
			int
		>
	> string_or_int;

//! [variant_binary_visitation]
	string_or_int v(
		std::string(
			"Hello World"
		)
	);

	string_or_int u(
		42
	);

	// Does a binary visitation with visitor(),
	// prints "Hello World" 42
	fcppt::variant::apply_binary(
		visitor(),
		v,
		u
	);
//! [variant_binary_visitation]
}
