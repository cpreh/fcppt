//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_ASIO_DEADLINE_TIMER_HPP_INCLUDED
#define FCPPT_CHRONO_ASIO_DEADLINE_TIMER_HPP_INCLUDED

#include <fcppt/chrono/duration_impl.hpp>
#include <fcppt/chrono/time_point_impl.hpp>
#include <fcppt/chrono/asio/tag.hpp>
#include <fcppt/chrono/asio/time_traits.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/asio/basic_deadline_timer.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace chrono
{
namespace asio
{

typedef boost::asio::basic_deadline_timer<
	fcppt::chrono::asio::tag
> deadline_timer;

}
}
}

#endif
