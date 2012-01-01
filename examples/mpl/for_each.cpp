//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[mplforeach
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

// declare a type that cannot be constructed
struct abstract_type
{
	virtual ~abstract_type() = 0;
};

// declare a normal type, too
struct normal_type
{};

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
				)
			)
			<< FCPPT_TEXT('\n');
	}
};

}

int main()
{
	typedef boost::mpl::vector2<
		abstract_type,
		normal_type
	> types;

	// do the visitation
	fcppt::mpl::for_each<
		types
	>(
		visitor()
	);

}
//]
