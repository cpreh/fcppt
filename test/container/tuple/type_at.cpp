//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/tuple/type_at.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{

	static_assert(
		std::is_same<
			fcppt::container::tuple::type_at<
				std::tuple<
					int,
					float
				>,
				1
			>,
			float
		>::value,
		""
	);
}
