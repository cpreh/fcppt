//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_TERNARY_UNWRAP_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_TERNARY_UNWRAP_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/detail/ternary_applier.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
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
class ternary_unwrap
{
	FCPPT_NONASSIGNABLE(
		ternary_unwrap
	);
public:
	typedef typename std::remove_reference<
		Operation
	>::type::result_type result_type;

	ternary_unwrap(
		Operation &_op,
		Variant &_obj
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
		typename T2,
		typename T3
	>
	result_type
	operator()(
		T2 &_t2,
		T3 &_t3
	) const
	{
		return
			fcppt::variant::apply_unary(
				fcppt::variant::detail::ternary_applier<
					Operation,
					T2,
					T3
				>(
					op_,
					_t2,
					_t3
				),
				obj_
			);
	}
private:
	Operation &op_;

	Variant &obj_;
};

}
}
}

#endif
