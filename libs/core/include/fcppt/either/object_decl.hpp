//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_EITHER_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/concepts/move_constructible.hpp> // IWYU pragma: keep
#include <fcppt/either/object_fwd.hpp> // IWYU pragma: keep
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <expected>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::either
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)
FCPPT_PP_DISABLE_VC_WARNING(5027)

/**
\brief A class that either holds a success or an error value.

\ingroup fcppteither

This class is a wrapper around <code>std::expected</code>. The changes are:
<ul>
<li>No default constructor.</li>
<li>No <code>operator-></code>, <code>operator*</code> or <code>value</code> function. This has been replaced with <code>get_success_unsafe</code>.</li>
<li>No <code>error</code> function. This has been replaced with <code>get_failure_unsafe</code>.</li>
<li>No assignment from <code>Success</code>. Assign an either instead.</li>
</ul>

\tparam Failure Must be move constructible.
\tparam Success Must be move constructible.
*/
template <typename Failure, typename Success>
class object
{
public:
  using failure = Failure;

  using success = Success;

  using std_type = std::expected<Success, Failure>;

  static_assert(fcppt::concepts::move_constructible<Failure>);
  static_assert(fcppt::concepts::move_constructible<Success>);
  static_assert(!std::is_same_v<Failure, Success>, "Success and Failure must be distinct");

  explicit object(Success &&);

  explicit object(Success const &);

  explicit object(Failure &&);

  explicit object(Failure const &);

  [[nodiscard]] bool has_success() const;

  [[nodiscard]] bool has_failure() const;

  [[nodiscard]] Success &get_success_unsafe();

  [[nodiscard]] Success const &get_success_unsafe() const;

  [[nodiscard]] Failure &get_failure_unsafe();

  [[nodiscard]] Failure const &get_failure_unsafe() const;

  [[nodiscard]] std_type &impl();

  [[nodiscard]] std_type const &impl() const;
private:
  std_type impl_;
};

FCPPT_PP_POP_WARNING

}

#endif
