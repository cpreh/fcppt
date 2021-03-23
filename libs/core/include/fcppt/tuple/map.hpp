//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TUPLE_MAP_HPP_INCLUDED
#define FCPPT_TUPLE_MAP_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/init.hpp>
#include <fcppt/tuple/is_object.hpp>
#include <fcppt/tuple/map_result.hpp>
#include <fcppt/tuple/size.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::tuple
{
/**
\brief Maps over a tuple.

\ingroup fcppttuple

Let \a _tuple be <code>(v_1,...,v_n)</code>.
The result of the function is the tuple <code>(_function(v_1),...,_function(v_n))</code>.

\tparam Tuple Must be an <code>fcppt::tuple::object</code>.

\tparam Function Must be callable with every type in \a Tuple.
*/
template <
    typename Tuple,
    typename Function,
    typename = std::enable_if_t<
        fcppt::tuple::is_object<fcppt::type_traits::remove_cv_ref_t<Tuple>>::value>>
fcppt::tuple::map_result<Tuple, Function> map(Tuple &&_tuple, Function const &_function)
{
  using source_type = fcppt::type_traits::remove_cv_ref_t<Tuple>;
  using result_type = fcppt::tuple::map_result<Tuple, Function>;
  static_assert(fcppt::tuple::size<source_type>::value == fcppt::tuple::size<result_type>::value);

  return fcppt::tuple::init<result_type>([&_function,&_tuple](auto const _index) {
    return _function(fcppt::move_if_rvalue<Tuple>(fcppt::tuple::get<_index()>(_tuple)));
  });
}
}

#endif
