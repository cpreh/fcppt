//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <iostream>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace
{

void
visit_simple()
{
	typedef fcppt::variant::object<
		boost::mpl::vector2<
			std::string,
			int
		>
	> string_or_int;

// ![variant_visit_simple]
	struct print_visitor
	{
		typedef
		void
		result_type;

		result_type
		operator()(
			std::string const &_string
		) const
		{
			std::cout
				<< _string
				<< '\n';
		}

		result_type
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
struct print_visitor2
{
	typedef
	void
	result_type;

	template<
		typename T
	>
	result_type
	operator()(
		T const &_arg
	) const
	{
		std::cout
			<< _arg
			<< '\n';
	}
};
// ![variant_visit_template]

}

int
main()
{
	visit_simple();

	print_visitor2()(
		42
	);
}
