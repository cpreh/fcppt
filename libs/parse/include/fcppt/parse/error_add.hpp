//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_ERROR_ADD_HPP_INCLUDED
#define FCPPT_PARSE_ERROR_ADD_HPP_INCLUDED

#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/fatal_tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch
>
fcppt::parse::error<
	Ch
>
operator+(
	fcppt::parse::error<
		Ch
	> &&_left,
	fcppt::parse::error<
		Ch
	> &&_right
)
{
	std::basic_string<
		Ch
	> value{
		std::move(
			_left.get()
		)
		+
		std::move(
			_right.get()
		)
	};

	return
		_left.is_fatal()
		||
		_right.is_fatal()
		?
			fcppt::parse::error<
				Ch
			>{
				std::move(
					value
				),
				fcppt::parse::fatal_tag{}
			}
		:
			fcppt::parse::error<
				Ch
			>{
				std::move(
					value
				)
			}
		;
}

}
}

#endif
