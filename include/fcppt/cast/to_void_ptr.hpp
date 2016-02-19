//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_TO_VOID_PTR_HPP_INCLUDED
#define FCPPT_CAST_TO_VOID_PTR_HPP_INCLUDED


namespace fcppt
{
namespace cast
{

/**
\brief Converts a pointer to const to a pointer to const void

\ingroup fcpptcasts
*/
template<
	typename Source
>
inline
void const *
to_void_ptr(
	Source const *const _ptr
)
{
	return
		_ptr;
}

/**
\brief Converts a pointer to const to a pointer to const void

\ingroup fcpptcasts
*/
template<
	typename Source
>
inline
void *
to_void_ptr(
	Source *const _ptr
)
{
	return
		_ptr;
}

}
}

#endif
