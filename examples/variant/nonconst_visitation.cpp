//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/get_exn.hpp>
#include <fcppt/variant/invalid_get.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace
{
//! [variant_nonconst_visitor]
struct visitor
{
	// operator() takes T as non const ref
	template<
		typename T
	>
	void
	operator()(
		T &_val
	) const
	{
		// reset _val to the default value
		_val = T();
	}
};
//! [variant_nonconst_visitor]
}

int
main()
try
{
	// typedef a variant that can either hold a string or an int
	typedef
	fcppt::variant::variadic<
		std::string,
		int
	>
	string_or_int;

//! [variant_nonconst_visitation]
	string_or_int v(
		std::string(
			"Hello World"
		)
	);

	fcppt::variant::apply_unary(
		visitor(),
		v
	);

	// only prints a newline because the string contains nothing anymore
	std::cout
		<<
		fcppt::variant::get_exn<
			std::string
		>(
			v
		) << '\n';
//! [variant_nonconst_visitation]

	fcppt::variant::get_exn<
		int
	>(
		v
	);

	return
		EXIT_SUCCESS;
}
catch(
	fcppt::variant::invalid_get const &_error
)
{
	fcppt::io::cerr()
		<<
		_error.string()
		<<
		FCPPT_TEXT('\n');

	return
		EXIT_SUCCESS;
}
