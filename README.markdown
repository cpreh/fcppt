fcppt
=====

<img src="https://travis-ci.com/freundlich/fcppt.svg?branch=master">

About
-----

Freundlich's C++ Toolkit (fcppt) is a collection of libraries that aim
to improve general C++ code through better typing and functional programming.

License
-------

<a href="https://www.boost.org/users/license.html">Boost Software License</a>

Documentation
-------------

<a href="https://fcppt.org">fcppt.org</a>

Dependencies
------------

### Required
* A C++-17-conforming compiler
* <a href="https://cmake.org/">CMake</a>
* <a href="https://github.com/brunocodutra/metal">Metal</a>

### Optional
* <a href="https://www.boost.org">Boost</a>
* <a href="http://www.doxygen.nl">Doxygen</a>
* <a href="https://github.com/catchorg/Catch2">Catch2</a>

Build
-----

The build uses <a href="https://cmake.org/">CMake</a>.
See our <a href="https://fcppt.org/d3/d36/requirements_download_installation.html#requirements_download_installation_building_and_installation">Build Guide</a>.

Code example
------------
```
void print_at_2(std::vector<int> const &_vec)
{
  fcppt::optional::reference<int const> ref{
    fcppt::container::at_optional(_vec, 2)
  };

  fcppt::optional::maybe(
    ref,
    []{ std::cout << "No value at position 2\n"; },
    [](fcppt::reference<int const> _value) { std::cout << "The value is " << _value.get() << '\n'; }
  );
}
```

Contact
-------

You can contact us via our IRC channel

`#sge-sanguis`

at

`irc.freenode.net`
