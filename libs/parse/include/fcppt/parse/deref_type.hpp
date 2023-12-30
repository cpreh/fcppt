//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_DEREF_TYPE_HPP_INCLUDED
#define FCPPT_PARSE_DEREF_TYPE_HPP_INCLUDED

#include <fcppt/deref_reference.hpp> // IWYU pragma: keep
#include <fcppt/deref_type.hpp>
#include <fcppt/deref_unique_ptr.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::parse
{

/**
\brief The dereferenced type of a parser.
\ingroup fcpptparse
\see fcppt::deref_type
*/
template <typename Parser>
using deref_type = std::remove_cvref_t<fcppt::deref_type<Parser const>>;

}

#endif
