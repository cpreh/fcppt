//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SCOPED_STATE_MACHINE_DECL_HPP_INCLUDED
#define FCPPT_SCOPED_STATE_MACHINE_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/scoped_state_machine_fwd.hpp>


namespace fcppt
{

template
<
	typename Machine
>
class scoped_state_machine
{
	FCPPT_NONCOPYABLE(
		scoped_state_machine
	);
public:
	explicit
	scoped_state_machine(
		Machine &
	);

	~scoped_state_machine();
private:
	Machine &machine_;
};

}

#endif
