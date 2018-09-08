//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_APPLY_HPP_INCLUDED
#define FCPPT_VARIANT_APPLY_HPP_INCLUDED

#include <fcppt/absurd.hpp>
#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/variant/is_object.hpp>
#include <fcppt/variant/types_of.hpp>
#include <fcppt/variant/detail/apply.hpp>
#include <fcppt/variant/detail/get_unsafe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/all.hpp>
#include <brigand/sequences/front.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/args.hpp>
#include <tuple>
#include <utility>
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
		::brigand::all<
			::brigand::list<
				fcppt::type_traits::remove_cv_ref_t<
					Variants
				>...
			>,
			fcppt::variant::is_object<
				::brigand::_1
			>
		>::value,
		"Variants must all be variants"
	);

	return
		fcppt::variant::detail::apply(
			_function,
			&fcppt::absurd<
				decltype(
					_function(
						fcppt::move_if_rvalue<
							Variants
						>(
							fcppt::variant::detail::get_unsafe<
								::brigand::front<
									fcppt::variant::types_of<
										fcppt::type_traits::remove_cv_ref_t<
											Variants
										>
									>
								>
							>(
								_variants
							)
						)...
					)
				)
			>,
			std::tuple<>{},
			std::forward<
				Variants
			>(
				_variants
			)...
		);
}

}
}

#endif
