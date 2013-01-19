//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_ASIO_CONVERT_DURATION_HPP_INCLUDED
#define FCPPT_CHRONO_ASIO_CONVERT_DURATION_HPP_INCLUDED

#include <fcppt/chrono/asio/duration.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/chrono/duration.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace chrono
{
namespace asio
{

template<
	typename Rep,
	typename Period
>
fcppt::chrono::asio::duration const
convert_duration(
	boost::chrono::duration<
		Rep,
		Period
	> const &_duration
)
{
	return
		boost::chrono::duration_cast<
			fcppt::chrono::asio::duration
		>(
			_duration
		);
}

}
}
}

#endif
