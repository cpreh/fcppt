//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_QUERY_PERFORMANCE_FREQUENCY_HPP_INCLUDED
#define FCPPT_CHRONO_QUERY_PERFORMANCE_FREQUENCY_HPP_INCLUDED

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace fcppt
{
namespace chrono
{

LARGE_INTEGER
query_performance_frequency();

}
}

#endif
