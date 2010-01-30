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
	io::ostream &sink_
)
:
	sink_(sink_),
	prefix_(),
	enabled_(false),
	level_(log::level::warning),
	context_(0)
{}

fcppt::log::parameters::root
fcppt::log::parameters::root::prefix(
	string const &nprefix_
)
{
	prefix_ = nprefix_;

	return *this;
}

fcppt::log::parameters::root
fcppt::log::parameters::root::enabled(
	bool const nenabled_
)
{
	enabled_ = nenabled_;

	return *this;
}

fcppt::log::parameters::root
fcppt::log::parameters::root::level(
	log::level::type const nlevel_
)
{
	level_ = nlevel_;

	return *this;
}

fcppt::log::parameters::root
fcppt::log::parameters::root::context(
	log::context &ncontext_
)
{
	context_ = &ncontext_;

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
