//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_MATCH_HPP_INCLUDED
#define FCPPT_VARIANT_MATCH_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/metal/from_number.hpp>
#include <fcppt/metal/index_of.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/variant/apply.hpp>
#include <fcppt/variant/is_object.hpp>
#include <fcppt/variant/types_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <tuple>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Matches a variant with a function for each element type

\ingroup fcpptvariant

Matches \a _variant with \a _functions. The functions must be listed in the
order the types appear in the variant.
*/
template<
	typename Variant,
	typename... Functions,
	typename Enable =
		fcppt::variant::is_object<
			fcppt::type_traits::remove_cv_ref_t<
				Variant
			>
		>
>
inline
decltype(
	auto
)
match(
	Variant &&_variant,
	Functions const &... _functions
)
{
	auto const tuple(
		std::make_tuple(
			_functions...
		)
	);

	return
		fcppt::variant::apply(
			[
				&tuple
			](
				auto &&_arg
			)
			->
			decltype(
				auto
			)
			{
				return
					std::get<
						fcppt::metal::from_number<
							std::size_t,
							fcppt::metal::index_of<
								fcppt::variant::types_of<
									fcppt::type_traits::remove_cv_ref_t<
										Variant
									>
								>,
								fcppt::type_traits::remove_cv_ref_t<
									decltype(
										_arg
									)
								>
							>
						>::value
					>(
						tuple
					)(
						fcppt::move_if_rvalue<
							Variant
						>(
							_arg
						)
					);
			},
			std::forward<
				Variant
			>(
				_variant
			)
		);
}

}
}

#endif
