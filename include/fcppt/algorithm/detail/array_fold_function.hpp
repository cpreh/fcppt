//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_ARRAY_FOLD_FUNCTION_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_ARRAY_FOLD_FUNCTION_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Result,
	typename Function
>
class array_fold_function
{
	FCPPT_NONASSIGNABLE(
		array_fold_function
	);
public:
	explicit
	array_fold_function(
		Function const &_function
	)
	:
		function_(
			_function
		)
	{
	}

	template<
		typename Index
	>
	Result
	operator()(
		Index
	) const
	{
		return
			function_(
				Index::value
			);
	}
private:
	Function const &function_;
};

}
}
}

#endif
