//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/mpl/enum_range.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/front.hpp>
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
	fcppt::mpl::enum_range<
		my_enum
	>::type
	range;

	static_assert(
		boost::mpl::front<
			range
		>::type::value
		==
		my_enum::test1,
		""
	);

	static_assert(
		boost::mpl::back<
			range
		>::type::value
		==
		my_enum::test2,
		""
	);
}
