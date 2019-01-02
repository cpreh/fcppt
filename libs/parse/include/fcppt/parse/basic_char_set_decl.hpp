//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_BASIC_CHAR_SET_DECL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_CHAR_SET_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/basic_char_set_fwd.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/tag.hpp>
#include <fcppt/parse/result_fwd.hpp>
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
	typedef
	std::unordered_set<
		Ch
	>
	char_set_type;

	explicit
	basic_char_set(
		std::initializer_list<
			Ch
		> const &
	);

	explicit
	basic_char_set(
		char_set_type &&
	);

	typedef
	Ch
	result_type;

	template<
		typename Skipper
	>
	fcppt::parse::result<
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

	char_set_type const &
	chars() const;
private:
	char_set_type chars_;
};

}
}

#endif
