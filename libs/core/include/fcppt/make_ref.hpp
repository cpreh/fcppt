//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_REF_HPP_INCLUDED
#define FCPPT_MAKE_REF_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>


namespace fcppt
{

/**
\brief Convenience function to create references

\ingroup fcpptref
*/
template<
	typename Type
>
inline
fcppt::reference<
	Type
>
make_ref(
	Type &_ref
)
noexcept
{
	return
		fcppt::reference<
			Type
		>(
			_ref
		);
}

}

#endif
