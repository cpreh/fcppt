//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/help_switch.hpp>
#include <fcppt/options/detail/help_error.hpp>
#include <fcppt/options/detail/long_or_short_name.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::options::error
fcppt::options::detail::help_error(
	fcppt::options::help_switch const &_help,
	fcppt::options::error &&_error
)
{
	return
		fcppt::variant::apply_unary(
			[
				&_help
			](
				auto &&_string
			)
			{
				return
					fcppt::options::error{
						std::move(
							_string
						)
						+
						typename
						std::decay<
							decltype(
								_string
							)
						>::type{
							FCPPT_TEXT("\nUse ")
							+
							fcppt::options::detail::long_or_short_name(
								_help.long_name(),
								_help.short_name()
							)
							+
							FCPPT_TEXT(" for a usage description.")
						}
					};
			},
			std::move(
				_error
			)
		);
}
