//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_RESULT_OF_HPP_INCLUDED
#define FCPPT_PARSE_RESULT_OF_HPP_INCLUDED

#include <fcppt/parse/deref_type.hpp>

namespace fcppt::parse
{
/**
\brief The result type of a parser.
\ingroup fcpptparse
*/
template <typename Parser>
using result_of = fcppt::parse::deref_type<Parser>::result_type;

}

#endif
