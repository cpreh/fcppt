//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_APPLY_HPP_INCLUDED
#define FCPPT_VARIANT_APPLY_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/variant/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <metal.hpp>
#include <variant>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

template<
	typename Function,
	typename... Variants
>
decltype(
	auto
)
apply(
	Function const &_function,
	Variants &&... _variants
)
{
	static_assert(
		::metal::all_of<
			::metal::list<
				fcppt::type_traits::remove_cv_ref_t<
					Variants
				>...
			>,
			::metal::trait<
				fcppt::variant::is_object
			>
		>::value,
		"Variants must all be variants"
	);

	return
		std::visit(
			_function,
			fcppt::move_if_rvalue<
				Variants
			>(
				_variants.impl()
			)...
		);
}

}
}

#endif
