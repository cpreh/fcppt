//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_SCOPED_STATE_MACHINE_DECL_HPP_INCLUDED
#define FCPPT_SCOPED_STATE_MACHINE_DECL_HPP_INCLUDED

#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_decl.hpp>
#include <fcppt/scoped_state_machine_fwd.hpp>

namespace fcppt
{
/**
\brief Scopes a boost state machine

\ingroup fcpptboost

Calls initiate in the constructor and terminate in the destructor.

\tparam Machine Must be a boost::statechart::state_machine
*/
template <typename Machine>
class scoped_state_machine
{
  FCPPT_NONMOVABLE(scoped_state_machine);

public:
  using machine_ref = fcppt::reference<Machine>;

  explicit scoped_state_machine(machine_ref);

  ~scoped_state_machine();

private:
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
  machine_ref const machine_;
};

}

#endif
