//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/brigand/enum_range.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/back.hpp>
#include <brigand/sequences/front.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

enum class my_enum
{
	test1,
	test2,
	fcppt_maximum = test2
};

}

int
main()
{
	typedef
	fcppt::brigand::enum_range<
		my_enum
	>
	range;

	static_assert(
		brigand::front<
			range
		>::value
		==
		my_enum::test1,
		""
	);

	static_assert(
		brigand::back<
			range
		>::value
		==
		my_enum::test2,
		""
	);
}
