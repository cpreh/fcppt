//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/c_deleter.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>

int main()
{
  //! [c_deleter]
  using void_c_ptr = fcppt::unique_ptr<void, fcppt::c_deleter>;

  void_c_ptr const ptr{
      // NOLINTNEXTLINE(cppcoreguidelines-no-malloc,hicpp-no-malloc)
      std::malloc(100)};
  //! [c_deleter]
}
//]
