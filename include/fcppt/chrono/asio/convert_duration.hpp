//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_ASIO_CONVERT_DURATION_HPP_INCLUDED
#define FCPPT_CHRONO_ASIO_CONVERT_DURATION_HPP_INCLUDED

#include <fcppt/chrono/duration_cast.hpp>
#include <fcppt/chrono/duration_impl.hpp>
#include <fcppt/chrono/asio/duration.hpp>


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
	fcppt::chrono::duration<
		Rep,
		Period
	> const &_duration
)
{
	return
		fcppt::chrono::duration_cast<
			fcppt::chrono::asio::duration
		>(
			_duration
		);
}

}
}
}

#endif
