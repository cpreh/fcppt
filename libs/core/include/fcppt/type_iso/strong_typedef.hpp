//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_TYPE_ISO_STRONG_TYPEDEF_HPP_INCLUDED
#define FCPPT_TYPE_ISO_STRONG_TYPEDEF_HPP_INCLUDED

#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/type_iso/transform_fwd.hpp>

namespace fcppt::type_iso
{
template <typename Type, typename Alias>
struct transform<fcppt::strong_typedef<Type, Alias>>
{
  using undecorated_type = Type;

  using decorated_type = fcppt::strong_typedef<Type, Alias>;

  static decorated_type decorate(undecorated_type const &_value)
  {
    return decorated_type(_value);
  }

  static undecorated_type undecorate(decorated_type const &_value) { return _value.get(); }
};

}

#endif
