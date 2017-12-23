//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_CONNECTION_DECL_HPP_INCLUDED
#define FCPPT_SIGNAL_CONNECTION_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/intrusive/base_decl.hpp>
#include <fcppt/intrusive/list_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/signal/connection_fwd.hpp>


namespace fcppt
{
namespace signal
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Wnon-virtual-dtor)

/**
\brief A connection returned by a connect call

\ingroup fcpptsignal

This class must be held onto as long as the connection to the signal should be
established.
*/
class connection
:
	public
		fcppt::intrusive::base
{
	FCPPT_NONCOPYABLE(
		connection
	);
protected:
	template<
		typename Type
	>
	explicit
	connection(
		fcppt::intrusive::list<
			Type
		> &
	);
public:
	virtual
	~connection() = 0;
};

FCPPT_PP_POP_WARNING

}
}

#endif
