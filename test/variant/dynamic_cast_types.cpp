//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/reference_impl.hpp>
#include <fcppt/variant/dynamic_cast_types.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/vector.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	typedef
	fcppt::variant::dynamic_cast_types<
		boost::mpl::vector<
			int,
			char const
		>
	>
	types;

	static_assert(
		std::is_same<
			boost::mpl::at_c<
				types,
				0
			>::type,
			fcppt::reference<
				int
			>
		>::value,
		""
	);

	static_assert(
		std::is_same<
			boost::mpl::at_c<
				types,
				1
			>::type,
			fcppt::reference<
				char const
			>
		>::value,
		""
	);
}
