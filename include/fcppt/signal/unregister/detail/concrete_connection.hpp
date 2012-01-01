//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_UNREGISTER_DETAIL_CONCRETE_CONNECTION_HPP_INCLUDED
#define FCPPT_SIGNAL_UNREGISTER_DETAIL_CONCRETE_CONNECTION_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/signal/detail/connection.hpp>
#include <fcppt/signal/unregister/function.hpp>


namespace fcppt
{
namespace signal
{
namespace unregister
{
namespace detail
{

template<
	typename T
>
class concrete_connection
:
	public signal::detail::connection
{
	FCPPT_NONCOPYABLE(
		concrete_connection
	);
public:
	typedef T function_signature;

	typedef fcppt::function::object<T> function_type;

	explicit concrete_connection(
		function_type const &,
		unregister::function const &
	);

	~concrete_connection();

	function_type &
	function();
private:
	function_type function_;

	unregister::function unregister_;
};

}
}
}
}

#endif
