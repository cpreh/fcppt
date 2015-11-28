//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <iostream>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::variant::variadic<
	std::string,
	int
>
string_or_int;

void
visit_simple()
{
// ![variant_visit_simple]
	struct print_visitor
	{
		void
		operator()(
			std::string const &_string
		) const
		{
			std::cout
				<< _string
				<< '\n';
		}

		void
		operator()(
			int const _value
		) const
		{
			std::cout
				<< _value
				<< '\n';
		}
	};

	// prints "Hello World"
	fcppt::variant::apply_unary(
		print_visitor(),
		string_or_int(
			std::string(
				"Hello World"
			)
		)
	);

	// prints 42
	fcppt::variant::apply_unary(
		print_visitor(),
		string_or_int(
			42
		)
	);
// ![variant_visit_simple]
}


// ![variant_visit_template]
auto const print_visitor2(
	[](
		auto const &_arg
	)
	{
		std::cout
			<< _arg
			<< '\n';
	}
);
// ![variant_visit_template]

// ![variant_match]
void
match_test(
	string_or_int const &_variant
)
{
	fcppt::variant::match(
		_variant,
		[](
			std::string const &_string
		)
		{
			std::cout
				<< "We have a string "
				<< _string
				<< '\n';
		},
		[](
			int const _int
		)
		{
			std::cout
				<< "We have an int "
				<< _int
				<< '\n';
		}
	);
}
// ![variant_match]

}

int
main()
{
	visit_simple();

	print_visitor2(
		42
	);

	match_test(
		string_or_int(
			std::string(
				"test"
			)
		)
	);
}
