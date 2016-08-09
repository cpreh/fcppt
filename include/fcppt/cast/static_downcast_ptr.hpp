//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_STATIC_DOWNCAST_PTR_HPP_INCLUDED
#define FCPPT_CAST_STATIC_DOWNCAST_PTR_HPP_INCLUDED

#include <fcppt/type_traits/is_base_of.hpp>
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

Converts \a _source to the pointer type specified by \a Derived. Null pointers
are preserved. This cast is unsafe and should only be used if the \a _source
has a dynamic type which is a subtype of \a Derived. Consider using \link
fcppt::cast::dynamic \endlink instead.

\tparam Derived The type to cast to. Must be a pointer type. Must inherit from \a Base.

\tparam Base A cv-qualified non-reference type.
*/
template<
	typename Derived,
	typename Base
>
Derived
static_downcast_ptr(
	Base *const _source
)
{
	static_assert(
		fcppt::type_traits::is_base_of<
			typename
			std::remove_cv<
				Base
			>::type,
			typename
			std::remove_cv<
				typename
				std::remove_pointer<
					Derived
				>::type
			>::type
		>::value,
		"static_downcast_ptr can only cast from pointers to base classes to pointers to derived classes"
	);

	return
		static_cast<
			Derived
		>(
			_source
		);
}

}
}

#endif
