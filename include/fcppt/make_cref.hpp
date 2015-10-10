//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_CREF_HPP_INCLUDED
#define FCPPT_MAKE_CREF_HPP_INCLUDED

#include <fcppt/reference_wrapper_impl.hpp>


namespace fcppt
{

/**
\brief Convenience function to create const reference_wrappers

\ingroup fcpptref
*/
template<
	typename Type
>
inline
fcppt::reference_wrapper<
	Type const
>
make_cref(
	Type const &_ref
)
{
	return
		fcppt::reference_wrapper<
			Type const
		>(
			_ref
		);
}

}

#endif
