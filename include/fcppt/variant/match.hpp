//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_MATCH_HPP_INCLUDED
#define FCPPT_VARIANT_MATCH_HPP_INCLUDED

#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/detail/match_visitor.hpp>
#include <fcppt/variant/detail/match_result_type.hpp>
#include <fcppt/config/external_begin.hpp>
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
	typename... Functions
>
inline
typename
fcppt::variant::detail::match_result_type<
	Variant,
	Functions...
>::type
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
			fcppt::variant::detail::match_visitor<
				typename
				fcppt::variant::detail::match_result_type<
					Variant,
					Functions...
				>::type,
				Variant,
				decltype(
					tuple
				)
			>(
				tuple
			),
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
