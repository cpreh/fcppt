//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_ASSIGN_VALUE_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_ASSIGN_VALUE_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Value
>
class assign_value
{
	FCPPT_NONASSIGNABLE(
		assign_value
	);
public:
	explicit assign_value(
		Value const &_value
	)
	:
		value_(_value)
	{
	}

	typedef void result_type;

	template<
		typename T
	>
	typename boost::enable_if<
		boost::is_same<
			T,
			Value
		>,
		result_type
	>::type
	operator()(
		T &_left
	) const
	{
		BOOST_STATIC_ASSERT(
			!boost::is_const<
				T
			>::value
		);

		_left = value_;
	}

	template<
		typename T
	>
	typename boost::disable_if<
		boost::is_same<
			T,
			Value
		>,
		result_type
	>::type
	operator()(
		T &
	) const
	{
		BOOST_STATIC_ASSERT(
			!boost::is_const<
				T
			>::value
		);
	}
private:
	Value const &value_;
};

}
}
}

#endif
