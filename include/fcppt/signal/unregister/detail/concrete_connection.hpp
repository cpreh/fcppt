//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_UNREGISTER_DETAIL_CONCRETE_CONNECTION_HPP_INCLUDED
#define FCPPT_SIGNAL_UNREGISTER_DETAIL_CONCRETE_CONNECTION_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/connection.hpp>
#include <fcppt/signal/unregister/function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


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
	public fcppt::signal::connection
{
	FCPPT_NONCOPYABLE(
		concrete_connection
	);
public:
	typedef T function_signature;

	typedef std::function<
		T
	> function_type;

	concrete_connection(
		function_type const &,
		fcppt::signal::unregister::function const &
	);

	~concrete_connection()
	override;

	function_type &
	function();
private:
	function_type function_;

	fcppt::signal::unregister::function unregister_;
};

}
}
}
}

#endif
