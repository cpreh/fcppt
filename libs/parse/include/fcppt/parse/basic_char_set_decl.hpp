//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_BASIC_CHAR_SET_DECL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_CHAR_SET_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_char_set_fwd.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <initializer_list>
#include <unordered_set>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch
>
class basic_char_set
:
	private fcppt::parse::tag
{
public:
	using
	char_set_type
	=
	std::unordered_set<
		Ch
	>;

	basic_char_set(
		std::initializer_list<
			Ch
		> const &
	);

	explicit
	basic_char_set(
		char_set_type &&
	);

	using
	result_type
	=
	Ch;

	template<
		typename Skipper
	>
	[[nodiscard]]
	fcppt::parse::result<
		Ch,
		result_type
	>
	parse(
		fcppt::reference<
			fcppt::parse::basic_stream<
				Ch
			>
		>,
		Skipper const &
	) const;

	[[nodiscard]]
	char_set_type const &
	chars() const;
private:
	char_set_type chars_;
};

}
}

#endif
