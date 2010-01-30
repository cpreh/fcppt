//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_DETAIL_CONCRETE_CONNECTION_HPP_INCLUDED
#define FCPPT_SIGNAL_DETAIL_CONCRETE_CONNECTION_HPP_INCLUDED

#include <fcppt/signal/detail/connection.hpp>
#include <fcppt/function/object.hpp>

namespace fcppt
{
namespace signal
{
namespace detail
{
template<typename T>
class concrete_connection : public connection
{
public:
	typedef T function_signature;
	typedef fcppt::function::object<T> function_type;

	concrete_connection(
		function_type const &);

	function_type &function();
private:
	function_type function_;
};
}
}
}

#endif
