//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_RUNTIME_INDEX_HPP_INCLUDED
#define FCPPT_BRIGAND_RUNTIME_INDEX_HPP_INCLUDED

#include <fcppt/brigand/detail/runtime_index.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief Transforms a runtime index into a an integral constant.

\ingroup fcpptbrigand

Passes \a _index as an integral constant to \a _function if \a _index is less
than \a MaxIndex::value, and returns its result.
Otherwise, the result of \a _fail_function is returned.

\tparam Index An unsigned integer type.

\tparam MaxIndex An integral constant.

\tparam Function A function callable as <code>R (std::integral_constant<Index,N>)</code> for
every N of type \a Index, where R is the result type.

\tparam FailFunction A function callable as <code> R()</code>, where R is the result type.
*/
template<
	typename MaxIndex,
	typename Index,
	typename Function,
	typename FailFunction
>
inline
decltype(
	auto
)
runtime_index(
	Index const _index,
	Function const &_function,
	FailFunction const &_fail_function
)
{
	static_assert(
		std::is_unsigned<
			Index
		>::value,
		"runtime_index can only be used with unsigned indices"
	);

	return
		fcppt::brigand::detail::runtime_index<
			MaxIndex,
			std::integral_constant<
				Index,
				0
			>
		>::execute(
			_index,
			_function,
			_fail_function
		);

}

}
}

#endif
