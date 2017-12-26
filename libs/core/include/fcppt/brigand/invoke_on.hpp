//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_INVOKE_ON_HPP_INCLUDED
#define FCPPT_BRIGAND_INVOKE_ON_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/use.hpp>
#include <fcppt/brigand/runtime_index.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/at.hpp>
#include <brigand/sequences/size.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief Applies a function to the nth element of a sequence with a runtime index.

\ingroup fcpptbrigand

Let \a Sequence be the types <code>(t_0,...,t_{n-1})</code> and <code>i =
_index</code>.
If i is less than n,
the result is \a _function called with <code>fcppt::tag<t_i></code>.
Otherwise, the result of \a _fail_function is returned.

\note The compile time and the runtime cobrigandexities of this function are linear
in the size of the BRIGAND sequence.

\snippet brigand/invoke_on.cpp brigand_invoke_on

\tparam Sequence An BRIGAND sequence.

\tparam Index An unsigned type.

\tparam Function Must be callable as <code>R fcppt::tag<T>()</code> for every T
in \a Sequence, where R is the result type.

\tparam FailFunction Must be a callable as <code>R ()</code>, where R is the result tye.
*/
template<
	typename Sequence,
	typename Index,
	typename Function,
	typename FailFunction
>
decltype(
	auto
)
invoke_on(
	Index const &_index,
	Function const &_function,
	FailFunction const &_fail_function
)
{
	static_assert(
		std::is_unsigned<
			Index
		>::value,
		"brigand::invoke_on can only be used with unsigned indices"
	);

	return
		fcppt::brigand::runtime_index<
			::brigand::size<
				Sequence
			>
		>(
			_index,
			[
				&_function
			](
				auto const _cur_index
			)
			->
			decltype(
				auto
			)
			{
				FCPPT_USE(
					_cur_index
				);

				return
					_function(
						fcppt::tag<
							::brigand::at_c<
								Sequence,
								decltype(
									_cur_index
								)::value
							>
						>()
					);
			},
			_fail_function
		);
}

}
}

#endif
