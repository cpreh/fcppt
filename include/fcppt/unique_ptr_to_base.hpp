//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_UNIQUE_PTR_TO_BASE_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_TO_BASE_HPP_INCLUDED

#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Casts a unique_ptr to a base class

\ingroup fcpptsmartptr
*/
template<
	typename Base,
	typename Derived,
	typename Deleter
>
inline
fcppt::unique_ptr<
	Base,
	Deleter
>
unique_ptr_to_base(
	fcppt::unique_ptr<
		Derived,
		Deleter
	> &&_other
)
{
	static_assert(
		std::is_base_of<
			Base,
			Derived
		>::value,
		"Base must be a base class of Derived"
	);

	return
		fcppt::unique_ptr<
			Base,
			Deleter
		>(
			_other.release_ownership()
		);
}

}

#endif
