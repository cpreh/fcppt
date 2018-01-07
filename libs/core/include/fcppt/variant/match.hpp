//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_MATCH_HPP_INCLUDED
#define FCPPT_VARIANT_MATCH_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/types_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/index_of.hpp>
#include <tuple>
#include <type_traits>
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
	typename... Functions
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
		fcppt::variant::apply_unary(
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
						::brigand::index_of<
							fcppt::variant::types_of<
								typename
								std::decay<
									Variant
								>::type
							>,
							typename
							std::decay<
								decltype(
									_arg
								)
							>::type
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
