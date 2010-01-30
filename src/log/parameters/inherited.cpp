//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/parameters/inherited.hpp>
#include <fcppt/log/parameters/all.hpp>
#include <fcppt/log/format/create_prefix.hpp>
#include <fcppt/log/format/create_chain.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/object.hpp>

fcppt::log::parameters::all const
fcppt::log::parameters::inherited(
	object &parent,
	string const &sub_location
)
{
	return
		all(
			parent.sink()
		)
		.parent(
			parent
		)
		.context_location(
			parent.context_location().context(),
			parent.context_location().location()
			+ sub_location
		)
		.enabled(
			parent.enabled()
		)
		.level_streams(
			parent.level_streams()
		)
		.enabled_levels(
			parent.enabled_levels()
		)
		.formatter(
			format::create_chain(
				parent.formatter(),
				format::create_prefix(
					sub_location
				)
			)
		);
}
