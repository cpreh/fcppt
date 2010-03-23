//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[variant
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/apply_binary.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <ostream>
#include <cstdlib>

namespace
{

// create a binary visitor
struct visitor
{
	// note: it is important to specify the result_type as a typedef
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
		fcppt::io::cout
			<< t1
			<< FCPPT_TEXT(' ')
			<< t2
			<< FCPPT_TEXT('\n');
	}
};
}

int main()
try
{
	// typedef a variant that can either hold an int or a string
	typedef fcppt::variant::object<
		boost::mpl::vector2<
			int,
			fcppt::string
		>
	> variant;

	// initialize v with a string
	variant v(
		fcppt::string(
			FCPPT_TEXT("blabla")
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
