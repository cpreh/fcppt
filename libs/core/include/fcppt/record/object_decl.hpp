//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_RECORD_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/all_of.hpp>
#include <fcppt/mpl/list/as_tuple.hpp>
#include <fcppt/mpl/list/distinct.hpp>
#include <fcppt/mpl/list/map.hpp>
#include <fcppt/mpl/list/object_fwd.hpp> // IWYU pragma: keep
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element_to_type.hpp>
#include <fcppt/record/is_element.hpp>
#include <fcppt/record/is_vararg_ctor.hpp>
#include <fcppt/record/label_value_type.hpp>
#include <fcppt/record/object_fwd.hpp>
#include <fcppt/record/detail/label_list.hpp>

namespace fcppt::record
{
FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4521)
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief A generic struct that identifies elements by types.

\ingroup fcpptrecord

A record of an MPL sequence #fcppt::record::element
<code>element<L_1,T_1>,...,element<L_n,T_n></code> contains an object
of type <code>T_i</code>, accessible by <code>L_i</code>,
for every <code>i = 1,...,n</code>.

\tparam Elements Each one must be of type #fcppt::record::element.
*/
template <typename... Elements>
class object
{
public:
  using all_types = fcppt::mpl::list::object<Elements...>;

  static_assert(
      fcppt::mpl::list::all_of<all_types, fcppt::mpl::lambda<fcppt::record::is_element>>::value,
      "Types of a record::object must all be fcppt::record::element<>");

  static_assert(
      fcppt::mpl::list::distinct<fcppt::record::detail::label_list<all_types>>::value,
      "Labels of record::object must form a set");

  using this_type = fcppt::record::object<Elements...>;

  /**
  \brief The fcppt::tuple::object type <code>(T_1,...,T_n)</code>.
  */
  using tuple = fcppt::mpl::list::as_tuple<
      fcppt::mpl::list::map<all_types, fcppt::mpl::lambda<fcppt::record::element_to_type>>>;

  /**
  \brief Constructor for empty records

  Calling this if \a Elements is not empty, a compile-time error occurs.
  */
  object();

  /**
  \brief An uninitialized record

  Calls only default constructors for its elements. Use this with care.
  */
  explicit object(fcppt::no_init const &);

  /**
  \brief Generic constructor.

  Initializing an <code>element<L_i,T_i></code> is done by calling
  <code>L_i{} = v_i</code> where <code>v_i</code> is of type <code>T_i</code>.

  The constructor checks that each <code>L_i</code> appears exactly once in \a Args.

  \param _args A parameter pack, obtained by assignment to #fcppt::record::label.

  \tparam Args Implementation-defined init types, obtained by assignment
  to #fcppt::record::label.
  */
  template <typename... Args>
  explicit object(Args &&..._args)
    requires(fcppt::record::is_vararg_ctor<Args...>::value);

  /**
  \brief Sets an element by copy.

  \see fcppt::record::set.
  */
  template <typename Label>
  void set(fcppt::record::label_value_type<this_type, Label> const &);

  /**
  \brief Sets an element by move.

  \see fcppt::record::set.
  */
  template <typename Label>
  void set(fcppt::record::label_value_type<this_type, Label> &&);

  /**
  \brief Gets an element.

  \see fcppt::record::get.
  */
  template <typename Label>
  [[nodiscard]] fcppt::record::label_value_type<this_type, Label> const &get() const;

  /**
  \brief Gets an element.

  \see fcppt::record::get.
  */
  template <typename Label>
  [[nodiscard]] fcppt::record::label_value_type<this_type, Label> &get();

  [[nodiscard]] tuple &impl();

  [[nodiscard]] tuple const &impl() const;

private:
  tuple elements_;
};

FCPPT_PP_POP_WARNING

}

#endif
