//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//! [mpl_for_each]
#include <fcppt/text.hpp>
#include <fcppt/type_name.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/mpl/for_each.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
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

// Declare our functor that is invoked on each type
struct visitor
{
	typedef void result_type;

	template<
		typename Type
	>
	result_type
	operator()() const
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
	typedef boost::mpl::vector2<
		abstract_type,
		normal_type
	> types;

	// Do the visitation
	fcppt::mpl::for_each<
		types
	>(
		visitor()
	);
}
//! [mpl_for_each]
