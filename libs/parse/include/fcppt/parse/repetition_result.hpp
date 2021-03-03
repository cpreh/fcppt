//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_REPETITION_RESULT_HPP_INCLUDED
#define FCPPT_PARSE_REPETITION_RESULT_HPP_INCLUDED

#include <fcppt/parse/is_char.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <type_traits>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
/**
\brief The result type of a repetition parser.

\ingroup fcpptparse

If \a Type is a character type (see #fcppt::parse::is_char),
then the result is <code>std::basic_string<Type></code>.
Otherwise, it is <code>std::vector<Type></code>.
*/
template <typename Type>
using repetition_result = std::conditional_t<
    fcppt::parse::is_char<Type>::value,
    std::basic_string<Type>,
    std::vector<Type>>;

}
}

#endif
