//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_OPERATION_WRAPPER_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_OPERATION_WRAPPER_HPP_INCLUDED

#include <fcppt/variant/detail/unwrap_recursive.hpp>
#include <fcppt/nonassignable.hpp>

namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Operation
>
class operation_wrapper
{
	FCPPT_NONASSIGNABLE(operation_wrapper)
public:
	typedef typename Operation::result_type result_type;

	explicit operation_wrapper(
		Operation const &op_
	)
	:
		op_(op_)
	{}

	template<
		typename T
	>
	result_type
	operator()(
		T const &t
	) const
	{
		return
			op_(
				detail::unwrap_recursive(
					t
				)
			);
	}
private:
	Operation const &op_;
};

}
}
}

#endif
