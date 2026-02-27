//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/reference_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/container/maybe_front.hpp>
#include <fcppt/filesystem/extension.hpp>
#include <fcppt/filesystem/extension_without_dot.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <fcppt/config/external_end.hpp>

fcppt::string fcppt::filesystem::extension_without_dot(std::filesystem::path const &_path)
{
  fcppt::string ret{fcppt::filesystem::extension(_path)};

  if (fcppt::optional::map(
          fcppt::container::maybe_front(ret),
          [](fcppt::reference<char> const _ref)
          { return _ref.get(); }) == fcppt::optional::make(FCPPT_TEXT('.')))
  {
    ret.erase(ret.begin());
  }

  return ret;
}
