//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//! [brigand_for_each]
#include <fcppt/tag.hpp>
#include <fcppt/text.hpp>
#include <fcppt/type_name.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/brigand/for_each.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


namespace
{

// Declare a type that cannot be constructed
struct abstract_type
{
	virtual ~abstract_type() = 0;
};

// Declare a constructible type, too
struct normal_type
{
};

// Declare our function that is invoked on each type
struct visitor
{
	typedef void result_type;

	template<
		typename Type
	>
	result_type
	operator()(
		fcppt::tag<
			Type
		>
	) const
	{
		// use fcppt::type_name to print the type
		fcppt::io::cout()
			<< fcppt::type_name(
				typeid(
					Type
				).name()
			)
			<< FCPPT_TEXT('\n');
	}
};

}

int
main()
{
	// Declare a vector of two ones, where one is not constructible
	typedef
	brigand::list<
		abstract_type,
		normal_type
	>
	types;

	// Do the visitation
	fcppt::brigand::for_each<
		types
	>(
		visitor()
	);
}
//! [brigand_for_each]
