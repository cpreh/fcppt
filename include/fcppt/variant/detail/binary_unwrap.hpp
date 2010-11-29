//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_BINARY_UNWRAP_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_BINARY_UNWRAP_HPP_INCLUDED

#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/detail/binary_applier.hpp>
#include <fcppt/nonassignable.hpp>

namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Operation,
	typename Variant
>
class binary_unwrap
{
	FCPPT_NONASSIGNABLE(binary_unwrap)
public:
	typedef typename Operation::result_type result_type;

	binary_unwrap(
		Operation const &_op,
		Variant const &_obj
	)
	:
		op_(_op),
		obj_(_obj)
	{}

	template<
		typename T2
	>
	result_type
	operator()(
		T2 const &_t2
	) const
	{
		return
			variant::apply_unary(
				detail::binary_applier<
					Operation,
					T2
				>(
					op_,
					_t2
				),
				obj_
			);
	}
private:
	Operation const &op_;

	Variant const &obj_;
};

}
}
}

#endif
