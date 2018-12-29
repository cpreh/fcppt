//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_OPERATORS_COMPLEMENT_HPP_INCLUDED
#define FCPPT_PARSE_OPERATORS_COMPLEMENT_HPP_INCLUDED

#include <fcppt/parse/deref_type.hpp>
#include <fcppt/parse/detail/complement_impl.hpp>
#include <fcppt/parse/detail/is_char_set.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Parser,
	typename =
		std::enable_if_t<
			fcppt::parse::detail::is_char_set<
				fcppt::parse::deref_type<
					Parser
				>
			>::value
		>
>
auto
operator~(
	Parser &&_parser
)
{
	return
		fcppt::parse::detail::complement<
			fcppt::type_traits::remove_cv_ref_t<
				Parser
			>
		>{
			std::forward<
				Parser
			>(
				_parser
			)
		};
}

}
}

#endif
