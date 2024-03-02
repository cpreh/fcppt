//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ENUM_INVALID_DECL_HPP_INCLUDED
#define FCPPT_ENUM_INVALID_DECL_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/enum/invalid_fwd.hpp> // IWYU pragma: keep

namespace fcppt::enum_
{

/**
\brief Exception to use for invalid enums.

\ingroup fcpptenum
*/
template<typename Enum>
class invalid : public fcppt::exception
{
public:
  explicit invalid(Enum);
};

}

#endif
