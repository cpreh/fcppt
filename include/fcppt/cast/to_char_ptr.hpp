//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_TO_CHAR_PTR_HPP_INCLUDED
#define FCPPT_CAST_TO_CHAR_PTR_HPP_INCLUDED

#include <fcppt/type_traits/is_raw_pointer.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Converts a pointer to a pointer to characters

\ingroup fcpptcasts

Converts \a _source to the pointer to character type specified by \a Dest.
This cast can be used to access the byte representation of an object, e.g.
for serialization and largely replaces <code>reinterpret_cast</code>.

\tparam Dest Must be a pointer to (cv) unsigned char
*/
template<
	typename Dest,
	typename Source
>
inline
Dest
to_char_ptr(
	Source *const _source
)
{
	static_assert(
		fcppt::type_traits::is_raw_pointer<
			Dest
		>::value,
		"to_char_ptr can only cast to pointers to (cv) unsigned char"
	);

	return
		reinterpret_cast<
			Dest
		>(
			_source
		);
}

}
}

#endif
