//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/enum_from_string.hpp>
#include <fcppt/enum_max_value.hpp>
#include <fcppt/enum_names_array.hpp>
#include <fcppt/enum_names_impl_fwd.hpp>
#include <fcppt/enum_to_string.hpp>
#include <fcppt/make_enum_range.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/enum_to_underlying.hpp>
#include <fcppt/container/enum_array.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>


namespace
{

//! [enum_maximum]
enum class myenum
{
	val1,
	val2,
	fcppt_maximum = val2
};

void
print_enum(
	myenum const _value
)
{
	std::cout
		<<
		// Convert to an integer
		fcppt::cast::enum_to_underlying(
			_value
		)
		<< '\n';

}

void
print()
{
	print_enum(
		fcppt::enum_max_value<
			myenum
		>::value
	);
}
//! [enum_maximum]

void
iterate()
{
// ![enum_range]
	// Prints 0, 1
	for(
		myenum const value
		:
		fcppt::make_enum_range<
			myenum
		>()
	)
		print_enum(
			value
		);
// ![enum_range]
}

void
enum_array()
{
// ![enum_array]
	typedef
	fcppt::container::enum_array<
		myenum,
		bool
	>
	array;

	// Requires three {} pairs because the array wraps std::array
	// internally
	array const val{{{
		true,
		false
	}}};

	std::cout
		<<
		val[myenum::val1]
		<<
		'\n';
// ![enum_array]
}

}

// ![enum_names]
namespace
{

fcppt::enum_names_array<
	myenum
> const names{{{
	FCPPT_TEXT("val1"),
	FCPPT_TEXT("val2")
}}};

}

namespace fcppt
{

template<>
struct enum_names_impl<
	myenum
>
{
	static
	fcppt::enum_names_array<
		myenum
	> const &
	get()
	{
		return
			names;
	}
};

}
// ![enum_names]

namespace
{

void
enum_to_string()
{
// ![enum_to_string]
	myenum const test{
		myenum::val2
	};

	fcppt::string const converted{
		fcppt::enum_to_string(
			test
		)
	};
// ![enum_to_string]
	fcppt::io::cout()
		<<
		converted
		<<
		FCPPT_TEXT('\n');
}

void
enum_from_string()
{
// ![enum_from_string]
	// Returns an empty optional
	fcppt::optional::object<
		myenum
	> const enum1{
		fcppt::enum_from_string<
			myenum
		>(
			FCPPT_TEXT("test")
		)
	};

	// Returns myenum::val1
	fcppt::optional::object<
		myenum
	> const enum2{
		fcppt::enum_from_string<
			myenum
		>(
			FCPPT_TEXT("val1")
		)
	};
// ![enum_from_string]

	fcppt::io::cout()
		<<
		enum1.has_value()
		<<
		FCPPT_TEXT('\n')
		<<
		enum2.has_value()
		<<
		FCPPT_TEXT('\n');
}

}

int
main()
{
	print();

	iterate();

	enum_array();

	enum_to_string();

	enum_from_string();
}
