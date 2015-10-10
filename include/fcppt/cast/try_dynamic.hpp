//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_TRY_DYNAMIC_HPP_INCLUDED
#define FCPPT_CAST_TRY_DYNAMIC_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Tries a <code>dynamic_cast</code>, returning an empty optional value if
it failed

\ingroup fcpptcasts

\tparam Derived The type to cast to. This has to be a reference type (see the
example below)

\tparam Base The type to cast from (must not be a reference)

This cast is basically the same as <code>dynamic_cast</code> with pointers, but
with optional references. Note that you can only cast to a reference type (be
that const or nonconst). Here's a usage example:

\snippet cast.cpp try_dynamic
*/
template<
	typename Derived,
	typename Base
>
fcppt::optional<
	Derived
>
try_dynamic(
	Base &_base
)
{
	static_assert(
		std::is_reference<
			Derived
		>::value,
		"try_dynamic can only cast to reference types"
	);

	typedef
	typename
	std::remove_reference<
		Derived
	>::type
	derived_no_reference;

	derived_no_reference * const derived_ptr{
		dynamic_cast<
			derived_no_reference *
		>(
			&_base
		)
	};

	typedef
	fcppt::optional<
		Derived
	>
	result_type;

	return
		derived_ptr
		?
			result_type{
				*derived_ptr
			}
		:
			result_type{}
		;
}

}
}

#endif
