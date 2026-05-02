//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MPL_TYPE_HPP_INCLUDED
#define FCPPT_MPL_TYPE_HPP_INCLUDED

/**
\brief Returns the inner typedef <code>type</code>.
\ingroup fcpptmpl
Returns <code>T::type</code>.
*/
namespace fcppt::mpl
{
template <typename T>
using type = T::type;
}

#endif
