//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_CONVERT_TO_BOOST_DURATION_HPP_INCLUDED
#define FCPPT_CHRONO_CONVERT_TO_BOOST_DURATION_HPP_INCLUDED

#include <fcppt/chrono/duration_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <boost/date_time/posix_time/posix_time_config.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace chrono
{
namespace convert
{

/// Converts durations to boost::date_time
/**
 * @remark The duration to convert must have period::num==1!
*/
template<
	typename Rep,
	typename Period
>
boost::posix_time::time_duration const
to_boost_duration(
	duration<
		Rep,
		Period
	> const &duration_
)
{
	BOOST_STATIC_ASSERT(
		Period::num == 1
	);

	return
		boost::date_time::subsecond_duration<
			boost::posix_time::time_duration,
			Period::den
		>(
			duration_.count()
		);
}

}
}
}

#endif
