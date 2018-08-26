//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/const.hpp>
#include <fcppt/cast/enum_to_int.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/enum/size.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/optional_level.hpp>
#include <fcppt/log/detail/active_level_int.hpp>
#include <fcppt/log/impl/convert_level.hpp>
#include <fcppt/optional/maybe.hpp>


fcppt::log::detail::active_level_int
fcppt::log::impl::convert_level(
	fcppt::log::optional_level const &_opt_level
)
{
	return
		fcppt::optional::maybe(
			_opt_level,
			fcppt::const_(
				fcppt::cast::size<
					fcppt::log::detail::active_level_int
				>(
					fcppt::enum_::size<
						fcppt::log::level
					>::value
				)
			),
			[](
				fcppt::log::level const _level
			)
			{
				return
					fcppt::cast::enum_to_int<
						fcppt::log::detail::active_level_int
					>(
						_level
					);
			}
		);
}
