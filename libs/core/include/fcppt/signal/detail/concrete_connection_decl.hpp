//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_DETAIL_CONCRETE_CONNECTION_DECL_HPP_INCLUDED
#define FCPPT_SIGNAL_DETAIL_CONCRETE_CONNECTION_DECL_HPP_INCLUDED

#include <fcppt/function.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/intrusive/base_decl.hpp>
#include <fcppt/signal/connection_decl.hpp>


namespace fcppt
{
namespace signal
{
namespace detail
{

template<
	typename Function
>
class concrete_connection
:
	public
		fcppt::signal::connection,
	public
		fcppt::intrusive::base<
			fcppt::signal::detail::concrete_connection<
				Function
			>
		>
{
	FCPPT_NONCOPYABLE(
		concrete_connection
	);
public:
	typedef
	fcppt::function<
		Function
	>
	function_type;

	typedef
	fcppt::intrusive::base<
		fcppt::signal::detail::concrete_connection<
			Function
		>
	>
	base_type;

	typedef
	typename
	base_type::list_type
	list_type;

	concrete_connection(
		list_type &,
		function_type const &
	);

	~concrete_connection()
	override;

	function_type const &
	function() const;
private:
	function_type const function_;
};

}
}
}

#endif
