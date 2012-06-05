//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SRC_THREAD_TO_BOOST_DURATION_HPP_INCLUDED
#define FCPPT_SRC_THREAD_TO_BOOST_DURATION_HPP_INCLUDED

#include <fcppt/static_assert_expression.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/chrono/duration.hpp>
#include <boost/date_time/posix_time/posix_time_config.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace thread
{

template<
	typename Rep,
	typename Period
>
boost::posix_time::time_duration const
to_boost_duration(
	boost::chrono::duration<
		Rep,
		Period
	> const &_duration
)
{
	FCPPT_STATIC_ASSERT_EXPRESSION(
		Period::num == 1
	);

	return
		boost::date_time::subsecond_duration<
			boost::posix_time::time_duration,
			Period::den
		>(
			_duration.count()
		);
}

}
}

#endif
