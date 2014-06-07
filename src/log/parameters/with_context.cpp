//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/context_location.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/parameters/object.hpp>
#include <fcppt/log/parameters/with_context.hpp>


fcppt::log::parameters::object
fcppt::log::parameters::with_context(
	fcppt::log::context &_context,
	fcppt::log::location const &_location
)
{
	return
		fcppt::log::parameters::object()
		.context_location(
			fcppt::log::context_location(
				_context,
				_location
			)
		);
}
