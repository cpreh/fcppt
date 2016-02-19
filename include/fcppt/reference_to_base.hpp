//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_REFERENCE_TO_BASE_HPP_INCLUDED
#define FCPPT_REFERENCE_TO_BASE_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Converts a reference to a base class

\ingroup fcpptref

\tparam Base Must be a base class of \a Type
*/
template<
	typename Base,
	typename Type
>
inline
fcppt::reference<
	Base
>
reference_to_base(
	fcppt::reference<
		Type
	> const _ref
)
{
	static_assert(
		std::is_base_of<
			typename
			std::remove_cv<
				Base
			>::type,
			typename
			std::remove_cv<
				Type
			>::type
		>::value,
		"Base must be a base of Type"
	);

	return
		fcppt::reference<
			Base
		>(
			_ref.get()
		);
}

}

#endif
