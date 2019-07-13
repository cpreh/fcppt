//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_SIGNAL_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/function.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/signal/base_decl.hpp>
#include <fcppt/signal/object_fwd.hpp>
#include <fcppt/signal/detail/enable_if_void.hpp>
#include <fcppt/type_traits/function_result.hpp>


namespace fcppt
{
namespace signal
{

/**
\brief Represents a signal with a non-void return value
\tparam T The signal's function type
\tparam Base The signal's base class (determines the existence of unregister functions)
\tparam Enable Dummy for SFINAE operations
\ingroup fcpptsignal

See \ref fcpptsignal for more information.
*/
template<
	typename T,
	template<
		typename
	> class Base,
	typename Enable
>
class object
:
private
	Base<
		T
	>
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	/**
	\brief A typedef for the signal's base class
	*/
	typedef
	Base<
		T
	>
	base;

	/**
	\brief A typedef for the function's return type
	*/
	typedef
	typename
	fcppt::type_traits::function_result<
		T
	>::type
	result_type;

	typedef
	typename
	base::function
	function;

	/**
	\brief Typedef to the combiner function
	*/
	typedef
	fcppt::function<
		result_type (
			result_type,
			result_type
		)
	>
	combiner_function;

	FCPPT_MAKE_STRONG_TYPEDEF(
		result_type,
		initial_value
	);

	/**
	\brief Construct a signal with a combiner
	*/
	explicit
	object(
		combiner_function &&
	);

	object(
		object &&
	);

	object &
	operator=(
		object &&
	);

	~object();

	/**
	\brief Call the signal
	*/
	template<
		typename... Args
	>
	result_type
	operator()(
		initial_value &&,
		Args &&...
	);

	using base::connect;

	using base::empty;

	using base::connections;
private:
	combiner_function combiner_;
};


/**
\brief Represents a signal without a return value
\tparam T The signal's function type
\tparam Base The signal's base class (determines the existence of unregister functions)
\ingroup fcpptsignal

See the #fcpptsignal module documentation  for more information.
*/
template<
	typename T,
	template<
		typename
	> class Base
>
class object<
	T,
	Base,
	fcppt::signal::detail::enable_if_void<
		T
	>
>
:
private
	Base<
		T
	>
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	/**
	\brief A typedef for the signal's base class
	*/
	typedef
	Base<
		T
	>
	base;

	typedef
	typename
	base::function
	function;

	/**
	\brief Construct an empty signal
	*/
	object();

	object(
		object &&
	);

	object &
	operator=(
		object &&
	);

	~object();

	/**
	\brief Typedef to the function's return type
	*/
	typedef
	void
	result_type;

	/**
	\brief Call the signal
	*/
	template<
		typename... Args
	>
	result_type
	operator()(
		Args &&...
	);

	using base::connect;

	using base::empty;

	using base::connections;
};

}
}

#endif
