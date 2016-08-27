//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_FLATTEN_HPP_INCLUDED
#define FCPPT_MPL_FLATTEN_HPP_INCLUDED

#include <fcppt/mpl/flatten_tpl.hpp>


namespace fcppt
{
namespace mpl
{

/**
\brief Flattens an MPL sequence

\ingroup fcpptmpl
*/
template<
	typename Type
>
using flatten
=
typename
fcppt::mpl::flatten_tpl<
	Type
>::type;

}
}

#endif
