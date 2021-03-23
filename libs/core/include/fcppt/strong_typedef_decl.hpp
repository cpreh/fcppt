//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_STRONG_TYPEDEF_DECL_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/strong_typedef_fwd.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief Used to create strong typedefs

\ingroup fcpptstrongtypedef

\tparam T The underlying type to be wrapped.

\tparam Tag A unique tag type

A strong typedef is a wrapper around a type. It has an explicit constructor and
a get member function.
*/
template <typename T, typename Tag>
class strong_typedef
{
public:
  static_assert(!std::is_reference_v<T>, "T must be a non-reference type");

  /**
  \brief A type that represents the data stored in the strong typedef
  */
  using value_type = T;

  /**
  \brief typedef for the <code>Tag</code> template parameter
  */
  using tag_type = Tag;

  /**
  \brief Constructs a strong typedef by copying.
  */
  constexpr explicit strong_typedef(T) noexcept(std::is_nothrow_move_constructible_v<T>);

  /**
  \brief Creates an uninitialized strong typedef.
  */
  explicit strong_typedef(fcppt::no_init const &);

  /**
  \brief Return the strong typedef's value.
  */
  [[nodiscard]] constexpr T &get();

  /**
  \brief Return the strong typedef's value.
  */
  [[nodiscard]] constexpr T const &get() const;
private:
  T value_;
};

FCPPT_PP_POP_WARNING

}

#endif
