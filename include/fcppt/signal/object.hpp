//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_OBJECT_HPP_INCLUDED
#define FCPPT_SIGNAL_OBJECT_HPP_INCLUDED

#include <fcppt/signal/object_fwd.hpp>
#include <fcppt/signal/base_impl.hpp>
#include <fcppt/signal/detail/operator_limit.hpp>
#include <fcppt/signal/detail/define_operator.hpp>
#include <fcppt/signal/detail/define_void_operator.hpp>
#include <boost/spirit/home/phoenix/core/argument.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/intrusive/list.hpp>
#include <boost/type_traits/is_void.hpp>
#include <boost/type_traits/function_traits.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace signal
{

template<
	typename T,
	typename Base,
	typename Enable
>
class object
:
	public Base
{
public:
	typedef Base base;

	typedef typename base::connection_list connection_list;

	typedef typename boost::function_traits<
		T
	>::result_type result_type;

	typedef fcppt::function::object<
		result_type (
			result_type,
			result_type
		)
	> combiner_type;

	explicit object(
		combiner_type const &_combiner = boost::phoenix::arg_names::arg1
	)
	:
		combiner_(_combiner)
	{}

	void
	combiner(
		combiner_type const &_combiner
	)
	{
		combiner_ = _combiner;
	}

	FCPPT_SIGNAL_DETAIL_DEFINE_EMPTY_OPERATOR

	BOOST_PP_REPEAT(
		FCPPT_SIGNAL_DETAIL_OPERATOR_LIMIT,
		FCPPT_SIGNAL_DETAIL_DEFINE_OPERATOR,
		nil
	)
private:
	combiner_type combiner_;
};

template<
	typename T,
	typename Base
>
class object<
	T,
	Base,
	typename boost::enable_if<
		boost::is_void<
			typename boost::function_traits<
				T
			>::result_type
		>
	>::type
>
:
	public Base
{
public:
	typedef Base base;

	typedef typename base::connection_list connection_list;

	FCPPT_SIGNAL_DETAIL_DEFINE_EMPTY_VOID_OPERATOR

	BOOST_PP_REPEAT(
		FCPPT_SIGNAL_DETAIL_OPERATOR_LIMIT,
		FCPPT_SIGNAL_DETAIL_DEFINE_VOID_OPERATOR,
		nil
	)
};

}
}

#endif
