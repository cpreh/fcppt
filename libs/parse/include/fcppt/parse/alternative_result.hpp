//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_ALTERNATIVE_RESULT_HPP_INCLUDED
#define FCPPT_PARSE_ALTERNATIVE_RESULT_HPP_INCLUDED

#include <fcppt/brigand/unique.hpp>
#include <fcppt/parse/detail/alternative_list.hpp>
#include <fcppt/parse/detail/alternative_result.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/append.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Left,
	typename Right
>
using
alternative_result
=
fcppt::parse::detail::alternative_result<
	fcppt::brigand::unique<
		::brigand::append<
			typename
			fcppt::parse::detail::alternative_list<
				Left
			>::type,
			typename
			fcppt::parse::detail::alternative_list<
				Right
			>::type
		>
	>
>;

}
}

#endif
