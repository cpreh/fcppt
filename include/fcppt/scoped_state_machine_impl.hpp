//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SCOPED_STATE_MACHINE_IMPL_HPP_INCLUDED
#define FCPPT_SCOPED_STATE_MACHINE_IMPL_HPP_INCLUDED

#include <fcppt/scoped_state_machine_decl.hpp>

template
<
	typename Machine
>
fcppt::scoped_state_machine<Machine>::scoped_state_machine(
	Machine &_machine
)
:
	machine_(
		_machine
	)
{
	machine_.initiate();
}

template
<
	typename Machine
>
fcppt::scoped_state_machine<Machine>::~scoped_state_machine()
{
	machine_.terminate();
}

#endif
