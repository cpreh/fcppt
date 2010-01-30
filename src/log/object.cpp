//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/object.hpp>
#include <fcppt/log/parameters/all.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/level_stream.hpp>

fcppt::log::object::object(
	parameters::all const &param_
)
:
	parent_(
		param_.parent()
	),
	sink_(
		param_.sink()
	),
	auto_context_(
		param_.context_location(),
		*this
	),
	formatter_(
		param_.formatter()
	),
	enabled_(
		param_.enabled()
	),
	level_streams_(
		param_.level_streams()
	),
	enabled_levels_(
		param_.enabled_levels()
	)
{
}

fcppt::log::object::~object()
{}

void
fcppt::log::object::log(
	level::type const level_,
	temporary_output const &helper
)
{
	if(
		!enabled()
		|| !activated(level_)
	)
		return;

	level_sink(level_).log(
		helper,
		formatter()
	);
}

fcppt::log::level_stream &
fcppt::log::object::level_sink(
	level::type const level_
)
{
	return *level_streams_.at(
		level_
	);
}

fcppt::log::level_stream const &
fcppt::log::object::level_sink(
	level::type const level_
) const
{
	return *level_streams_.at(
		level_
	);
}

void
fcppt::log::object::activate(
	level::type const level_
)
{
	enabled_levels_[
		level_
	] = true;
}

void
fcppt::log::object::deactivate(
	level::type const level_
)
{
	enabled_levels_[
		level_
	] = false;
}

bool
fcppt::log::object::activated(
	level::type const level_
) const
{
	return
		enabled_levels_[
			level_
		];
}

void
fcppt::log::object::enable(
	bool const b
)
{
	enabled_ = b;
}

bool
fcppt::log::object::enabled() const
{
	return enabled_;
}

fcppt::io::ostream &
fcppt::log::object::sink() const
{
	return sink_;
}

fcppt::log::format::const_object_ptr const
fcppt::log::object::formatter() const
{
	return formatter_;
}

fcppt::log::context_location const
fcppt::log::object::context_location() const
{
	return auto_context_.location();
}

fcppt::log::level_stream_array const &
fcppt::log::object::level_streams() const
{
	return level_streams_;
}

fcppt::log::enabled_level_array const &
fcppt::log::object::enabled_levels() const
{
	return enabled_levels_;
}
