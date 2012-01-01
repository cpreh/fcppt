//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_SIGNAL_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/base_decl.hpp>
#include <fcppt/signal/object_fwd.hpp>
#include <fcppt/signal/detail/declare_operator.hpp>
#include <fcppt/signal/detail/enable_if_void.hpp>
#include <fcppt/signal/detail/operator_limit.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/type_traits/function_traits.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace signal
{

template<
	typename T,
	template<
		typename
	> class Base,
	typename Enable
>
class object
:
	public Base<T>
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	typedef Base<T> base;

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
		combiner_type const &,
		result_type const &initial_result
	);

	~object();

	void
	combiner(
		combiner_type const &
	);

	void
	initial_result(
		result_type const &
	);

	result_type
	operator()() const;

	BOOST_PP_REPEAT(
		FCPPT_SIGNAL_DETAIL_OPERATOR_LIMIT,
		FCPPT_SIGNAL_DETAIL_DECLARE_OPERATOR,
		nil
	)
private:
	combiner_type combiner_;

	result_type initial_result_;
};

template<
	typename T,
	template<
		typename
	> class Base
>
class object<
	T,
	Base,
	typename detail::enable_if_void<
		T
	>::type
>
:
	public Base<T>
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	typedef Base<T> base;

	object();

	~object();

	typedef void result_type;

	result_type
	operator()() const;

	BOOST_PP_REPEAT(
		FCPPT_SIGNAL_DETAIL_OPERATOR_LIMIT,
		FCPPT_SIGNAL_DETAIL_DECLARE_OPERATOR,
		nil
	)
};

}
}

#endif
