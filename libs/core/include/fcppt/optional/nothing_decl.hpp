//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_NOTHING_DECL_HPP_INCLUDED
#define FCPPT_OPTIONAL_NOTHING_DECL_HPP_INCLUDED

#include <fcppt/concepts/move_constructible.hpp>
#include <fcppt/optional/nothing_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>

namespace fcppt::optional
{
/**
\brief A polymorphic empty optional

Objects of this class implicitly convert into empty #fcppt::optional::object.

\ingroup fcpptoptional
*/
struct nothing
{
  /**
  \brief Returns an empty optional.
  */
  template <fcppt::concepts::move_constructible T>
  // NOLINTNEXTLINE(google-explicit-constructor,hicpp-explicit-conversions)
  operator fcppt::optional::object<T>() const;
};

}

#endif
