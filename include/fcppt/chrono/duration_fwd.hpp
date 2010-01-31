//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_DURATION_FWD_HPP_INCLUDED
#define FCPPT_CHRONO_DURATION_FWD_HPP_INCLUDED

#include <fcppt/ratio/object.hpp>

namespace fcppt
{
namespace chrono
{

template<
	typename Rep,
	typename Period
		= ratio::object<1>
>
class duration;

}
}

#endif
