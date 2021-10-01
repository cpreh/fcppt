//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_GET_OR_INSERT_RESULT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GET_OR_INSERT_RESULT_DECL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/container/get_or_insert_result_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container
{
/**
\brief The result type of #fcppt::container::get_or_insert_with_result

\ingroup fcpptcontainer
*/
template <typename Reference>
class get_or_insert_result
{
public:
  static_assert(std::is_reference_v<Reference>, "Reference must be a reference type");

  get_or_insert_result(Reference, bool);

  template <typename Other>
  explicit get_or_insert_result(get_or_insert_result<Other> const &);

  /**
  \brief A reference to the element in the container
  */
  [[nodiscard]] Reference element() const;

  /**
  \brief Tells if the element was inserted

  \return <code>true</code> if the element was inserted, <code>false</code> if it was found.
  */
  [[nodiscard]] bool inserted() const;

private:
  fcppt::reference<std::remove_reference_t<Reference>> reference_;

  bool inserted_;
};

}

#endif
