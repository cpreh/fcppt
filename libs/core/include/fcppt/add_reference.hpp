//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ADD_REFERENCE_HPP_INCLUDED
#define FCPPT_ADD_REFERENCE_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>


namespace fcppt
{

/**
\brief Metafunction that adds #fcppt::reference.

Transforms <code>T</code> into <code>fcppt::reference<T></code>.

\ingroup fcpptref
*/
template<
	typename Type
>
struct add_reference
{
	typedef
	fcppt::reference<
		Type
	>
	type;
};

}

#endif
