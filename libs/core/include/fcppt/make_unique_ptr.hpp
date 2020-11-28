//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_MAKE_UNIQUE_PTR_HPP_INCLUDED
#define FCPPT_MAKE_UNIQUE_PTR_HPP_INCLUDED

#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Like <code>std::make_unique</code> for #fcppt::unique_ptr

\ingroup fcpptsmartptr
*/
template <typename Res, typename... Args>
inline fcppt::unique_ptr<Res> make_unique_ptr(Args &&..._args)
{
  return fcppt::unique_ptr<Res>(std::make_unique<Res>(std::forward<Args>(_args)...));
}

}

#endif
