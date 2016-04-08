//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_INVOKE_ON_HPP_INCLUDED
#define FCPPT_MPL_INVOKE_ON_HPP_INCLUDED

#include <fcppt/tag.hpp>
#include <fcppt/use.hpp>
#include <fcppt/mpl/runtime_index.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/size.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

/**
\brief Applies a function to the nth element of a sequence with a runtime index

\ingroup fcpptmpl

Applies \a _function to the nth element (where n is denoted by \a _index) of
the sequence \a Sequence. This can be useful if you have a runtime index into
an MPL sequence and you want to invoke something on that type. If \a _index is
out of range, the result of <code>_fail_function()</code> is returned.

\note The compile time and the runtime complexities of this function are linear
in the size of the MPL sequence

\snippet mpl/invoke_on.cpp mpl_invoke_on

\tparam Sequence An MPL sequence

\tparam Index An unsigned type

\tparam Function Must be callable with <code>operator()%<T%>()</code> for every T
in \a Sequence

\tparam FailFunction Must be a callable with no parameters.

\param _index The runtime index of type \a Index

\param _function The function to invoke

\param _fail_function The function to call when \a _index is out of range.

\return The result of <code>_function%<T%>()</code> if <code>T</code> is the
element of \a Sequence at \a _index
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
		"mpl::invoke_on can only be used with unsigned indices"
	);

	return
		fcppt::mpl::runtime_index<
			typename
			boost::mpl::size<
				Sequence
			>::type
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
							typename
							boost::mpl::at_c<
								Sequence,
								decltype(
									_cur_index
								)::value
							>::type
						>()
					);
			},
			_fail_function
		);
}

}
}

#endif
