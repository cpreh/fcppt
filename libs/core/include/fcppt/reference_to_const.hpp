//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_REFERENCE_TO_CONST_HPP_INCLUDED
#define FCPPT_REFERENCE_TO_CONST_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Converts a reference to a const reference

\ingroup fcpptref

\tparam Type Must not be const
*/
template<
	typename Type
>
inline
fcppt::reference<
	Type const
>
reference_to_const(
	fcppt::reference<
		Type
	> const _ref
)
noexcept
{
	static_assert(
		!std::is_const<
			Type
		>::value,
		"Type must not be const"
	);

	return
		fcppt::reference<
			Type const
		>(
			_ref.get()
		);
}

}

#endif
