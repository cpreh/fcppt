//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/ref.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <iostream>
#include <ostream>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace
{
//! [variant_nonconst_visitor]
struct visitor
{
	typedef void result_type;

	// operator() takes T as non const ref
	template<
		typename T
	>
	result_type
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

int main()
{
	// typedef a variant that can either hold a string or an int
	typedef fcppt::variant::object<
		boost::mpl::vector2<
			std::string,
			int
		>
	> string_or_int;

//! [variant_nonconst_visitation]
	string_or_int v(
		std::string(
			"Hello World"
		)
	);

	fcppt::variant::apply_unary(
		visitor(),
		fcppt::ref(
			v
		)
	);

	// only prints a newline because the string contains nothing anymore
	std::cout << v.get<std::string>() << '\n';
//! [variant_nonconst_visitation]
}
