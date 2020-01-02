//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_BASIC_CHAR_DECL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_CHAR_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_char_fwd.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/is_char.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/tag.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch
>
class basic_char
:
	private fcppt::parse::tag
{
public:
	static_assert(
		fcppt::parse::is_char<
			Ch
		>::value
	);

	basic_char();

	typedef
	Ch
	result_type;

	template<
		typename Skipper
	>
	fcppt::parse::result<
		Ch,
		result_type
	>
	parse(
		fcppt::reference<
			fcppt::parse::state<
				Ch
			>
		>,
		fcppt::parse::context<
			Skipper
		> const &
	) const;
};

}
}

#endif
