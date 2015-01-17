//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_MAP_CONCAT_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_MAP_CONCAT_HPP_INCLUDED

#include <fcppt/algorithm/fold.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename TargetContainer,
	typename SourceContainer,
	typename Function,
	typename BinOp
>
inline
TargetContainer
map_concat(
	SourceContainer const &_source,
	Function const &_function,
	BinOp const &_bin_op
)
{
	return
		fcppt::algorithm::fold(
			_source,
			TargetContainer(),
			[
				&_function,
				&_bin_op
			](
				typename SourceContainer::const_reference _ref,
				TargetContainer &&_state
			)
			{
				return
					_bin_op(
						std::move(
							_state
						),
						_function(
							_ref
						)
					);
			}
		);
}

}
}
}

#endif
