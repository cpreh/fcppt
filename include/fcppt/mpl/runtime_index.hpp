//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_RUNTIME_INDEX_HPP_INCLUDED
#define FCPPT_MPL_RUNTIME_INDEX_HPP_INCLUDED

#include <fcppt/mpl/detail/runtime_index.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

/**
\brief Transforms a runtime index into a an integral constant

\ingroup fcpptmpl

Passes \a _index as an integral constant to \a _function if \a _index is less
than \a MaxIndex::value. Otherwise, \a _fail_function is called.

\tparam Index An integer type

\tparam MaxIndex An integral constant

\tparam Function A function callable with an integral constant

\tparam FailFunction A function callable with no arguments
*/
template<
	typename MaxIndex,
	typename Index,
	typename Function,
	typename FailFunction
>
inline
typename
boost::enable_if<
	std::is_unsigned<
		Index
	>,
	typename
	Function::result_type
>::type
runtime_index(
	Index const _index,
	Function const &_function,
	FailFunction const &_fail_function
)
{
	return
		fcppt::mpl::detail::runtime_index<
			MaxIndex,
			boost::mpl::integral_c<
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
