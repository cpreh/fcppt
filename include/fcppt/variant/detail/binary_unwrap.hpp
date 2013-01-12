//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_BINARY_UNWRAP_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_BINARY_UNWRAP_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/detail/binary_applier.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


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
	FCPPT_NONASSIGNABLE(
		binary_unwrap
	);
public:
	typedef typename Operation::result_type result_type;

	binary_unwrap(
		Operation const &_op,
		Variant &&_obj
	)
	:
		op_(
			_op
		),
		obj_(
			_obj
		)
	{
	}

	template<
		typename T2
	>
	result_type
	operator()(
		T2 &&_t2
	) const
	{
		return
			fcppt::variant::apply_unary(
				fcppt::variant::detail::binary_applier<
					Operation,
					T2
				>(
					op_,
					std::forward<
						T2
					>(
						_t2
					)
				),
				std::forward<
					Variant
				>(
					obj_
				)
			);
	}
private:
	Operation const &op_;

	Variant &&obj_;
};

}
}
}

#endif
