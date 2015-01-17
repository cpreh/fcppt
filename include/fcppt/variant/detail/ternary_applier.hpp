//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_TERNARY_APPLIER_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_TERNARY_APPLIER_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
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
	typename T2,
	typename T3
>
class ternary_applier
{
	FCPPT_NONASSIGNABLE(
		ternary_applier
	);
public:
	typedef typename std::remove_reference<
		Operation
	>::type::result_type result_type;

	ternary_applier(
		Operation &_op,
		T2 &_t2,
		T3 &_t3
	)
	:
		op_(
			_op
		),
		t2_(
			_t2
		),
		t3_(
			_t3
		)
	{
	}

	template<
		typename T1
	>
	result_type
	operator()(
		T1 &_t1
	) const
	{
		return
			op_(
				_t1,
				t2_,
				t3_
			);
	}
private:
	Operation &op_;

	T2 &t2_;

	T3 &t3_;
};

}
}
}

#endif
