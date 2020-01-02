//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/apply.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <string>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::variant::object<
	std::string,
	int
>
string_or_int;

// ![variant_visitor]
struct print_visitor
{
	template<
		typename T
	>
	std::enable_if_t<
		!std::is_integral<
			T
		>::value,
		void
	>
	operator()(
		T const &_value
	) const
	{
		std::cout
			<< "Not integral: "
			<< _value
			<< '\n';
	}

	template<
		typename T
	>
	std::enable_if_t<
		std::is_integral<
			T
		>::value,
		void
	>
	operator()(
		T const _value
	) const
	{
		std::cout
			<< "Integral: "
			<< _value
			<< '\n';
	}
};
// ![variant_visitor]

void
visit_simple()
{
// ![variant_visitor_apply]
	// Prints "Not integral: Hello World".
	fcppt::variant::apply(
		print_visitor(),
		string_or_int(
			std::string(
				"Hello World"
			)
		)
	);

	// Prints "Integral: 42".
	fcppt::variant::apply(
		print_visitor(),
		string_or_int(
			42
		)
	);
// ![variant_visitor_apply]
}


}

int
main()
{
	visit_simple();
}
