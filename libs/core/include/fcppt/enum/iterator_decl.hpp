//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_ITERATOR_DECL_HPP_INCLUDED
#define FCPPT_ENUM_ITERATOR_DECL_HPP_INCLUDED

#include <fcppt/enum/iterator_fwd.hpp>
#include <fcppt/enum/size_type.hpp>
#include <fcppt/iterator/base_decl.hpp>
#include <fcppt/iterator/types_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace enum_
{
/**
\ingroup fcpptenum
*/
template <typename Enum>
class iterator final : public fcppt::iterator::base<fcppt::iterator::types<
                           fcppt::enum_::iterator<Enum>,
                           Enum,
                           Enum,
                           std::make_signed_t<fcppt::enum_::size_type<Enum>>,
                           std::input_iterator_tag>>
{
public:
  using size_type = fcppt::enum_::size_type<Enum>;

  explicit iterator(size_type) noexcept;

  void increment() noexcept;

  [[nodiscard]] bool equal(iterator) const noexcept;

  [[nodiscard]] Enum dereference() const noexcept;

private:
  size_type value_;
};

}
}

#endif
