//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "tree_formatter.hpp"
#include <fcppt/io/ostream.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/parameters/all.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/optional_context_location.hpp>
#include <fcppt/log/detail/temporary_output_fwd.hpp>
#include <fcppt/log/format/const_object_ptr.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)

fcppt::log::object::object(
	parameters::all const &_param
)
:
	sink_(
		_param.sink()
	),
	auto_context_(
		_param.context_location(),
		*this
	),
	formatter_(
		_param.formatter()
	),
	enabled_(
		_param.enabled()
	),
	level_streams_(
		_param.level_streams()
	),
	enabled_levels_(
		_param.enabled_levels()
	)
{
}

FCPPT_PP_POP_WARNING

fcppt::log::object::~object()
{
}

void
fcppt::log::object::log(
	level::type const _level,
	detail::temporary_output const &_helper
)
{
	if(
		!this->enabled()
		||
		!this->activated(
			_level
		)
	)
		return;

	this->level_sink(
		_level
	).log(
		_helper,
		auto_context_.context_location()
		?
			log::tree_formatter(
				*auto_context_.context_location(),
				this->formatter()
			)
		:
			this->formatter()
	);
}

fcppt::log::level_stream &
fcppt::log::object::level_sink(
	level::type const _level
)
{
	return
		*level_streams_[
			_level
		];
}

fcppt::log::level_stream const &
fcppt::log::object::level_sink(
	level::type const _level
) const
{
	return
		*level_streams_[
			_level
		];
}

void
fcppt::log::object::activate(
	level::type const _level
)
{
	enabled_levels_[
		_level
	] = true;
}

void
fcppt::log::object::deactivate(
	level::type const _level
)
{
	enabled_levels_[
		_level
	] = false;
}

bool
fcppt::log::object::activated(
	level::type const _level
) const
{
	return
		enabled_levels_[
			_level
		];
}

void
fcppt::log::object::enable(
	bool const _enabled
)
{
	enabled_ = _enabled;
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

fcppt::log::optional_context_location const
fcppt::log::object::context_location() const
{
	return auto_context_.context_location();
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
