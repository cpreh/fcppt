//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_HOURS_HPP_INCLUDED
#define FCPPT_CHRONO_HOURS_HPP_INCLUDED

#include <fcppt/chrono/duration_fwd.hpp>
#include <fcppt/chrono/rep.hpp>
#include <fcppt/ratio/object.hpp>

namespace fcppt
{
namespace chrono
{

/// A duration that counts in hours
typedef duration<
	rep,
	ratio::object<
		3600
	>
> hours;

}
}

#endif
