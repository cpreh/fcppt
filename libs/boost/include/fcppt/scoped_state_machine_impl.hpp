//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_SCOPED_STATE_MACHINE_IMPL_HPP_INCLUDED
#define FCPPT_SCOPED_STATE_MACHINE_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp> // IWYU pragma: keep
#include <fcppt/scoped_state_machine_decl.hpp> // IWYU pragma: export

template <typename Machine>
fcppt::scoped_state_machine<Machine>::scoped_state_machine(machine_ref const _machine)
    : machine_{_machine}
{
  this->machine_->initiate();
}

namespace fcppt
{
template <typename Machine>
scoped_state_machine<Machine>::~scoped_state_machine()
{
  this->machine_->terminate();
}
}

#endif
