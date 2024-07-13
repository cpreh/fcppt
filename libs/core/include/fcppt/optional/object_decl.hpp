//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONAL_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_OPTIONAL_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/concepts/move_constructible.hpp> // IWYU pragma: keep
#include <fcppt/optional/object_fwd.hpp> // IWYU pragma: keep
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <optional>
#include <fcppt/config/external_end.hpp>

namespace fcppt::optional
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief A class that makes values optional.

\ingroup fcpptoptional

This class is a wrapper around <code>std::optional</code> that makes the following changes:
<ul>
<li>No <code>operator-></code> and <code>operator*</code>. This has been replaced
<code>get_unsafe</code>.</li> <li>No <code>operator bool()</code>. This has been replaced by
<code>has_value</code>.</li> <li>No assignment from <code>T</code>. Assign an optional instead.</li>
</ul>

\tparam T Must be move constructible.

See \ref fcpptoptional for more information.
*/
template <typename T>
class object
{
public:
  static_assert(fcppt::concepts::move_constructible<T>);

  using std_type = std::optional<T>;

  /**
  \brief The value type.
  */
  using value_type = T;

  /**
  \brief Constructs an empty optional.

  \post has_value() will be false.
  */
  object();

  /**
  \brief Constructs an optional by copying.
  */
  explicit object(T const &);

  /**
  \brief Constructs an optional by moving.
  */
  explicit object(T &&);

  /**
  \brief Returns a reference to the current value.

  \warning The behaviour is undefined if <code>has_value()</code> is false.
  */
  [[nodiscard]] T &get_unsafe();

  /**
  \brief Returns a const reference to the current value.

  \warning The behaviour is undefined if <code>has_value()</code> is false.
  */
  [[nodiscard]] T const &get_unsafe() const;

  /**
  \brief Returns whether the optional holds a value.
  */
  [[nodiscard]] bool has_value() const;

  [[nodiscard]] std_type &impl();

  [[nodiscard]] std_type const &impl() const;
private:
  std_type impl_;
};

FCPPT_PP_POP_WARNING

}

#endif
