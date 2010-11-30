//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/parameters/root.hpp>
#include <fcppt/log/parameters/all.hpp>
#include <fcppt/log/format/create_prefix.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/enabled_levels.hpp>

fcppt::log::parameters::root::root(
	io::ostream &_sink
)
:
	sink_(_sink),
	prefix_(),
	enabled_(false),
	level_(log::level::warning),
	context_(0)
{}

fcppt::log::parameters::root
fcppt::log::parameters::root::prefix(
	string const &_prefix
)
{
	prefix_ = _prefix;

	return *this;
}

fcppt::log::parameters::root
fcppt::log::parameters::root::enabled(
	bool const _enabled
)
{
	enabled_ = _enabled;

	return *this;
}

fcppt::log::parameters::root
fcppt::log::parameters::root::level(
	log::level::type const _level
)
{
	level_ = _level;

	return *this;
}

fcppt::log::parameters::root
fcppt::log::parameters::root::context(
	log::context &_context
)
{
	context_ = &_context;

	return *this;
}

fcppt::log::parameters::all const
fcppt::log::parameters::root::create() const
{
	return
		all(
			sink_
		)
		.context_location(
			context_,
			location(
				prefix_
			)
		)
		.enabled(
			enabled_
		)
		.level_streams(
			default_level_streams(
				sink_
			)
		)
		.enabled_levels(
			log::enabled_levels(
				level_
			)
		)
		.formatter(
			prefix_.empty()
			?
				format::const_object_ptr()
			:
				format::create_prefix(
					prefix_
				)
		);
}
