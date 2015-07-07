//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_UNIQUE_PTR_TO_CONST_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_TO_CONST_HPP_INCLUDED

#include <fcppt/unique_ptr_impl.hpp>


namespace fcppt
{

/**
\brief Casts a unique_ptr to a const unique_ptr

\ingroup fcpptsmartptr
*/
template<
	typename Type
>
inline
fcppt::unique_ptr<
	Type const
>
unique_ptr_to_const(
	fcppt::unique_ptr<
		Type
	> &&_other
)
{
	return
		fcppt::unique_ptr<
			Type const
		>(
			_other.release_ownership()
		);
}

}

#endif
