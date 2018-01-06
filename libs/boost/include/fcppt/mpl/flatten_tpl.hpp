//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_FLATTEN_TPL_HPP_INCLUDED
#define FCPPT_MPL_FLATTEN_TPL_HPP_INCLUDED

#include <fcppt/mpl/detail/flatten.hpp>


namespace fcppt
{
namespace mpl
{

/**
\brief Flattens an MPL sequence.

\ingroup fcpptmpl

If \a Type is a sequence <code>[t_1,...,t_n]</code>, then
the result is <code>flatten(t_1) + ... + flatten(t_n)</code>.
Otherwise, the result is <code>[Type]</code>.
*/
template<
	typename Type
>
struct flatten_tpl
:
fcppt::mpl::detail::flatten<
	Type
>
{
};

}
}

#endif
