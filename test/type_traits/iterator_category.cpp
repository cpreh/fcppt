//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/type_traits/is_bidirectional_iterator.hpp>
#include <fcppt/type_traits/is_forward_iterator.hpp>
#include <fcppt/type_traits/is_input_iterator.hpp>
#include <fcppt/type_traits/is_output_iterator.hpp>
#include <fcppt/type_traits/is_random_access_iterator.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <list>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		fcppt::type_traits::is_input_iterator<
			int *
		>::value,
		""
	);

	static_assert(
		fcppt::type_traits::is_random_access_iterator<
			int *
		>::value,
		""
	);

	static_assert(
		!fcppt::type_traits::is_random_access_iterator<
			std::list<
				int
			>::const_iterator
		>::value,
		""
	);

	static_assert(
		fcppt::type_traits::is_bidirectional_iterator<
			std::list<
				int
			>::const_iterator
		>::value,
		""
	);

	static_assert(
		fcppt::type_traits::is_forward_iterator<
			std::list<
				int
			>::const_iterator
		>::value,
		""
	);

	static_assert(
		fcppt::type_traits::is_output_iterator<
			std::ostream_iterator<
				int
			>
		>::value,
		""
	);
}
