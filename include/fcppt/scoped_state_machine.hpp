//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SCOPED_STATE_MACHINE_HPP_INCLUDED
#define FCPPT_SCOPED_STATE_MACHINE_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>

namespace fcppt
{
// FIXME: Split to _impl, _decl, _fwd and the normal file
template
<
	typename Machine
>
class scoped_state_machine
{
FCPPT_NONCOPYABLE(scoped_state_machine)
public:
	explicit 
	scoped_state_machine(
		Machine &_machine)
	:
		machine_(
			_machine)
	{
		machine_.initiate();
	}

	~scoped_state_machine()
	{
		machine_.terminate();
	}
private:
	Machine &machine_;
};
}

#endif
