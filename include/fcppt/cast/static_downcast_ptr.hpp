//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_STATIC_DOWNCAST_PTR_HPP_INCLUDED
#define FCPPT_CAST_STATIC_DOWNCAST_PTR_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Statically converts a pointer to a base class to a pointer to a derived
class

\ingroup fcpptcasts

Converts \a _source to the pointer type specified by \a Dest. This cast is
unsafe and should only be used if the \a _source has a dynamic type which is a
subtype of \a Dest. Consider using fcppt::cast::dynamic instead.

Dest must be a pointer to a class type derived from Source.
*/
template<
	typename Dest,
	typename Source
>
Dest
static_downcast_ptr(
	Source *const _source
)
{
	static_assert(
		std::is_base_of<
			typename
			std::remove_cv<
				Source
			>::type,
			typename
			std::remove_cv<
				typename
				std::remove_pointer<
					Dest
				>::type
			>::type
		>::value,
		"static_downcast_ptr can only cast from pointers to base classes to pointers to derived classes"
	);

	return
		static_cast<
			Dest
		>(
			_source
		);
}

}
}

#endif
