//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_BINARY_APPLIER_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_BINARY_APPLIER_HPP_INCLUDED

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
	typename T2
>
class binary_applier
{
	FCPPT_NONASSIGNABLE(
		binary_applier
	);
public:
	typedef typename std::remove_reference<
		Operation
	>::type::result_type result_type;

	binary_applier(
		Operation &_op,
		T2 &_t2
	)
	:
		op_(
			_op
		),
		t2_(
			_t2
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
				t2_
			);
	}
private:
	Operation &op_;

	T2 &t2_;
};

}
}
}

#endif
