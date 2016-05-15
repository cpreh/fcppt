//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_TRY_CALL_HPP_INCLUDED
#define FCPPT_EITHER_TRY_CALL_HPP_INCLUDED

#include <fcppt/either/object_impl.hpp>


namespace fcppt
{
namespace either
{

/**
\brief Catches exceptions of a function call and puts the result in an either

\ingroup fcppteither

Calls \a _function in a try block. If \a _function returns <code>s</code>,
then the result is success <code>s</code>.  If the function throws an
exception <code>e</code> of type \a Exception, then the result is the failure
<code>_to_exception(e)</code>.

\tparam Function A function callable as <code>S ()</code> where <code>S</code>
is the success result type

\tparam ToException A function callable as <code>E (Exception)</code> where
<code>E</code> is the failure result type
*/
template<
	typename Exception,
	typename Function,
	typename ToException
>
auto
try_call(
	Function const &_function,
	ToException const &_to_exception
)
->
fcppt::either::object<
	decltype(
		_to_exception(
			Exception{}
		)
	),
	decltype(
		_function()
	)
>
{
	typedef
	fcppt::either::object<
		decltype(
			_to_exception(
				Exception{}
			)
		),
		decltype(
			_function()
		)
	>
	result_type;

	try
	{
		return
			result_type{
				_function()
			};
	}
	catch(
		Exception const &_exception
	)
	{
		return
			result_type{
				_to_exception(
					_exception
				)
			};
	}
}

}
}

#endif
