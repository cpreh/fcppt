//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[variant
#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/variant/apply_binary.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <cstdlib>
#include <iostream>
#include <ostream>
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
try
{
//! [variant_binary_visitation]
	// typedef a variant that can either hold an int or a string
	typedef fcppt::variant::object<
		boost::mpl::vector2<
			std::string,
			int
		>
	> variant;

	// initialize v with a string
	variant v(
		std::string(
			"Hello World"
		)
	);

	// initialize u with an int
	variant u(
		42
	);

	// do a binary visitation on them
	fcppt::variant::apply_binary(
		visitor(),
		v,
		u
	);
//! [variant_binary_visitation]
}
catch(
	fcppt::exception const &e
)
{
	fcppt::io::cerr()
		<< e.string()
		<< FCPPT_TEXT('\n');

	return EXIT_FAILURE;
}
//]
