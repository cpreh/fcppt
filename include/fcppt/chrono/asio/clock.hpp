//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_ASIO_CLOCK_HPP_INCLUDED
#define FCPPT_CHRONO_ASIO_CLOCK_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/chrono/system_clocks.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace chrono
{
namespace asio
{

typedef boost::chrono::steady_clock clock;

}
}
}

#endif
