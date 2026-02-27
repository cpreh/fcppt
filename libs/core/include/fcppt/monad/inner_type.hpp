//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MONAD_INNER_TYPE_HPP_INCLUDED
#define FCPPT_MONAD_INNER_TYPE_HPP_INCLUDED

#include <fcppt/monad/instance_fwd.hpp>

namespace fcppt::monad
{
/**
\brief Extracts the type a monadic constructor was used with.

\ingroup fcpptmonad

Becaused C++ lacks type inference, we need a special function to get
<code>a</code> from <code>m a</code>.
*/
template <typename Type>
using inner_type = fcppt::monad::instance<Type>::template inner_type<Type>::type;

}

#endif
