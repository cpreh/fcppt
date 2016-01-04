//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_TO_OPTIONAL_REF_HPP_INCLUDED
#define FCPPT_VARIANT_TO_OPTIONAL_REF_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/variant/holds_type.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Converts a variant and a type to an optional reference

\ingroup fcpptvariant
*/
template<
	typename Type,
	typename Variant
>
fcppt::optional::reference<
	Type
>
to_optional_ref(
	Variant &_variant
)
{
	typedef
	fcppt::optional::reference<
		Type
	>
	result_type;

	typedef
	typename
	std::remove_cv<
		Type
	>::type
	element_type;

	return
		fcppt::variant::holds_type<
			element_type
		>(
			_variant
		)
		?
			result_type{
				fcppt::make_ref(
					_variant. template get_unsafe<
						element_type
					>()
				)
			}
		:
			result_type{}
		;
}

}
}

#endif
