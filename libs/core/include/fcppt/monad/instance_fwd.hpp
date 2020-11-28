//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MONAD_INSTANCE_FWD_HPP_INCLUDED
#define FCPPT_MONAD_INSTANCE_FWD_HPP_INCLUDED

namespace fcppt
{
namespace monad
{
/**
\brief Used to implement a monad instance.

\ingroup fcpptmonad

This class needs the following:
<ul>
<li><code>template<typename Type> struct constructor</code> with an inner typedef called
<code>type</code>. This applies the monad constructor to \a Type.</li> <li><code>template<typename
Type> struct inner_type</code> with an inner typedef called <code>type</code>. This extracts the
type passed to a monad constructor.</li> <li>A static function <code>template<typename T>
constructor<T> return_(T)</code>.</li> <li>A static function <code>template<typename T,typename U>
constructor\<U> bind(constructor<T>,constructor<U>(T))</code>.</li>
</ul>
*/
template <typename Type>
struct instance;

}
}

#endif
