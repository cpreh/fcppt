//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_REPETITION_RESULT_HPP_INCLUDED
#define FCPPT_PARSE_REPETITION_RESULT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <string>
#include <type_traits>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Result
>
using
repetition_result
=
std::conditional_t<
	std::disjunction_v<
		std::is_same<
			Result,
			char
		>,
		std::is_same<
			Result,
			wchar_t
		>
	>,
	std::basic_string<
		Result
	>,
	std::vector<
		Result
	>
>;

}
}

#endif
