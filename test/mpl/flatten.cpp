//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/mpl/flatten.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/vector.hpp>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		boost::mpl::equal<
			fcppt::mpl::flatten<
				boost::mpl::vector<
					boost::mpl::vector2<
						int,
						long
					>,
					void
				>
			>,
			boost::mpl::vector<
				int,
				long,
				void
			>
		>::value,
		""
	);
}
