//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_SKIPPER_IS_VALID_ARGUMENT_HPP_INCLUDED
#define FCPPT_PARSE_SKIPPER_IS_VALID_ARGUMENT_HPP_INCLUDED

#include <fcppt/parse/deref_type.hpp>
#include <fcppt/parse/skipper/is_skipper.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace parse
{
namespace skipper
{
/**
\brief Checks if a parameter is a valid skipper type.
\ingroup fcpptparse

Skippers can be passed as-is, by #fcppt::reference or by #fcppt::unique_ptr.
*/
template <typename Type>
using is_valid_argument = fcppt::parse::skipper::is_skipper<
    fcppt::parse::deref_type<std::remove_cvref_t<Type>>>;

}
}
}

#endif
