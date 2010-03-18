//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_DURATION_CAST_HPP_INCLUDED
#define FCPPT_CHRONO_DURATION_CAST_HPP_INCLUDED

#include <fcppt/chrono/detail/duration_cast.hpp>
#include <fcppt/chrono/is_duration.hpp>
#include <boost/static_assert.hpp>

namespace fcppt
{
namespace chrono
{

/// Converts a duration into a different duration
/**
 * @tparam ToDuration The destination duration type
*/
template<
	typename ToDuration,
	typename Rep,
	typename Period
>
ToDuration
duration_cast(
	duration<
		Rep,
		Period
	> const &d
)
{
	BOOST_STATIC_ASSERT(
		is_duration<
			ToDuration
		>::value
	);

	return
		detail::duration_cast<
			ToDuration
		>(
			d
		);
}

}
}

#endif
