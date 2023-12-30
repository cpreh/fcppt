//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_DEREF_IMPL_HPP_INCLUDED
#define FCPPT_DEREF_IMPL_HPP_INCLUDED

#include <fcppt/deref_impl_fwd.hpp> // IWYU pragma: keep

namespace fcppt
{
/**
\brief Customization point for #fcppt::deref.

\ingroup fcpptvarious

The default implementation is the identity on reference types.
*/
template <typename Arg, typename Enable>
struct deref_impl
{
  static Arg &execute(Arg &_value) { return _value; }
};

}

#endif
