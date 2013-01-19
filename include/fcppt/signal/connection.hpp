//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_CONNECTION_HPP_INCLUDED
#define FCPPT_SIGNAL_CONNECTION_HPP_INCLUDED

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

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief A connection returned by a connect call

\ingroup fcpptsignal

This class must be held onto as long as the connection should to the signal
should be established.
*/
class FCPPT_CLASS_SYMBOL connection
:
	public fcppt::signal::detail::connection_base
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

#endif
