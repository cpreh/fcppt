//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/type_traits/is_iterator.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


int
main()
{
	struct not_iterator
	{};

	static_assert(
		fcppt::type_traits::is_iterator<
			int *
		>::value,
		""
	);

	static_assert(
		fcppt::type_traits::is_iterator<
			int const *
		>::value,
		""
	);

	static_assert(
		fcppt::type_traits::is_iterator<
			std::string::iterator
		>::value,
		""
	);

	static_assert(
		fcppt::type_traits::is_iterator<
			std::string::const_iterator
		>::value,
		""
	);

	static_assert(
		!fcppt::type_traits::is_iterator<
			int
		>::value,
		""
	);

	static_assert(
		!fcppt::type_traits::is_iterator<
			not_iterator
		>::value,
		""
	);
}
