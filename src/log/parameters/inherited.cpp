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
	object &_parent,
	string const &_sub_location
)
{
	return
		all(
			_parent.sink()
		)
		.parent(
			_parent
		)
		.context_location(
			_parent.context_location().context(),
			_parent.context_location().location()
			+ _sub_location
		)
		.enabled(
			_parent.enabled()
		)
		.level_streams(
			_parent.level_streams()
		)
		.enabled_levels(
			_parent.enabled_levels()
		)
		.formatter(
			format::create_chain(
				_parent.formatter(),
				format::create_prefix(
					_sub_location
				)
			)
		);
}
