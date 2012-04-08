//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_DETAIL_CONNECTION_HPP_INCLUDED
#define FCPPT_SIGNAL_DETAIL_CONNECTION_HPP_INCLUDED

#include <fcppt/class_symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/signal/detail/connection_base.hpp>


namespace fcppt
{
namespace signal
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

// this class is intentionally left blank
class FCPPT_CLASS_SYMBOL connection
:
	public detail::connection_base
{

FCPPT_PP_POP_WARNING

	FCPPT_NONCOPYABLE(
		connection
	);
public:
	FCPPT_SYMBOL
	connection();

	FCPPT_SYMBOL
	virtual ~connection();
};

}
}
}

#endif
