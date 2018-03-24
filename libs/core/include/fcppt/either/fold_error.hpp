//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_FOLD_ERROR_HPP_INCLUDED
#define FCPPT_EITHER_FOLD_ERROR_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/algorithm/fold_break.hpp>
#include <fcppt/container/to_value_type.hpp>
#include <fcppt/either/is_object.hpp>
#include <fcppt/either/match.hpp>
#include <fcppt/either/no_error.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace either
{

/**
\brief Folds over a range, breaking out on the first error.

\ingroup fcppteither

This function is similar to \link fcppt::either::sequence\endlink, except it
does not produce an output sequence. Instead, \a _function returns \link
fcppt::either::error\endlink, which on success contains an \link
fcppt::unit\endlink on success.
Let <code>_sequence = [x_1, ..., x_n]</code>.
The algorithms calls <code>_function(x_1), ..., _function(x_i)</code>,
where <code>_function(x_i)</code> is either the first call that returns a failure, in
which case the failure is returned as the result, or <code>i=n</code>, in which case
success is returned.

\tparam Sequence Must be a range.

\tparam Function Must be a function callable as
<code>fcppt::either::error<T>(Sequence::value_type)</code> for some type <code>T</code>.
*/
template<
	typename Sequence,
	typename Function
>
auto
fold_error(
	Sequence &&_sequence,
	Function const &_function
)
->
decltype(
	_function(
		std::declval<
			fcppt::container::to_value_type<
				std::remove_reference_t<
					Sequence
				>
			>
		>()
	)
)
{
	typedef
	decltype(
		_function(
			std::declval<
				fcppt::container::to_value_type<
					std::remove_reference_t<
						Sequence
					>
				>
			>()
		)
	)
	either_type;

	static_assert(
		fcppt::either::is_object<
			either_type
		>::value,
		"Function must return an either"
	);

	static_assert(
		std::is_same<
			typename
			either_type::success,
			fcppt::either::no_error
		>::value,
		"Function must return an either::error"
	);

	return
		fcppt::algorithm::fold_break(
			std::forward<
				Sequence
			>(
				_sequence
			),
			either_type{
				fcppt::either::no_error{}
			},
			[
				&_function
			](
				auto &&_element,
				either_type
			)
			{
				return
					fcppt::either::match(
						_function(
							fcppt::move_if_rvalue<
								Sequence
							>(
								_element
							)
						),
						[](
							typename
							either_type::failure &&_error
						)
						{
							return
								std::make_pair(
									fcppt::loop::break_,
									either_type{
										std::move(
											_error
										)
									}
								);
						},
						[](
							fcppt::either::no_error
						){
							return
								std::make_pair(
									fcppt::loop::continue_,
									either_type{
										fcppt::either::no_error{}
									}
								);
						}
					);
			}
		);
}

}
}

#endif
