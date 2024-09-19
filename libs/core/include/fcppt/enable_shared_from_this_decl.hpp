//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENABLE_SHARED_FROM_THIS_DECL_HPP_INCLUDED
#define FCPPT_ENABLE_SHARED_FROM_THIS_DECL_HPP_INCLUDED

#include <fcppt/enable_shared_from_this_fwd.hpp> // IWYU pragma: keep
#include <fcppt/shared_ptr_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
/**
\brief Allows an object to obtain a shared ptr to itself.

\ingroup fcpptsmartptr

Derive from this class to allow an object to obtain a shared ptr to itself.
*/
template <typename Type>
class enable_shared_from_this : public std::enable_shared_from_this<Type>
{
  using base = std::enable_shared_from_this<Type>;

protected:
  enable_shared_from_this(); // NOLINT(bugprone-crtp-constructor-accessibility)

  enable_shared_from_this(enable_shared_from_this const &); // NOLINT(bugprone-crtp-constructor-accessibility)

  enable_shared_from_this(enable_shared_from_this &&) noexcept; // NOLINT(bugprone-crtp-constructor-accessibility)

  enable_shared_from_this &operator=(enable_shared_from_this const &);

  enable_shared_from_this &operator=(enable_shared_from_this &&) noexcept;

  ~enable_shared_from_this();

  [[nodiscard]] fcppt::shared_ptr<Type> fcppt_shared_from_this();

  [[nodiscard]] fcppt::shared_ptr<Type const> fcppt_shared_from_this() const;
};

}

#endif
