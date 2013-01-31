//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/ostream.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/optional_location.hpp>
#include <fcppt/log/detail/optional_context_location.hpp>
#include <fcppt/log/detail/temporary_output_fwd.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/log/parameters/object.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/src/log/tree_formatter.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)

fcppt::log::object::object(
	fcppt::log::parameters::object const &_param
)
:
	auto_context_(
		_param.context_location(),
		*this
	),
	formatter_(
		auto_context_.node()
		?
			fcppt::log::tree_formatter(
				auto_context_.node(),
				_param.formatter()
			)
		:
			_param.formatter()
	),
	level_streams_(
		_param.level_streams()
	),
	enabled_levels_(
		_param.enabled_levels()
	),
	enabled_(
		_param.enabled()
	)
{
}

FCPPT_PP_POP_WARNING

fcppt::log::object::~object()
{
}

void
fcppt::log::object::log(
	fcppt::log::level const _level,
	fcppt::log::detail::temporary_output const &_helper
)
{
	if(
		!this->enabled_and_activated(
			_level
		)
	)
		return;

	this->level_sink(
		_level
	).log(
		_helper,
		formatter_
	);
}

fcppt::log::level_stream &
fcppt::log::object::level_sink(
	fcppt::log::level const _level
)
{
	return
		level_streams_[
			static_cast<
				fcppt::log::level_stream_array::size_type
			>(
				_level
			)
		];
}

fcppt::log::level_stream const &
fcppt::log::object::level_sink(
	fcppt::log::level const _level
) const
{
	return
		level_streams_[
			static_cast<
				fcppt::log::level_stream_array::size_type
			>(
				_level
			)
		];
}

void
fcppt::log::object::activate(
	fcppt::log::level const _level
)
{
	enabled_levels_[
		static_cast<
			fcppt::log::enabled_level_array::size_type
		>(
			_level
		)
	] = true;
}

void
fcppt::log::object::deactivate(
	fcppt::log::level const _level
)
{
	enabled_levels_[
		static_cast<
			fcppt::log::enabled_level_array::size_type
		>(
			_level
		)
	] = false;
}

bool
fcppt::log::object::activated(
	fcppt::log::level const _level
) const
{
	return
		enabled_levels_[
			static_cast<
				fcppt::log::enabled_level_array::size_type
			>(
				_level
			)
		];
}

bool
fcppt::log::object::enabled_and_activated(
	fcppt::log::level const _level
) const
{
	return
		this->enabled()
		&&
		this->activated(
			_level
		);
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

fcppt::log::format::function const &
fcppt::log::object::formatter() const
{
	return formatter_;
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

fcppt::log::optional_location const
fcppt::log::object::location() const
{
	return auto_context_.location();
}
