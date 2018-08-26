//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/char_type.hpp>
#include <fcppt/not.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/detail/flag_is_short.hpp>
#include <fcppt/options/impl/is_flag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


fcppt::optional::object<
	std::pair<
		fcppt::options::detail::flag_is_short,
		fcppt::string
	>
>
fcppt::options::impl::is_flag(
	fcppt::string const &_value
)
{
	// TODO: This is terrible
	fcppt::string::const_iterator pos{
		_value.begin()
	};

	typedef
	fcppt::optional::object<
		std::pair<
			fcppt::options::detail::flag_is_short,
			fcppt::string
		>
	>
	result_type;

	auto const is_dash(
		[](
			fcppt::char_type const _ch
		)
		{
			return
				_ch
				==
				FCPPT_TEXT('-');
		}
	);

	if(
		pos
		==
		_value.end()
		||
		fcppt::not_(
			is_dash(
				*pos
			)
		)
	)
		return
			result_type{};

	++pos;

	return
		result_type{
			is_dash(
				*pos
			)
			?
				std::make_pair(
					fcppt::options::detail::flag_is_short{
						false
					},
					fcppt::string{
						std::next(
							pos
						),
						_value.end()
					}
				)
			:
				std::make_pair(
					fcppt::options::detail::flag_is_short{
						true
					},
					fcppt::string{
						pos,
						_value.end()
					}
				)
		};
}
