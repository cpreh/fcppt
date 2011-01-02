//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_REP_HPP_INCLUDED
#define FCPPT_CHRONO_REP_HPP_INCLUDED

#include <fcppt/config.hpp>
#ifdef FCPPT_HAVE_ATLEAST_UINT64
#include <boost/cstdint.hpp>
#else
#include <fcppt/preprocessor/warning.hpp>
#endif

namespace fcppt
{
namespace chrono
{

#ifdef FCPPT_HAVE_ATLEAST_UINT64
typedef boost::int64_t rep;
#else
typedef long rep;
FCPPT_PP_WARNING("This platform does not provide a 64 bit integer type. time_points may overflow too quickly.")
#endif

}
}

#endif
