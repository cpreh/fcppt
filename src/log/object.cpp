//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_stream.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/parameters.hpp>
#include <fcppt/log/setting.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/temporary_output_fwd.hpp>
#include <fcppt/log/format/optional_function.hpp>
#include <fcppt/log/impl/tree_formatter.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)

fcppt::log::object::object(
	fcppt::log::parameters const &_param
)
:
	auto_context_(
		_param.context(),
		_param.location()
	),
	formatter_(
		fcppt::log::impl::tree_formatter(
			auto_context_.node(),
			_param.formatter()
		)
	),
	level_streams_(
		_param.level_streams()
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
		!this->enabled(
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
			_level
		];
}

fcppt::log::level_stream const &
fcppt::log::object::level_sink(
	fcppt::log::level const _level
) const
{
	return
		level_streams_[
			_level
		];
}

bool
fcppt::log::object::enabled(
	fcppt::log::level const _level
) const
{
	return
		this->enabled_levels()[
			_level
		];
}

fcppt::log::format::optional_function const &
fcppt::log::object::formatter() const
{
	return
		formatter_;
}

fcppt::log::level_stream_array const &
fcppt::log::object::level_streams() const
{
	return
		level_streams_;
}

fcppt::log::enabled_level_array const &
fcppt::log::object::enabled_levels() const
{
	return
		this->setting().enabled_levels();
}

fcppt::log::setting const &
fcppt::log::object::setting() const
{
	return
		auto_context_.node().value().setting();
}
