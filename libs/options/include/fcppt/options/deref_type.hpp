//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_DEREF_TYPE_HPP_INCLUDED
#define FCPPT_OPTIONS_DEREF_TYPE_HPP_INCLUDED

#include <fcppt/deref_reference.hpp>
#include <fcppt/deref_type.hpp>
#include <fcppt/deref_unique_ptr.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>

namespace fcppt
{
namespace options
{
/**
\brief The dereferenced type of a parser.

\ingroup fcpptoptions

\tparam Parser A regular parser, an #fcppt::reference to a parser or an #fcppt::unique_ptr to a
parser.
*/
template <typename Parser>
using deref_type = fcppt::type_traits::remove_cv_ref_t<fcppt::deref_type<Parser>>;

}
}

#endif
