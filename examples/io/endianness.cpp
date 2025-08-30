//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/io/read.hpp>
#include <fcppt/io/write.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/config/external_begin.hpp>
#include <bit>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <sstream>
#include <fcppt/config/external_end.hpp>

int main()
try
{
  //[io_endianness]
  std::stringstream stream{};

  // Write 42u into the stream, using big endianness
  fcppt::io::write(stream, 42U, std::endian::big);

  // Read the written unsigned int back
  fcppt::optional::maybe_void(
      fcppt::io::read<unsigned>(stream, std::endian::big),
      [](unsigned const _result) { std::cout << _result << '\n'; });
  //[io_endianness]
}
catch(std::exception const &_error)
{
  std::cerr << _error.what() << '\n';
  return EXIT_FAILURE;
}
