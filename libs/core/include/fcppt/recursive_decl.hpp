//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECURSIVE_DECL_HPP_INCLUDED
#define FCPPT_RECURSIVE_DECL_HPP_INCLUDED

#include <fcppt/recursive_fwd.hpp> // IWYU pragma: keep
#include <fcppt/unique_ptr_decl.hpp>

namespace fcppt
{
/**
\brief Turns an incomplete type into a complete one, allowing recursion.

\ingroup fcpptvarious

Unfortunately, C++ makes no guarantees that incomplete types
can be used as a template parameter of a container like
std::vector. For example, the following might or might not work:
\code
struct X { std::vector<X> x; };
\endcode
The recursive class uses a unique pointer internally which allows
its type to be incomplete. We can therefore write
\code
struct X { std::vector<fcppt::recursive<X>> x; };
\endcode
*/
template <typename Type>
class recursive
{
public:
  explicit recursive(Type const &);

  explicit recursive(Type &&);

  recursive(recursive const &);

  recursive(recursive &&) noexcept;

  recursive &operator=(recursive const &);

  recursive &operator=(recursive &&) noexcept;

  ~recursive();

  [[nodiscard]] Type &get();

  [[nodiscard]] Type const &get() const;

  [[nodiscard]] Type *operator->();

  [[nodiscard]] Type const *operator->() const;
private:
  fcppt::unique_ptr<Type> impl_;
};

}

#endif
