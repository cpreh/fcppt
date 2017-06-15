//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/mpl/set_difference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/has_key.hpp>
#include <boost/mpl/set.hpp>
#include <fcppt/config/external_end.hpp>


int
main()
{
	typedef
	fcppt::mpl::set_difference<
		boost::mpl::set<
			short,
			int
		>,
		boost::mpl::set<
			int,
			long
		>
	>::type
	result;

	static_assert(
		!boost::mpl::has_key<
			result,
			int
		>::value,
		""
	);

	static_assert(
		boost::mpl::has_key<
			result,
			short
		>::value,
		""
	);

	static_assert(
		!boost::mpl::has_key<
			result,
			long
		>::value,
		""
	);
}
