//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_REF_HPP_INCLUDED
#define FCPPT_MAKE_REF_HPP_INCLUDED

#include <fcppt/reference_wrapper_impl.hpp>


namespace fcppt
{

/**
\brief Convenience function to create reference_wrappers

\ingroup fcpptvarious
*/
template<
	typename Type
>
fcppt::reference_wrapper<
	Type
> const
make_ref(
	Type &_ref
)
{
	return
		fcppt::reference_wrapper<
			Type
		>(
			_ref
		);
}

}

#endif
